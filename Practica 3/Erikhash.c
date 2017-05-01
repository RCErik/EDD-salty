#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<iostream>
#include<fstream>
#include<locale.h>
#include"TADLista.h"

using namespace std;

/*
Estadisticas de la tabla hash, orden maximo de busqueda, tamaño de la tabla, numero de celdas vacias, numero de pasos
al consultar una palabra, modificarla o eliminarla, el numero de colisiones y el resultado de la funcion hash para cada palabra.
*/
int
Estadisticas (lista palabras[83])
{
  return 0;
}

elemento
dividir_cadena (char buffer[1000], elemento copia)
{
  elemento aux;
  copia.pal = strtok (buffer, ":");	//Obtiene el apuntador de la cadena desde que detecta ':'.
  copia.def = strtok (NULL, ":");	//Obiene el apuntador de la cadena de definicion.
  strcpy (aux.d, copia.def);	//Copia la cadena del apuntador de la definicion a un arreglo para las funciones
  strcpy (aux.p, copia.pal);	//Copia la cadena del apuntador de la palabra a un arreglo para las funciones
  return aux;			//Regresa el elemento con la palabra y definicion.
}


int
Clavehash (char aux[50])
{
  int largo = 0;
  int cont = 0;
  float clave = 0;
  largo = strlen (aux);
  clave = (largo + (int) aux[largo - 3]) * (3.1415 + (int) aux[1]);
  clave = (clave + (int) aux[largo]) / 2.7182;
  clave = (int) clave % 83;
  return (int) clave;
}


int
main (void)
{
  int cont = 0;			//Un int para los ciclos.
  int num = 0;			//int auxiliar para varias asignaciones de un uso.
  int largo = 0;		//Longitud de una cadena.
  int clave = 0;		//int para guardar la clave que genere la funcion hash.
  int opcion = 0;		//Un entero que guarda la opción de menú que desea el usuario.
  int pasos = 0;		//int que es usasdo para saber en cuantos pasos encuentra una palabra.
  int sumas=0;
  int elem=0;
  int claves[83];
  char a;			//Char para las funciones que detectan caracteres.
  char buffer[1000];		//Cadena que guarda toda la cadena.
  char auxiliar[50];		//Auxiliar que guarda la cadena de la palabra y despues lo asigna al elemento.p.
  elemento aux;			//Elemento que se usa para meter los datos en la lista.
  elemento aux2;		//Elemento que recibe el elemento de las funciones de la lista.
  elemento copia;		//Elemento que se usa para los apuntadores.
  posicion p;			//Obtiene la posicion de los elementos para las funciones de la lista.
  lista palabras[83];		//La lista de claves, el numero se puede cambiar.
  ifstream Diccionario;		//Hace un archivo de salida.
  string linea;			//Una cadena auxiliar para recibir las lineas de texto con getline


  setlocale (LC_ALL, "es_ES");	//Cambia la localidad total al Español y pueda reconocer acentos y la ñ.

  for (cont = 0; cont < 83; cont++)	//Inicializa la tabla para su trabajo.
    {
      Initialize (&palabras[cont]);
    }

  while (1)
    {
      printf ("Diccionario del conocimiento completo del universo\n\n");
      printf ("1.- Cargar un archivo de definiciones\n");
      printf ("2.- Agregar una palabra y su definicion\n");
      printf ("3.- Buscar una palabra y ver su definicion\n");
      printf ("4.- Modificar una definicion\n");
      printf ("5.- Eliminar una palabra\n");
      printf ("6.- Salir\n\n");
      scanf ("%d", &opcion);
      switch (opcion)
	{
	case 1:
	  system ("clear");
	  printf ("Elija el archivo que desea abrir\n\n");
	  printf ("1.- Glosario BIOQUANTUM\n");
	  printf ("2.- Lunfardo\n");
	  scanf ("%d", &opcion);
	  if (opcion == 1)	//Si el usuario elige BIOQUANTUM
	    {
	      Diccionario.open ("Glosario BIOQUANTUM.txt");	//Abre el diccionario para su uso
	      for (cont = 0; cont < 300; cont++)	// mientras no se terminen de las lineas del archivo sigue leyendo
		{
		  getline (Diccionario, linea);	//toma la linea del archivo de entrada
		  strcpy (buffer, linea.c_str ());	//Copia el string en el arreglo.
		  aux = dividir_cadena (buffer, copia);	//Manda a llamar a la funcion de separar la cadena en palabra y significado.
		  clave = Clavehash (aux.p);	//Manda a ejecutar la funcion hash para generar la clave.
		  Add (&palabras[clave], aux);	//Añade al elemento en la lista con la clave generada por la funcion hash.
		}
	      Diccionario.close ();	//Cierra el diccionario para no causar problemas
	    }

	  if (opcion == 2)	//Si elige Lunfardo
	    {
	      Diccionario.open ("Lunfardo.txt");	//Abre el diccionario para su uso
	      for (cont = 0; cont < 2225; cont++)	// mientras no se terminen de las lineas del archivo sigue leyendo
		{
		  getline (Diccionario, linea);	//toma la linea del archivo de entrada
		  strcpy (buffer, linea.c_str ());	//Copia el string en el arreglo.
		  aux = dividir_cadena (buffer, copia);	//Manda a llamar a la funcion de separar la cadena en palabra y significado.
		  clave = Clavehash (aux.p);	//Manda a ejecutar la funcion hash para generar la clave.
		  Add (&palabras[clave], aux);	//Añade al elemento en la lista con la clave generada por la funcion hash.
		}
	      Diccionario.close ();	//Cierra el diccionario para no causar problemas
	    }

	  break;

	case 2:
	  //Inciso 2 de la practica, agrega una palabra y su definicion.
	  printf
	    ("Escriba la palabra que usted quiere insertar con su significado seprarado por dos puntos:\n");
	  a = getchar ();
	  getline (cin, linea);	//Obtener la cadena de la palabra a buscar
	  strcpy (buffer, linea.c_str());	//Copia la cadena de auxiliar al elemento.      
	  aux = dividir_cadena (buffer, copia);	//Manda a llamar a la funcion de separar la cadena en palabra y significado.
	  clave = Clavehash (aux.p);	//Manda a ejecutar la funcion hash para generar la clave.
	  Add (&palabras[clave], aux);	//Añade al elemento en la lista con la clave generada por la funcion hash.
	  printf ("La palabra fue insertada. \n");

	  break;

	case 3:
	  //Inciso 3 de la practica, busca una palabra y muestra su definicion.
	  a = getchar ();
	  printf ("Escriba la palabra que usted busca:\n");
	  getline (cin, linea);	//Obtener la cadena de la palabra a buscar
	  strcpy (aux.p, linea.c_str());	//Copia la cadena de auxiliar al elemento.      
	  clave = Clavehash (aux.p);	//Manda a ejecutar la funcion hash para generar la clave y buscar la palabra.
	  num = Size (&palabras[clave]);	//Obtiene el tamaño de la lista de va a buscar
	  for (cont = 1; cont <= num; cont++)
	    {
	      aux2 = Element (&palabras[clave], cont);	//Copia al elemento n de la lista
	      largo = strlen (aux2.p);	//Cuenta el largo de la palabra
	      if (strncmp (aux.p, aux2.p, largo) == 0)	//Si la comparacion de las palabras es igual, imprime la definicion de la palabra.
		{
		  printf ("\nLa definicion de %s es: %s\n\n", aux2.p, aux2.d);
		  pasos = cont;	//Numero de pasos que se hizo para encontrar la palabra.
		  cont = 2000;	//Asignacion para salir del ciclo.
		}
	    }
	  if (cont >= num && cont < 2000)
	    printf
	      ("\nLa palabra que usted busca no se encuentra.\nUsted puede agregar la palabra que usted busca o intente en otro lugar.\n");

	  break;

	case 4:
	  //Inciso 4 de la practica, modifica una definicion.
	  a = getchar ();
	  printf
	    ("Escriba la palabra que usted busca cambiar de definicion:\n");
	  getline (cin, linea);	//Obtener la cadena de la palabra a buscar
	  strcpy (aux.p, linea.c_str());	//Copia la cadena de auxiliar al elemento.      
	  clave = Clavehash (aux.p);	//Manda a ejecutar la funcion hash para generar la clave y buscar la palabra.
	  num = Size (&palabras[clave]);	//Obtiene el tamaño de la lista de va a buscar
	  for (cont = 1; cont <= num; cont++)
	    {
	      aux2 = Element (&palabras[clave], cont);	//Copia al elemento n de la lista
	      largo = strlen (aux2.p);	//Cuenta el largo de la palabra
	      if (strncmp (aux.p, aux2.p, largo) == 0)	//Si la comparacion de las palabras es igual, cambia la definicion de la palabra.
		{
		  printf ("\nEscriba la nueva definicion de %s\n", aux.p);
		  fgets (buffer, 1000, stdin);	//Obtiene la cadena de la nueva definicion.
		  strcpy (aux.d, buffer);	//Copia la cadena del apuntador de la palabra a un arreglo para las funciones
		  p = ElementPosition (&palabras[clave], cont);	//Obtiene la posicion del elemento que se busca cambiar
		  Replace (&palabras[clave], p, aux);	//Cambia al elemento con el nuevo significado
		  aux2 = Element (&palabras[clave], cont);	//Lo obtiene de nuevo para comprobar que se cambio la definicion
		  printf
		    ("\nAhora el nuevo significado de la palabra %s es: %s\n",
		     aux2.p, aux2.d);
		  pasos = cont;	//Numero de pasos que dio para modificar la definicion de la palabra.
		  cont = 2000;	//Asignacion para salir del ciclo.
		}
	    }
	  if (cont >= num && cont < 2000)
	    printf
	      ("\nLa palabra que usted busca no se encuentra.\nUsted puede agregar la palabra que usted busca o intente en otro lugar.\n");

	  break;

	case 5:
	  //Inciso 5 de la practica, elimina una palabra.
	  printf ("Escriba la palabra que usted busca eliminar:\n");
	  a = getchar ();
	  getline (cin, linea);	//Obtener la cadena de la palabra a buscar
	  strcpy (aux.p, linea.c_str());	//Copia la cadena de auxiliar al elemento.      
	  clave = Clavehash (aux.p);	//Manda a ejecutar la funcion hash para generar la clave y buscar la palabra.
	  num = Size (&palabras[clave]);	//Obtiene el tamaño de la lista de va a buscar
	  for (cont = 1; cont <= num; cont++)
	    {
	      aux2 = Element (&palabras[clave], cont);	//Copia al elemento n de la lista
	      largo = strlen (aux2.p);	//Cuenta el largo de la palabra
	      if (strncmp (aux.p, aux2.p, largo) == 0)	//Si la comparacion de las palabras es igual, borra la palabra con su definicion.
		{
		  p = ElementPosition (&palabras[clave], cont);	//Obtiene la posicion del elemento a borrar
		  Remove (&palabras[clave], p);	//Borra el elemento
		  printf ("\nLa palabra fue borrada.\n");
		  num = Size (&palabras[clave]);	//Asigna a num el nuevo tamaño de la lista para las estadisticas.
		  pasos = cont;	//Numero de pasos que dio para borrar la palabra.
		  cont = 2000;	//Asignacion para salir del ciclo.
		}
	    }
	  if (cont >= num && cont < 2000)
	    printf
	      ("\nLa palabra que usted busca no se encuentra.\nUsted puede agregar la palabra que usted busca o intente en otro lugar.\n");
	  break;

	case 6:
	  for (cont = 0; cont < 17; cont++)
	    Destroy (&palabras[cont]);
	  return 0;
	  break;
	}
    }
}
