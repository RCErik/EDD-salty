
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
	    printf ("%c %d\t", aux.c, aux.n);
	  }
	else			//Si esta vacia que imprima "vacio".
	  printf ("vacio\t");
      }

      printf ("\n\n\nEl 1 de la fila:\t");	//Ciclo que imprime el primero de la fila que no es atendido.
      for (cont = 0; cont < 10; cont++)
	{
	  if (Size (&cajeros[cont]) >= 2)
	    {
	      aux = Element (&cajeros[cont], 2);
	      printf ("%c %d\t", aux.c, aux.n);
	    }
	  else
	    printf ("vacio\t");
	}

      printf ("\n\nEl 2 de la fila:\t");
      for (cont = 0; cont < 10; cont++)	//Ciclo que imprime el segundo de la fila que no es atendido.
	{
	  if (Size (&cajeros[cont]) >= 3)
	    {
	      aux = Element (&cajeros[cont], 3);
	      printf ("%c %d\t", aux.c aux.n);
	    }
	  else
	    printf ("vacio\t");
	}

      printf ("\n\nEl 3 de la fila:\t");	//Ciclo que imprime el tercero de la fila que no es atendido.
      for (cont = 0; cont < 10; cont++)
	{
	  if (Size (&cajeros[cont]) >= 4)
	    {
	      aux = Element (&cajeros[cont], 4);
	      printf ("%c %d\t",aux.c, aux.n);
	    }
	  else
	    printf ("vacio\t");
	}

      printf ("\n\n\nTamaño de la fila:\t");	//Ciclo que imprime el tamaño de cada caja.
      for (cont = 0; cont < 10; cont++)
	{
	  printf ("%d\t", Size (&cajeros[cont]));
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
  int clientes[3];		//Los clientes de las colas, 0 cliente, 1 usuario, 2 preferente.
  elemento aux;			//Elemento auxiliar para meter elementos a la cola.
  elemento cajero[10];		//arreglo que sirve para la funcion de imprimir banco
  cola filas[3];		//Colas que son las filas de los usuarios, clientes y preferentes.

  srand (time (NULL));		//a lo mejor se quita esta linea

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

  if()		//Si el modulo del tiempo con la llegada del cliente es 0, hace push a la fila 1.
  {
    
  }
  if()		//Si el modulo del tiempo con la llegada del usuario es 0, hace push a la fila 2.
  {
    
  }
  if()		//Si el modulo del tiempo con la llegada del preferente es 0, hace push a la fila 3.
  {
    
  }

 
      Imprimir_banco(registradora, mercado, tiempos, cont, tiempomod, atendidos, aux);	//pendiente
     
  return 0;
}
