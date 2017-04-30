#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<locale.h>
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

Funcion strtok divide la cadena en apuntadores detectando el caracter limite en forma de cadena que le da el usuario, 
se pone la cadena y el limite cuando es de principio a fin:
copia.def = strtok (buffer (cadena), ":"(cadena del caracter limite));
buffer = "HOLA:QUE ONDA"
la funcion guarda HOLA en copia def

si es NULL y el caracter limite es de fin hasta el caracter limite
copia.def=strtok(NULL,":");
la funcion guarda QUE ONDA en copia def

COMPILACION: g++ main.c TADListaDobleLigada.c -o "Nombre del programa" 
*/
void Imprimir_Datos(lista palabras[17])
{
return 0;
}

elemento
dividir_cadena (char buffer[1000], elemento copia)
{
  elemento aux;
  copia.pal = strtok (buffer, ":");     //Obtiene el apuntador de la cadena desde que detecta ':'.
  copia.def = strtok (NULL, ":");       //Obiene el apuntador de la cadena de definicion.
  strcpy (aux.p, copia.pal);    //Copia la cadena del apuntador de la palabra a un arreglo para las funciones
  strcpy (aux.d, copia.def);    //Copia la cadena del apuntador de la definicion a un arreglo para las funciones

  return aux;                   //Regresa el elemento con la palabra y definicion.
}


void hash()
{
return;
}


int
main (void)
{
  int cont = 0;                 //Un int para los ciclos.
  int num = 0;                  //int auxiliar para varias asignaciones de un uso.
  int largo = 0;                //Longitud de una cadena.
  int clave = 0;                //int para guardar la clave que genere la funcion hash.
  int opcion = 0;               //UN entero que guarda la opción de menú que desea el usuario
  char a;                       //Char para las funciones que detectan caracteres.
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
          if (opcion == 1)      //Si el usuario elige BIOQUANTUM
            {
              Diccionario.open ("Glosario BIOQUANTUM.txt");     //Abre el diccionario para su uso
              for (cont = 0; cont < 300; cont++)        // mientras no se terminen de las lineas del archivo sigue leyendo
                {
                  getline (Diccionario, linea); //toma la linea del archivo de entrada
                  cout << linea << endl;        //imprime la linea con cout, la cadena es linea y pasa al siguiente parrafo (\n) con endl
                  strcpy (buffer, linea.c_str ());      //Copia el string en el arreglo.
                  aux = dividir_cadena (buffer, copia); //Manda a llamar a la funcion de separar la cadena en palabra y significado.
                  Add (&palabras[0], aux);      //Añade al elemento en la lista con la clave generada por la funcion hash.
                }
              Diccionario.close ();     //Cierra el diccionario para no causar problemas
            }

          if (opcion == 2)      //Si elige Lunfardo
            {
              Diccionario.open ("Lunfardo.txt");        //Abre el diccionario para su uso
              for (cont = 0; cont < 2225; cont++)       // mientras no se terminen de las lineas del archivo sigue leyendo
                {
                  getline (Diccionario, linea); //toma la linea del archivo de entrada
                  cout << linea << endl;        //imprime la linea con cout, la cadena es linea y pasa al siguiente parrafo (\n) con endl
                  strcpy (buffer, linea.c_str ());      //Copia el string en el arreglo.
                  aux = dividir_cadena (buffer, copia); //Manda a llamar a la funcion de separar la cadena en palabra y significado.
                  Add (&palabras[0], aux);      //Añade al elemento en la lista con la clave generada por la funcion hash.
                  //Cambiar por hash y funcion separar cadena
                }
              Diccionario.close ();     //Cierra el diccionario para no causar problemas
            }
          system ("clear");
          break;

        case 2:
          //Inciso 2 de la practica, agrega una palabra y su definicion.
          printf
            ("Escriba la palabra que usted quiere insertar con su significado seprarado por dos puntos:\n");
          a = getchar ();
          fgets (buffer, 1000, stdin);  //Obtiene toda la cadena para dividirla.
          aux = dividir_cadena (buffer, copia); //Manda a llamar a la funcion de separar la cadena en palabra y significado.
          //Aqui se mandaria a llamar a la funcion de hash y generar la clave para meterlo a la lista
          Add (&palabras[1], aux);      //Añade al elemento en la lista con la clave generada por la funcion hash.
          printf ("La palabra fue insertada. \n");

          //Bloque de instrucciones que obtiene la palabra con su significado y las separa en dos variables.
          break;

        case 3:
          //Inciso 3 de la practica, busca una palabra y muestra su definicion.
          a = getchar ();
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
                  printf ("\nLa definicion de %s es: %s\n\n", aux2.p, aux2.d);
                  cont = 2000;  //Asignacion para salir del ciclo.
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
                  printf ("\nEscriba la nueva definicion de %s\n", aux.p);
                  fgets (buffer, 1000, stdin);
                  strcpy (aux.d, buffer);       //Copia la cadena del apuntador de la palabra a un arreglo para las funciones
                  p = ElementPosition (&palabras[0], cont);     //Obtiene la posicion del elemento que se busca cambiar
                  Replace (&palabras[0], p, aux);       //Cambia al elemento con el nuevo significado
                  aux2 = Element (&palabras[0], cont);  //Lo obtiene de nuevo para comprobar que se cambio la definicion
                  printf
                    ("\nAhora el nuevo significado de la palabra %s es: %s\n",
                     aux2.p, aux2.d);
                  cont = 2000;  //Asignacion para salir del ciclo.
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
                  cont = 2000;  //Asignacion para salir del ciclo.
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
