#include<stdlib.h>
#include<stdio.h>


int
verificar_reinas_diagonales (char *tablero, int referencia, int numero )
{
  int lugar = 0;       //Lugar en el apuntador.
  int salida = 0;      //Entero que termina la funcion en caso de encontrar una reina.
  int columna = 0;     //Entero que guarda la colmuna de la pieza puesta.          
  columna = referencia%numero; //Obtiene la coordenada vertical de la pieza.
  //Primero verificar diagonales superiores.
  //Diagonal superior izquierda.
  lugar = referencia - numero - 1;
  while ((lugar >= 0) && (lugar%numero < columna) && (salida == 0))
  {
    if (*(tablero+lugar) == 'R') 
      salida = 1;
    else
      lugar = lugar - numero - 1;
  }
  //Diagonal superior derecha.
  lugar = referencia - numero + 1;
  while ((lugar >= 0) && (lugar%numero > columna) && (salida == 0))
  {
    if (*(tablero+lugar) == 'R') 
      salida = 1;
    else
      lugar = lugar - numero + 1;
  }
  //Ahora las diagonales inferiores
  //Diagonal inferior izquierda
  lugar = referencia + numero - 1;
  while ((lugar < numero*numero) && (lugar%numero < columna) && (salida == 0))
  {
    if (*(tablero+lugar) == 'R') 
      salida = 1;
    else
      lugar = lugar + numero - 1;
  }
  //Diagonal inferior derecha
  lugar = referencia + numero + 1;
  while ((lugar < numero*numero) && (lugar%numero > columna) && (salida == 0))
  {
    if (*(tablero+lugar) == 'R') 
      salida = 1;
    else
      lugar = lugar + numero + 1;
  }
  /*Si salida es 1, entonces encontro una reina que la esta atacando
  por lo tanto ese lugar no es valido.
  Si es 0, entonces ese lugar es valido y la reina puede ocuparlo.*/  
  return salida;                     
}

int
verificar_reinas_vh (char *tablero, int referencia, int numero )
{
  int lugar = 0;       //Lugar en el apuntador.
  int columna = 0;     //Entero que guarda la colmuna de la pieza puesta.          
  int salida = 0;      //Entero que termina la funcion en caso de encontrar una reina.
  columna = referencia%numero;
  //Primero verificar verticales.
  //Vertical superior.
  lugar = referencia - numero;
  while ((lugar >= 0) && (salida == 0))
  {
    if (*(tablero+lugar) == 'R') 
      salida = 1;
    else
      lugar = lugar - numero;
  }
  //Vertical inferior.
  lugar = referencia + numero;
  while ((lugar < numero*numero) && (salida == 0))
  {
    if (*(tablero+lugar) == 'R') 
      salida = 1;
    else
      lugar = lugar + numero;
  }
  //Ahora las horizontales
  //Horizontal derecha
  lugar = referencia + 1;
  while ((lugar < numero*numero) &&(lugar%numero > columna) && (salida == 0))
  {
    if (*(tablero+lugar) == 'R') 
      salida = 1;
    else
      lugar = lugar + 1;
  }
  //Horizontal izquierda.
  lugar = referencia - 1;
  while ((lugar >= 0) && (lugar%numero < columna) && (salida == 0))
  {
    if (*(tablero+lugar) == 'R') 
      salida = 1;
    else
      lugar = lugar - 1;
  }
  
  /*Si salida es 1, entonces encontro una reina que la esta atacando
  por lo tanto ese lugar no es valido.
  Si es 0, entonces ese lugar es valido y la reina puede ocuparlo.*/
  return salida;                     
}

void
Imprimir (char *tablero, int numero)
{
  int cont = 0;
  system("cls");
  for(cont=0; cont<(numero*numero); cont++)
  {
    printf("%c ", *(tablero + cont));
    if((cont+1)%numero==0)
      printf("\n");
  }         
}

int
validar_lugar (char *tablero, int referencia, int numero)
{
  int salida = 0;
  salida = verificar_reinas_vh (tablero, referencia, numero);
  if(salida == 0)           
    salida = verificar_reinas_diagonales (tablero, referencia, numero);
  return salida;              
}

int
N_reinas (char *tablero, int referencia, int numero)
{
  int validar = 0;       //Entero que sirve como booleano, si es 1 es que la solucion no es valida, si es 0 la solucion es valida.
  while(referencia < numero*numero)
  {
   if(validar_lugar (tablero, referencia, numero) == 0)
   { 
     *(tablero + referencia) = 'R';       //Coloca a la reina en el lugar valido.
     Imprimir (tablero, numero);          //Imprime el tablero.
     if((referencia%numero) + 1 < numero) //Si no llega a la ultima columna, imprime este mensaje.
     {
       printf("Este lugar es valido, coloquemos a la siguiente reina. \n");
       getchar();
     }
     else           //Si encontro la solucion, entonces regresa la TRUE (0) e indica al usuario la solucion.
     {
       printf("Esta es una solucion del tablero %d x %d. \n");
       printf("Gracias por usar nuestro programa\n");
       return 0;
     }
     validar = N_reinas (tablero, (referencia%numero) + 1 , numero);    //Recursividad para explorar más la solucion. 
     if (validar == 1)            //Si saliendo de la funcion la solucion no fue la correcta.
     { 
       Imprimir (tablero, numero);
       *(tablero + referencia) = (char)254;     //Borra la reina anterior. 
       referencia = referencia + numero;        //Y pone a la nueva reina en el siguiente lugar.
       printf("Regresemos una columna para encontrar una solucion.\n");
       getchar();
     }
     else                     //Si la solucion ya fue encontrada, regresa a la anterior
       return 0;             
   }
   else       //Si el lugar no es valido.
   {
     *(tablero + referencia) = 'R';      //Muestra el tablero erroneo al usuario
     Imprimir (tablero, numero);
     printf("Este lugar no es valido, probemos con la siguiente casilla. \n");
     *(tablero + referencia) = (char)254;      //Borra el error y sigue buscando.
     referencia = referencia + numero;
     getchar();
   }
  }
  if (referencia > numero*numero)     //Si no encontro donde poner a la reina, regresa FALSE (1).
    validar = 1;

  return validar;      
}

int
main (void)
{
  int cont = 0;        //Contador de inicializar el tablero.
  int numero = 0;      //Tamaño del tablero.
  int referencia = 0;  //Lugar que sire para verificar las reinas.
  char *tablero = 0;   //El tablero.
  printf ("Bienvenido usuario.\nEste programa le permite encontrar una solución al problema de las reinas que no se atacan.\n");
  printf ("Para introducir el tamaño del tablero basta con solo poner el numero de la longitud. Ejemplo, el tablero de 4x4 solo basta con poner 4\n");
  printf ("¿Cual es el tamaño del tablero que usted desea?\n");
  scanf ("%d", &numero);      //Obtiene el tamaño que quiere el usuario.
  tablero = (char *)malloc(sizeof(char)*(numero*numero));    //Aparta el tamaño del tablero.
  for(cont = 0; cont<(numero*numero); cont++)                //Inicializa el tablero.
    *(tablero + cont) = (char)254; 
  getchar();
  N_reinas(tablero, referencia, numero);                     //Empieza la recursividad.
  free(tablero);                                             //Libera el espacio de memoria usado.
  getchar();
return 0;     
}
