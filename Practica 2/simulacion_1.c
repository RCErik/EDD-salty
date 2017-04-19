/*
	AUTOR: Equipo "Salty boys" (C) Marzo 2017
	VERSIÓN: 1.0
	
	DESCRIPCIÓN: Simulación que representa las cajas registradoras de un super mercado, las cajas
	son entre 1 a 10, la simulacion acaba cuando son atendidos 100 clientes o mas y las cajas estan
	vacias.
	
	OBSERVACIONES: Puede que la simulacion nunca acabe, depende de los paramentros que el usuario asigne. 
  	Funciona con los diferentes TAD Cola.
  
  	COMPILACION: gcc simulacion_1.c TADColaxxxx.o -o "Nombre del ejecutable" 
*/

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include "TADColaDin.h"

void Imprimir_mercado (cola registradora[10], char mercado[100], int tiempos[11], int cont, int tiempomod, int atendidos, elemento aux)
{
      //Bloque que imprime la simulacion.
      system ("clear");		//Borra la pantalla.
      printf ("\t\t\t\t\t\t\t\t%s\n\n\t\t\t", mercado);	//Nombre del mercado

      for (cont = 0; cont < 10; cont++)		//Ciclo que imprime las cajas.
      {
	printf ("Caja %d\t", cont + 1);
      }

      printf ("\n\nEn turno:\t\t");	//Ciclo que imprime el cliente en turno.
      for (cont = 0; cont < 10; cont++)
      {
	if (Size (&registradora[cont]) >= 1)	//Si no esta vacia que imprima el de enfrente.
	  {
	    aux = Front (&registradora[cont]);
	    printf ("%d\t", aux.n);
	  }
	else			//Si esta vacia que imprima "vacio".
	  printf ("vacio\t");
      }

      printf ("\n\n\nEl 1 de la fila:\t");	//Ciclo que imprime el primero de la fila que no es atendido.
      for (cont = 0; cont < 10; cont++)
	{
	  if (Size (&registradora[cont]) >= 2)
	    {
	      aux = Element (&registradora[cont], 2);
	      printf ("%d\t", aux.n);
	    }
	  else
	    printf ("vacio\t");
	}

      printf ("\n\nEl 2 de la fila:\t");
      for (cont = 0; cont < 10; cont++)	//Ciclo que imprime el segundo de la fila que no es atendido.
	{
	  if (Size (&registradora[cont]) >= 3)
	    {
	      aux = Element (&registradora[cont], 3);
	      printf ("%d\t", aux.n);
	    }
	  else
	    printf ("vacio\t");
	}

      printf ("\n\nEl 3 de la fila:\t");	//Ciclo que imprime el tercero de la fila que no es atendido.
      for (cont = 0; cont < 10; cont++)
	{
	  if (Size (&registradora[cont]) >= 4)
	    {
	      aux = Element (&registradora[cont], 4);
	      printf ("%d\t", aux.n);
	    }
	  else
	    printf ("vacio\t");
	}

      printf ("\n\n\nTamaño de la fila:\t");	//Ciclo que imprime el tamaño de cada caja.
      for (cont = 0; cont < 10; cont++)
	{
	  printf ("%d\t", Size (&registradora[cont]));
	}
      printf("\n\n\nTiempo caja atnd:\t");
      for (cont = 0; cont < 10; cont++)
	{
	  printf ("%d\t", tiempos[cont]);
	}
      printf("\nTiempo que llegan las personas: %d", tiempos[10]);
      printf ("\nNumero de clientes atendidos en total:  %d", atendidos);	//Imprime el numero total de clientes atendidos.
      printf ("\nTiempo de la simulacion: %d segundos\n", tiempomod);	//Imprime el tiempo que lleva la simulacion.
}

int
main (void)
{
  int cont = 0;			//Contador para inicializar las cosas.
  int atendidos = 0;		//Contador para los que ya fueron atendidos.
  int tiempomod = 0;		//Tiempo de la simulacion.
  int caja = 0;			//Valor de la caja en los arreglos.
  int tiempos[11];		//Tiempo de cada caja, lugar 0-9 para cajas, lugar 10 para la llegada de las personas.
  int clientes[10];		//Los clientes de las cajas.
  int b = 0;			//Entero auxiliar para el for que verifica las colas vacias.
  int numero = 0;		//Numero de cajas disponibles.
  char mercado[100];		//Nombre del mercado de la simulacion.
  elemento aux;			//Elemento auxiliar para meter elementos a la cola.
  cola registradora[10];	//Colas que son las cajas.

  srand (time (NULL));		//Semilla para el rand que acomoda a los clientes.

  for (cont = 0; cont < 10; cont++)	//Ciclo que inicializa las colas y arreglos.
    {
      Initialize (&registradora[cont]);
      clientes[cont] = 0;
      tiempos[cont] = 0;
    }

  //Instrucciones para obtener la informacion del usuario.
  printf ("El nombre del mercado de la simulacion es:   ");
  fgets (mercado, 100, stdin);	//Obtiene la cadena nombre del mercado.
  printf ("Cuantas cajas atienden:   ");
  scanf ("%d", &numero);	//Obtiene el numero de las cajas que estan abiertas.
  for (cont = 0; cont < numero; cont++)	//Bloque que recibe la informacion del usuario.
    {
      printf ("Asigne el tiempo en que la caja %d atiende:   ", cont + 1);
      scanf ("%d", &tiempos[cont]);	//Obtiene el tiempo en que atienden las cajas.
    }
  printf ("Asigne el tiempo en que los clientes llegan:   ");
  scanf ("%d", &tiempos[10]);	//Obtiene el tiempo en que llegan las personas.


  while ((atendidos < 100) || (b == 1))
    {
      Imprimir_mercado(registradora, mercado, tiempos, cont, tiempomod, atendidos, aux);
      usleep (100000);		//Tiempo de pausa, 100 milisegundos.
      tiempomod++;		//Tiempo de la simulacion

      if ((tiempomod % tiempos[10]) == 0)	//Llegan los clientes
	{
	  caja = rand () % numero;	//Valor al azar para poner al cliente en una caja.
	  clientes[caja] = clientes[caja] + 1;	//Sumar uno al valor de clientes en la cola que se formo.
	  //Potencial crash en estatica, poner un if despues
	  aux.n = clientes[caja];
	  Queue (&registradora[caja], aux);	//Mete al cliente 'n' a la cola.
	}
      Imprimir_mercado(registradora, mercado, tiempos, cont, tiempomod, atendidos, aux);
		
      for (cont = 0; cont < numero; cont++)
	{
	  if (Empty (&registradora[cont]) == FALSE)	//Si la caja no esta vacia:
	    {
	      if (((tiempomod % tiempos[cont]) == 0))	//salen los clientes
		{
		  aux = Dequeue (&registradora[cont]);
		  atendidos++;	//Suma uno al numero total de atendidos.
		}
	    }
	}

      Imprimir_mercado(registradora, mercado, tiempos, cont, tiempomod, atendidos, aux);
      for (cont = 0; cont < numero; cont++)	//ciclo que revisa si las colas estan vacias o no.
	{
	  if (Empty (&registradora[cont]) == TRUE)	//Si es el caso, b=0 para hacer falsa la condicion del while principal.
	    {
	      b = 0;
	    }
	  if (Empty (&registradora[cont]) == FALSE)	//Si tiene elementos aun, b sigue siendo verdadero al while y el contador = 20 para salir del for.
	    {
	      b = 1;
	      cont = 20;
	    }
	}
    }

  return 0;
}
