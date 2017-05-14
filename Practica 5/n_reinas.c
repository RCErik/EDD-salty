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
  lugar = referencia - numero - 1;  //Obtiene el lugar de la esquina superior izquierda a la pieza.
  while ((lugar >= 0) && (lugar%numero < columna) && (salida == 0))
  {
    if (*(tablero+lugar) == 'R') 
      salida = 1;            //Si existe una reina en ese lugar, entonces la verificacion acaba.
    else
      lugar = lugar - numero - 1; //Si no hay nada, vuelve a verificar la esquina superior izquierda.
  }
  //Diagonal superior derecha.
  lugar = referencia - numero + 1;  //Obtiene el lugar de la esquina superior derecha a la pieza.
  while ((lugar >= 0) && (lugar%numero > columna) && (salida == 0))
  {
    if (*(tablero+lugar) == 'R') 
      salida = 1;             //Si existe una reina en ese lugar, entonces la verificacion acaba.
    else
      lugar = lugar - numero + 1;  //Si no hay nada, vuelve a verificar la esquina superior derecha.
  }
  //Ahora las diagonales inferiores
  //Diagonal inferior izquierda
  lugar = referencia + numero - 1;  //Obtiene el lugar de la esquina inferior izquierda a la pieza.
  while ((lugar < numero*numero) && (lugar%numero < columna) && (salida == 0))
  {
    if (*(tablero+lugar) == 'R') 
      salida = 1;             //Si existe una reina en ese lugar, entonces la verificacion acaba.
    else
      lugar = lugar + numero - 1; //Si no hay nada, vuelve a verificar la esquina inferior izquierda.
  }
  //Diagonal inferior derecha
  lugar = referencia + numero + 1;  //Obtiene el lugar de la esquina inferior derecha a la pieza.
  while ((lugar < numero*numero) && (lugar%numero > columna) && (salida == 0))
  {
    if (*(tablero+lugar) == 'R') 
      salida = 1;             //Si existe una reina en ese lugar, entonces la verificacion acaba.
    else
      lugar = lugar + numero + 1; //Si no hay nada, vuelve a verificar la esquina inferior derecha.
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
  lugar = referencia - numero;  //Obtiene el lugar superior a la pieza.
  while ((lugar >= 0) && (salida == 0))
  {
    if (*(tablero+lugar) == 'R') 
      salida = 1;             //Si existe una reina en ese lugar, entonces la verificacion acaba.
    else
      lugar = lugar - numero; //Si no hay nada, vuelve a verificar el lugar superior.
  }
  //Vertical inferior.
  lugar = referencia + numero;  //Obtiene el lugar inferior a la pieza.
  while ((lugar < numero*numero) && (salida == 0))
  {
    if (*(tablero+lugar) == 'R') 
      salida = 1;             //Si existe una reina en ese lugar, entonces la verificacion acaba.
    else
      lugar = lugar + numero; //Si no hay nada, vuelve a verificar el lugar inferior.
  }
  //Ahora las horizontales
  //Horizontal derecha
  lugar = referencia + 1; //Obtiene el lugar horizontal derecha a la pieza.
  while ((lugar < numero*numero) &&(lugar%numero > columna) && (salida == 0))
  {
    if (*(tablero+lugar) == 'R') 
      salida = 1;             //Si existe una reina en ese lugar, entonces la verificacion acaba.
    else
      lugar = lugar + 1;  //Si no hay nada, vuelve a verificar el lugar horizontal derecha.
  }
  //Horizontal izquierda.
  lugar = referencia - 1; //Obtiene el lugar horizontal izquierda a la pieza.
  while ((lugar >= 0) && (lugar%numero < columna) && (salida == 0))
  {
    if (*(tablero+lugar) == 'R') 
      salida = 1;             //Si existe una reina en ese lugar, entonces la verificacion acaba.
    else
      lugar = lugar - 1;  //Si no hay nada, vuelve a verificar el lugar horizontal izquierda.
  }
  
  /*Si salida es 1, entonces encontro una reina que la esta atacando
  por lo tanto ese lugar no es valido.
  Si es 0, entonces ese lugar es valido y la reina puede ocuparlo.*/
  return salida;                     
}

void
Imprimir (char *tablero, int numero)
{
  int cont = 0;   //Entero para el ciclo for de impresion.
  system("cls");  //Borra la pantalla.
  for(cont=0; cont<(numero*numero); cont++)   //Imprime el tablero.
  {
    printf("%c ", *(tablero + cont));
    if((cont+1)%numero==0)
      printf("\n");
  }
  return;
}

int
validar_lugar (char *tablero, int referencia, int numero)
{
  int salida = 0; //Entero que detecta cuando se encontro una reina.
  salida = verificar_reinas_vh (tablero, referencia, numero); //Primero verifica la horizontal y vertical de la pieza.
  if(salida == 0)            //Si es 0 significa que no ha encontrado una reina, ahora se verifican las diagonales.
    salida = verificar_reinas_diagonales (tablero, referencia, numero);
  return salida;      //Si salida es 1 encontro una reina, si es 0 el lugar es valido.        
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
     referencia = referencia + numero;     //Cambia el lugar de la pieza a la siguiente casilla.
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
