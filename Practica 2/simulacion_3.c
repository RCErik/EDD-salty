
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include "TADColaDin.h"

void Imprimir_banco (cola cajeros[10], int tiempos[4], int cont, int tiempomod, int atendidos, elemento aux)
{
      //Bloque que imprime la simulacion.
      system ("clear");		//Borra la pantalla.
      printf ("\t\t\t\t\t\t\t\tBanco Nacional Mexicano\n\n\t\t\t");	//Nombre del banco

      for (cont = 0; cont < 10; cont++)		//Ciclo que imprime las cajas.
      {
	printf ("Cajero %d\t", cont + 1);
      }

      printf ("\n\nEn turno:\t\t");	//Ciclo que imprime el cliente en turno.
      for (cont = 0; cont < 10; cont++)
      {
	if (Size (&cajeros[cont]) >= 1)	//Si no esta vacia que imprima el de enfrente.
	  {
	    aux = Front (&cajeros[cont]);
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
  int tiempos[4];		//Tiempo de cada caja, 0 el tiempo de atencion de las cajas, 1-3 tiempo que llega la gente.
  int clientes[10];		//Los clientes de las cajas.
  int b = 0;			//Entero auxiliar para el for que verifica las colas vacias.
  int numero = 0;		//Numero de cajas disponibles.
  elemento aux;			//Elemento auxiliar para meter elementos a la cola.
  cola cajeros[10];	//Colas que son las cajas.

  srand (time (NULL));		//Semilla para el rand que acomoda a los clientes.

  for (cont = 0; cont < 10; cont++)	//Ciclo que inicializa las colas y arreglos.
    {
      Initialize (&cajeros[cont]);
      clientes[cont] = 0;
      tiempos[cont] = 0;
    }

  //Instrucciones para obtener la informacion del usuario.
  printf ("Cuantas cajeros atienden:   ");
  scanf ("%d", &numero);	//Obtiene el numero de las cajas que estan abiertas.
  printf ("Asigne el tiempo en que los cajeros atienden:   ");
  scanf ("%d", &tiempos[0]);	//Obtiene el tiempo en que atienden las cajas.
  printf ("Asigne el tiempo en que los clientes llegan:   ");
  scanf ("%d", &tiempos[1]);	//Obtiene el tiempo en que llegan los clientes.
  printf ("Asigne el tiempo en que los usuarios llegan:   ");
  scanf ("%d", &tiempos[2]);	//Obtiene el tiempo en que llegan los usuarios.
  printf ("Asigne el tiempo en que los clientes preferentes llegan:   ");
  scanf ("%d", &tiempos[3]);	//Obtiene el tiempo en que llegan los clientes preferentes.



 
      Imprimir_banco(registradora, mercado, tiempos, cont, tiempomod, atendidos, aux);
     
  return 0;
}
