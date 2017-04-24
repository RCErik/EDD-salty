#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>


using namespace std;

void menuArchivos(){
	int opcion = 0;
	ifstream Diccionario;
	printf("Elija el archivo que desea abrir\n\n");
	printf("1.- Lunfardo\n");
	printf("2.- Glosario BIOQUANTUM\n");
	scanf("%d", &opcion);
	switch(opcion){
		case 1:
			//Si el usuario elige BIOQUANTUM
			Diccionario.open ("Glosario BIOQUANTUM.txt"); //Abre el diccionario para su uso
			while (!Diccionario.eof ())   // mientras no se terminen de las lineas del archivo sigue leyendo
			{
			   getline (Diccionario, linea);     //toma la linea del archivo de entrada
			   strcpy (buffer, linea.c_str ());          //Copia el string en el arreglo.
			   aux = dividir_cadena (buffer, copia);     //Manda a llamar a la funcion de separar la cadena en palabra y significado.
			   Add (&palabras[0], aux);  //Añade al elemento en la lista con la clave generada por la funcion hash.
			}
			Diccionario.close ();         //Cierra el diccionario para no causar problemas
			break;
		case 2:
			 //Si elige Lunfardo
			 Diccionario.open ("Lunfardo.txt");    //Abre el diccionario para su uso
  			 while (!Diccionario.eof ())   // mientras no se terminen de las lineas del archivo sigue leyendo
  			 {
      			    getline (Diccionario, linea);     //toma la linea del archivo de entrada
     			    cout << linea << endl;    //imprime la linea con cout, la cadena es linea y pasa al siguiente parrafo (\n) con endl
     			    //Cambiar por hash y funcion separar cadena
    			 }
 			 Diccionario.close ();         //Cierra el diccionario para no causar problemas
			break;
	return;
}


elemento
dividir_cadena (char buffer[1000], elemento copia)
{
  elemento aux;
  copia.pal = strtok (buffer, ":");     //Obtiene el apuntador de la cadena desde que detecta ':'.
  copia.def = strtok (NULL, ":");       //Obiene el apuntador de la cadena de definicion.
  strcpy(aux.p, copia.pal);             //Copia la cadena del apuntador de la palabra a un arreglo para las funciones
  strcpy(aux.d, copia.def);             //Copia la cadena del apuntador de la definicion a un arreglo para las funciones

  return aux;                           //Regresa el elemento con la palabra y definicion.
}


int hashCharly(char palabra[50]){
	int caracteres = 0, random;
	int suma = 0, i, resta, mult, clave, aux, potencia, tam = 100;
	caracteres = strlen(palabra);
	resta = (int)palabra[0] - (int)palabra[caracteres - 1];
	if(resta < 0)
		resta = resta * -1;
	mult = resta * caracteres;
	for(i = 0; i < caracteres; i++)
		suma = suma + (int)palabra[i];
	random = rand() % 40;
	aux = ((suma * mult) / resta) / (rand() % suma);
	random = rand() % 5;
	potencia = pow(aux, random);
	clave = potencia % tam;
	printf("clave %d \n", clave);
	return clave;	
}

int main(void){
	int cont = 0;                 //Un int para los ciclos.
	int num = 0;                  //int auxiliar para varias asignaciones de un uso.
	int largo = 0;                //Longitud de una cadena.
	int clave = 0;                //int para guardar la clave que genere la funcion hash.
	int opcion = 0;		      //UN entero que guarda la opción de menú que desea el usuario
	char a = ':';                 //Char para las funciones que detectan caracteres.
	char buffer[1000];            //Cadena que guarda toda la cadena.
	char auxiliar[50];            //Auxiliar que guarda la cadena de la palabra y despues lo asigna al elemento.p.
	elemento aux;                 //Elemento que se usa para meter los datos en la lista.
	elemento aux2;                //Elemento que recibe el elemento de las funciones de la lista.
	elemento copia;               //Elemento que se usa para los apuntadores.
	posicion p;                   //Obtiene la posicion de los elementos para las funciones de la lista.
	lista palabras[17];           //La lista de claves, el numero se puede cambiar.
	ifstream Diccionario;         //Hace un archivo de salida.
	string linea;                 //Una cadena auxiliar para recibir las lineas de texto con getline
	

	setlocale (LC_ALL, "es_ES");  //Cambia la localidad total al Español y pueda reconocer acentos y la ñ.

	for (cont = 0; cont < 17; cont++)     //Inicializa la tabla para su trabajo.
	{
	    Initialize (&palabras[cont]);
	}
	
	printf("Diccionario del conocimiento completo del universo\n\n");
	printf("1.- Cargar un archivo de definiciones\n");
	printf("2.- Agregar una palabra y su definicion\n");
	printf("3.- Buscar una palabra y ver su definicion\n");
	printf("4.- Modificar una definicion\n");
	printf("5.- Eliminar una palabra\n");
	printf("6.- Salir\n\n");
	scanf("%d", &opcion);
	switch(opcion){
		case 1:
			menuArchivos();
			break;
		case 2:
			//Inciso 2 de la practica, agrega una palabra y su definicion.
			  printf
			    ("Escriba la palabra que usted quiere insertar con su significado seprarado por dos puntos:\n");
			  fgets (buffer, 1000, stdin);  //Obtiene toda la cadena para dividirla.
			  aux = dividir_cadena (buffer, copia); //Manda a llamar a la funcion de separar la cadena en palabra y significado.
			//Aqui se mandaria a llamar a la funcion de hash y generar la clave para meterlo a la lista
			  Add (&palabras[1], aux);      //Añade al elemento en la lista con la clave generada por la funcion hash.
			  printf ("La palabra fue insertada. \n");

			//Bloque de instrucciones que obtiene la palabra con su significado y las separa en dos variables.
			break;
		case 3:
			//Inciso 3 de la practica, busca una palabra y muestra su definicion.
			  printf ("Escriba la palabra que usted busca:\n");
			  fgets (auxiliar, 50, stdin);  //Obtener la cadena de la palabra a buscar
			  strcpy (aux.p, auxiliar);     //Copia la cadena de auxiliar al elemento.      
			//Hacer pasar por hash a la palabra a buscar.
			  num = Size (&palabras[0]);    //Obtiene el tamaño de la lista de va a buscar
			  for (cont = 1; cont <= num; cont++)
			    {
			      aux2 = Element (&palabras[0], cont);      //Copia al elemento n de la lista
			      largo = strlen (aux2.p);  //Cuenta el largo de la palabra
			      if (strncmp (aux.p, aux2.p, largo) == 0)  //Si la comparacion de las palabras es igual, imprime la definicion de la palabra.
				{
				  printf ("\nLa definicion de %s es: %s\n", aux2.p, aux2.d);
				  cont = 2000;          //Asignacion para salir del ciclo.
				}
			    }
			  if (cont >= num && cont < 2000)
			    printf
			      ("\nLa palabra que usted busca no se encuentra.\nUsted puede agregar la palabra que usted busca o intente en otro lugar.\n");

			break;
		case 4:
			//Inciso 4 de la practica, modifica una definicion.
			  printf ("Escriba la palabra que usted busca cambiar de definicion:\n");
			  fgets (auxiliar, 50, stdin);  //Obtener la cadena de la palabra a buscar
			  strcpy (aux.p, auxiliar);     //Copia la cadena de auxiliar al elemento.      
			//Hacer pasar por hash a la palabra a buscar.
			  num = Size (&palabras[0]);    //Obtiene el tamaño de la lista de va a buscar
			  for (cont = 1; cont <= num; cont++)
			    {
			      aux2 = Element (&palabras[0], cont);      //Copia al elemento n de la lista
			      largo = strlen (aux2.p);  //Cuenta el largo de la palabra
			      if (strncmp (aux.p, aux2.p, largo) == 0)  //Si la comparacion de las palabras es igual, cambia la definicion de la palabra.
				{
				  printf
				    ("\nEscriba la nueva definicion de %s\n",
				     aux.p);
				  fgets (buffer, 1000, stdin);
				  strcpy(aux.d, buffer);                //Copia la cadena del apuntador de la palabra a un arreglo para las funciones
				  p = ElementPosition (&palabras[0], cont);     //Obtiene la posicion del elemento que se busca cambiar
				  Replace (&palabras[0], p, aux);       //Cambia al elemento con el nuevo significado
				  aux2 = Element (&palabras[0], cont);  //Lo obtiene de nuevo para comprobar que se cambio la definicion
				  printf ("\nAhora el nuevo significado de la palabra %s es: %s\n",
					  aux2.p, aux2.d);
				  cont = 2000;          //Asignacion para salir del ciclo.
				}
			    }
			  if (cont >= num && cont < 2000)
			    printf
			      ("\nLa palabra que usted busca no se encuentra.\nUsted puede agregar la palabra que usted busca o intente en otro lugar.\n");

			break;
		case 5:
			//Inciso 5 de la practica, elimina una palabra.
			  printf ("Escriba la palabra que usted busca eliminar:\n");
			  fgets (auxiliar, 50, stdin);  //Obtener la cadena de la palabra a buscar
			  strcpy (aux.p, auxiliar);     //Copia la cadena de auxiliar al elemento.      
			//Hacer pasar por hash a la palabra a buscar.
			  num = Size (&palabras[0]);    //Obtiene el tamaño de la lista de va a buscar
			  for (cont = 1; cont <= num; cont++)
			    {
			      aux2 = Element (&palabras[0], cont);      //Copia al elemento n de la lista
			      largo = strlen (aux2.p);  //Cuenta el largo de la palabra
			      if (strncmp (aux.p, aux2.p, largo) == 0)  //Si la comparacion de las palabras es igual, borra la palabra con su definicion.
				{
				  p = ElementPosition (&palabras[0], cont);     //Obtiene la posicion del elemento a borrar
				  Remove (&palabras[0], p);     //Borra el elemento
				  printf ("\nLa palabra fue borrada.\n");
				  num = Size (&palabras[0]);
				  cont = 2000;          //Asignacion para salir del ciclo.
				}
			    }
			  if (cont >= num && cont < 2000)
			    printf
			      ("\nLa palabra que usted busca no se encuentra.\nUsted puede agregar la palabra que usted busca o intente en otro lugar.\n");

						break;
		case 6:
			for(cont=0;cont<17;cont++)
  			Destroy(&palabras[cont]);
			exit(0);
			break;
	}
}

