
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include "TADColaDin.h"

void Imprimir_banco (cola cajeros[10], int tiempos[4], int cont, int tiempomod, int atendidos, elemento aux)//pendiente
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
  int ClyPr = 0;		//Contador que de clientes y preferentes que no debe pasar el numero 5.
  int tiempomod = 0;		//Tiempo de la simulacion.
  int caja = 0;			//Valor de la caja en los arreglos.
  int numero = 0;		//Numero de cajeros disponibles que selecciono el usuario para la simulacion.
  int tiempos[4];		//Tiempo de cada caja, 0 el tiempo de atencion de las cajas, 1-3 tiempo que llega la gente.
  int personas[3];		//Las personas de las colas, 0 cliente, 1 usuario, 2 preferente.
  elemento aux;			//Elemento auxiliar para meter elementos a la cola.
  elemento cajero[10];		//por si acaso se necesita
  cola cajero[10];		//Colas que son los cajeros donde son atendidos las personas.
  cola filas[3];		//Colas que son las filas de los usuarios, clientes y preferentes.

  srand (time (NULL));		//a lo mejor se quita esta linea

  for (cont = 0; cont < 3; cont++)	//Ciclo que inicializa las colas de personas y arreglos de tiempo.
    {
      Initialize (&fila[cont]);
      personas[cont] = 0;
      tiempos[cont] = 0;
    }
  tiempos[3] = 0;
  for (cont = 0; cont < 10; cont++)	//Ciclo que inicializa los cajeros.
      Initialize (&cajero[cont]);  

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
  
  while(1)
  {
      usleep (100000);		//Tiempo de pausa.
      tiempomod++;		//Tiempo de la simulacion
	  
      if((tiempomod % tiempo[1]) == 0)		//Si el modulo del tiempo con la llegada del cliente es 0, hace push a la fila 1.
      {
	  personas[0] = personas[0] + 1;	//Sumar uno al valor de clientes en la cola que se formo.
	  //Potencial crash en estatica, poner un if despues si queremos
	  aux.n = clientes[0];
	  aux.c = 'C';    
	  Queue (&fila[0], aux);	//Mete al cliente 'n' a la cola.
      }
	  
      if((tiempomod % tiempo[2]) == 0)		//Si el modulo del tiempo con la llegada del usuario es 0, hace push a la fila 2.
      {
          personas[1] = personas[1] + 1;	//Sumar uno al valor de usuarios en la cola que se formo.
	  //Potencial crash en estatica, poner un if despues si queremos
	  aux.n = clientes[1];
	  aux.c = 'U';    
	  Queue (&fila[1], aux);	//Mete al usuario 'n' a la cola.
      }
	  
      if((tiempomod % tiempo[3]) == 0)		//Si el modulo del tiempo con la llegada del preferente es 0, hace push a la fila 3.
      {
          personas[2] = personas[2] + 1;	//Sumar uno al valor de preferentes en la cola que se formo.
	  //Potencial crash en estatica, poner un if despues si queremos
	  aux.n = clientes[2];
	  aux.c = 'P';    
	  Queue (&fila[2], aux);	//Mete al cliente preferente 'n' a la cola.
      }
     
      if((tiempomod % tiempos[0]) == 0) //Modulo del tiempo con el que son atendidos es 0 hace push de los cajeros.
      {
	  for(cont = 0; cont < numero; cont++)	//Primero saca a los que fueron atendidos
	  {
	      if(Empty(&cajero[cont]) == FALSE)	//Verifica si no esta vacia la fila y evitar matar el programa.
	      {
		  Pop(&cajero[cont]);    //Lo saca de la cajero en el que estaba.
	      }       
	  }
	  cont = 0;	//Contador a 0 para verificar que en el while no exceda los cajeros disponibles
	  
	  while( (Empty(&fila[2]) == FALSE) && (ClyPr <= 4) && (cont<=(numero-1)) )
	  /*menor a 4 para que el 5 sea el cliente y el 6 el usuario, el cont<=(numero-1) es para que por lo menos deje una caja 
	  para los clientes y si es solo una caja, solo atienda a los importantes
	  y el quinto sea el cliente y el sexto el usuario y no romper el sistema de atendido*/
	  {//while para hacer Pop de los preferentes ya que son la maxima prioridad pero tambien los demas deben ser atendidos.
	      aux = Pop (&fila[2]);
	      for(cont = 0; cont < numero; cont++)//Verifica que cajeros estan vacios para atender al preferente.
	      {
		  if(Empty(&cajero[cont]) == TRUE)		//Si lo esta, lo acomodan en ese cajero y sale del for
		  {
		      Push(&cajero, aux);
		      cont = 20;
		  }
		  else		//Si tiene a alguien en ese cajero pasa al siguente.
		      cont++;
	      }
	      ClyPr++;  //Suma uno a los clientes/preferentes.
	  }
	      //Falta las condiciones para los clientes normales y usuarios
      }
 
      Imprimir_banco(registradora, mercado, tiempos, cont, tiempomod, atendidos, aux);	//pendiente
  }   
  return 0;
}
