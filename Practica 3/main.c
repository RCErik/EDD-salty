#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include"TADLista.h"
/*
Nota: aux.d tiene que ser apuntador por la funcion strchr que devuelve el apuntador de la cadena a partir del caracter a localizar.
Ejemplo:
cadena1 = Hola: saludo.
El caracter a locarlizar es ':' y la funcion devuleve un apuntador desde donde localiza ese caracter, entonces
aqui seria:

*d = strchr(cadena1,:)	
devuelve *d = ": saludo."

Y strncpy copia la cadena desde el principio hasta el numero de caracteres que le das.
Ejemplo con la misma cadena anterior:

strncpy(cadena2, cadena1, 4)
devuelve cadena2 = "hola"		

*/

elemento
dividir_cadena (char buffer[300], char auxiliar[50], char a)
{
  int numero = 0;
  elemento aux;
  aux.d = strchr (buffer, a);	//Obtiene la cadena desde que detecta ':'.
  numero = aux.d - buffer;	//Obtiene el numero de donde esta ':' y usar ese numero.
  strncpy (auxiliar, buffer, numero);	//Copia la cadena desde el inicio hasta el numero de caracteres dado por numero.
  auxiliar[numero + 1] = '\0';	//Pone el final de cadena a la cadena auxiliar.
  strcpy (aux.p, auxiliar);	//Copia la cadena al elemento.

  return aux;
}


int
main (void)
{
  int cont = 0;			//Un int para los ciclos.
  int num = 0;			//int auxiliar para varias asignaciones de un uso.
  int largo = 0;		//Longitud de una cadena.
  int clave = 0;		//int para guardar la clave que genere la funcion hash.
  char a = ':';			//Char para las funciones que detectan caracteres.
  char buffer[300];		//Cadena que guarda toda la cadena.
  char auxiliar[50];		//Auxiliar que guarda la cadena de la palabra y despues lo asigna al elemento.p.
  elemento aux;			//Elemento que se usa para meter los datos en la lista.
  elemento aux2;		//Elemento que recibe el elemento de las funciones de la lista.
  posicion p;			//Obtiene la posicion de los elementos para las funciones de la lista.
  lista palabras[17];		//La lista de claves, el numero se puede cambiar.

  for (cont = 0; cont < 17; cont++)	//Inicializa la tabla para su trabajo.
    Initialize (&palabras[cont]);

//Inciso 1 de la practica, carga un archivo de definiciones.

//Inciso 2 de la practica, agrega una palabra y su definicion.
//Bloque de instrucciones que obtiene la palabra con su significado y las separa en dos variables.
  printf ("Escriba la palabra que usted quiere insertar:\n");
  fgets (buffer, 300, stdin);	//Obtiene toda la cadena para dividirla.
  aux = dividir_cadena (buffer, auxiliar, a);	//Manda a llamar a la funcion de separar la cadena en palabra y significado.
//Aqui se mandaria a llamar a la funcion de hash y generar la clave para meterlo a la lista
  Add (&palabras[0], aux);	//Añade al elemento en la lista con la clave generada por la funcion hash.
  printf ("La palabra fue insertada.\n");

//Inciso 3 de la practica, busca una palabra y muestra su definicion.
  printf ("Escriba la palabra que usted busca:\n");
  fgets (auxiliar, 50, stdin);	//Obtener la cadena de la palabra a buscar
  strcpy (aux.p, auxiliar);	//Copia la cadena de auxiliar al elemento.      
//Hacer pasar por hash a la palabra a buscar.
  num = Size (&palabras[0]);	//Obtiene el tamaño de la lista de va a buscar
  for (cont = 1; cont <= num; cont++)
    {
      aux2 = Element (&palabras[0], cont);	//Copia al elemento n de la lista
      largo = strlen (aux2.p);	//Cuenta el largo de la palabra
      if (strncmp (aux.p, aux2.p, largo) == 0)	//Si la comparacion de las palabras es igual, imprime la definicion de la palabra.
	{
	  printf ("\nLa definicion de %s es%s", aux2.p, aux2.d);
	  cont = 2000;		//Asignacion para salir del ciclo.
	}
      else			//Si no es la palabra, suma cont uno para seguir buscando
	cont++;
    }
  if (cont >= num && cont < 2000)
    printf
      ("\nLa palabra que usted busca no se encuentra.\nUsted puede agregar la palabra que usted busca o intente en otro lugar.\n");

//Inciso 4 de la practica, modifica una definicion.
  printf ("Escriba la palabra que usted busca cambiar de definicion:\n");
  fgets (auxiliar, 50, stdin);	//Obtener la cadena de la palabra a buscar
  strcpy (aux.p, auxiliar);	//Copia la cadena de auxiliar al elemento.      
//Hacer pasar por hash a la palabra a buscar.
  num = Size (&palabras[0]);	//Obtiene el tamaño de la lista de va a buscar
  for (cont = 1; cont <= num; cont++)
    {
      aux2 = Element (&palabras[0], cont);	//Copia al elemento n de la lista
      largo = strlen (aux2.p);	//Cuenta el largo de la palabra
      if (strncmp (aux.p, aux2.p, largo) == 0)	//Si la comparacion de las palabras es igual, cambia la definicion de la palabra.
	{
	  printf
	    ("\nEscriba la nueva definicion de %s empezando con el signo de dos puntos.\n",
	     aux.p);
	  fgets (buffer, 300, stdin);
	  aux.d = strchr (buffer, ':');	//Obtiene la cadena desde que detecta ':'.
	  p = ElementPosition (&palabras[0], cont);	//Obtiene la posicion del elemento que se busca cambiar
	  Replace (&palabras[0], p, aux);	//Cambia al elemento con el nuevo significado
	  aux2 = Element (&palabras[0], cont);	//Lo obtiene de nuevo para comprobar que se cambio la definicion
	  printf ("\nAhora el nuevo significado de la palabra %s es%s\n",
		  aux2.p, aux2.d);
	  cont = 2000;		//Asignacion para salir del ciclo.
	}
      else			//Si no es la palabra, suma cont uno para seguir buscando
	cont++;
    }
  if (cont >= num && cont < 2000)
    printf
      ("\nLa palabra que usted busca no se encuentra.\nUsted puede agregar la palabra que usted busca o intente en otro lugar.");


//Inciso 5 de la practica, elimina una palabra.
  printf ("Escriba la palabra que usted busca eliminar:\n");
  fgets (auxiliar, 50, stdin);	//Obtener la cadena de la palabra a buscar
  strcpy (aux.p, auxiliar);	//Copia la cadena de auxiliar al elemento.      
//Hacer pasar por hash a la palabra a buscar.
  num = Size (&palabras[0]);	//Obtiene el tamaño de la lista de va a buscar
  for (cont = 1; cont <= num; cont++)
    {
      aux2 = Element (&palabras[0], cont);	//Copia al elemento n de la lista
      largo = strlen (aux2.p);	//Cuenta el largo de la palabra
      if (strncmp (aux.p, aux2.p, largo) == 0)	//Si la comparacion de las palabras es igual, borra la palabra con su definicion.
	{
	  p = ElementPosition (&palabras[0], cont);	//Obtiene la posicion del elemento a borrar
	  Remove (&palabras[0], p);	//Borra el elemento
	  printf ("\nLa palabra fue borrada.\n");
	  largo = Size (&palabras[0]);
	  cont = 2000;		//Asignacion para salir del ciclo.
	}
      else			//Si no es la palabra, suma cont uno para seguir buscando
	cont++;
    }
  if (cont >= num && cont < 2000)
    printf
      ("\nLa palabra que usted busca no se encuentra.\nUsted puede agregar la palabra que usted busca o intente en otro lugar.\n");

//Inciso 6 de la practica, sale del programa.

  return 0;
}
