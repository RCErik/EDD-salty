#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include "TADColaDin.h"

void
Imprimir_banco (cola cajero[10], cola filas[3], int tiempos[4], int cont,
                int tiempomod, int atendidos, int ClyPr, elemento aux)
{
  //Bloque que imprime la simulacion.
  system ("clear");             //Borra la pantalla.
  printf ("\t\t\t\t\t\t\tBanco Nacional Mexicano\n\n\t\t\t\t\t");       //Nombre del banco

  for (cont = 0; cont < 10; cont++)     //Ciclo que imprime los cajeros.
    {
      printf ("Caja %d\t", cont + 1);
    }

  printf ("\n\nEn turno:\t\t\t\t");     //Ciclo que imprime a la persona que esta siendo atendido.
  for (cont = 0; cont < 10; cont++)
    {
      if (Size (&cajero[cont]) >= 1)    //Si no esta vacia la caja, imprime al atendido.
        {
          aux = Front (&cajero[cont]);
          printf ("%c %d\t", aux.c, aux.n);
        }
      else                      //Si esta vacia que imprima "vacio".
        printf ("vacio\t");
    }

  printf ("\n\n\n\n\t\t\t\t\t\tClientes\t\tUsuarios\t\tPreferentes");   //Encabezado de las filas
  printf ("\nEl primero de la fila:\t\t\t\t");  //Ciclo que imprime el primero de la fila que no es atendido.
  for (cont = 0; cont < 3; cont++)
    {
      if (Size (&filas[cont]) >= 1)
        {
          aux = Front (&filas[cont]);
          printf ("%c %d\t\t\t", aux.c, aux.n);
        }
      else
        printf ("vacio\t\t\t");
    }

  printf ("\n\nEl segundo de la fila:\t\t\t\t");
  for (cont = 0; cont < 3; cont++)      //Ciclo que imprime el segundo de la fila que no es atendido.
    {
      if (Size (&filas[cont]) >= 2)
        {
          aux = Element (&filas[cont], 2);
          printf ("%c %d\t\t\t", aux.c, aux.n);
        }
      else
        printf ("vacio\t\t\t");
    }

  printf ("\n\nEl tercero de la fila:\t\t\t\t");        //Ciclo que imprime el tercero de la fila que no es atendido.
  for (cont = 0; cont < 3; cont++)
    {
      if (Size (&filas[cont]) >= 3)
        {
          aux = Element (&filas[cont], 3);
          printf ("%c %d\t\t\t", aux.c, aux.n);
        }
      else
        printf ("vacio\t\t\t");
    }

  printf ("\n\nEl cuarto de la fila:\t\t\t\t"); //Ciclo que imprime el tercero de la fila que no es atendido.
  for (cont = 0; cont < 3; cont++)
    {
      if (Size (&filas[cont]) >= 4)
        {
          aux = Element (&filas[cont], 4);
          printf ("%c %d\t\t\t", aux.c, aux.n);
        }
      else
        printf ("vacio\t\t\t");
    }

  printf ("\n\nEl quinto de la fila:\t\t\t\t"); //Ciclo que imprime el tercero de la fila que no es atendido.
  for (cont = 0; cont < 3; cont++)
    {
      if (Size (&filas[cont]) >= 5)
        {
          aux = Element (&filas[cont], 5);
          printf ("%c %d\t\t\t", aux.c, aux.n);
        }
      else
        printf ("vacio\t\t\t");
    }

  printf ("\n\n\nTamaño de la fila:\t\t\t\t");  //Ciclo que imprime el tamaño de cada fila.
  for (cont = 0; cont < 3; cont++)
    {
      printf ("%d\t\t\t", Size (&filas[cont]));
    }

  printf ("\n\nTiempo en el que llegan:\t\t\t");        //Imprime los tiempos de llegada de las personas.
  for (cont = 1; cont < 4; cont++)
    {
      printf ("%d\t\t\t", tiempos[cont]);
    }

  printf ("\n\n\nTiempo que atienden los cajeros: %d", tiempos[0]);
  printf ("\nNumero de clientes atendidos en total:  %d", atendidos);   //Imprime el numero total de clientes atendidos.
  printf ("\nTiempo de la simulacion: %d segundos\n", tiempomod);       //Imprime el tiempo que lleva la simulacion.
  printf ("\nContador Cliente/Preferente:%d\n", ClyPr);
  printf ("\nC = Cliente\t\tU = Usuario\t\tP = Preferente\n");  //Indicador de las personas de la simulacion.
}

int
main (void)
{
  int cont = 0;                 //Contador para inicializar las cosas.
  int cont2 = 0;
  int atendidos = 0;            //Contador para los que ya fueron atendidos.
  int ClyPr = 0;                //Contador que de clientes y preferentes que no debe pasar el numero 5.
  int tiempomod = 0;            //Tiempo de la simulacion.
  int caja = 0;                 //Valor de la caja en los arreglos.
  int numero = 0;               //Numero de cajeros disponibles que selecciono el usuario para la simulacion.
  int tiempos[4];               //Tiempo de cada caja, 0 el tiempo de atencion de las cajas, 1-3 tiempo que llega la gente.
  int personas[3];              //Las personas de las colas, 0 cliente, 1 usuario, 2 preferente.
  elemento aux;                 //Elemento auxiliar para meter elementos a la cola.
  cola cajero[10];              //Colas que son los cajeros donde son atendidos las personas.
  cola filas[3];                //Colas que son las filas de los usuarios, clientes y preferentes.

  srand (time (NULL));          //a lo mejor se quita esta linea

  for (cont = 0; cont < 3; cont++)      //Ciclo que inicializa las colas de personas y arreglos de tiempo.
    {
      Initialize (&filas[cont]);
      personas[cont] = 0;
      tiempos[cont] = 0;
    }
  tiempos[3] = 0;               //Tiempo que falto inicializar en 0.
  for (cont = 0; cont < 10; cont++)     //Ciclo que inicializa los cajeros.
    Initialize (&cajero[cont]);

  //Instrucciones para obtener la informacion del usuario.
  printf ("Cuantas cajeros atienden:   ");
  scanf ("%d", &numero);        //Obtiene el numero de las cajas que estan abiertas.
  printf ("Asigne el tiempo en que los cajeros atienden:   ");
  scanf ("%d", &tiempos[0]);    //Obtiene el tiempo en que atienden las cajas.
  printf ("Asigne el tiempo en que los clientes llegan:   ");
  scanf ("%d", &tiempos[1]);    //Obtiene el tiempo en que llegan los clientes.
  printf ("Asigne el tiempo en que los usuarios llegan:   ");
  scanf ("%d", &tiempos[2]);    //Obtiene el tiempo en que llegan los usuarios.
  printf ("Asigne el tiempo en que los clientes preferentes llegan:   ");
  scanf ("%d", &tiempos[3]);    //Obtiene el tiempo en que llegan los clientes preferentes.

  while (1)
    {
      Imprimir_banco (cajero, filas, tiempos, cont, tiempomod, atendidos,
                      ClyPr, aux);
      sleep (1);                //Tiempo de pausa.
      tiempomod++;              //Tiempo de la simulacion
      cont = 0;
      if ((tiempomod % tiempos[1]) == 0)        //Si el modulo del tiempo con la llegada del cliente es 0, hace push a la fila 1.
        {
          personas[0] = personas[0] + 1;        //Sumar uno al valor de clientes en la cola que se formo.
          //Potencial crash en estatica, poner un if despues si queremos
          aux.n = personas[0];
          aux.c = 'C';
          Queue (&filas[0], aux);       //Mete al cliente 'n' a la cola.
        }

      if ((tiempomod % tiempos[2]) == 0)        //Si el modulo del tiempo con la llegada del usuario es 0, hace push a la fila 2.
        {
          personas[1] = personas[1] + 1;        //Sumar uno al valor de usuarios en la cola que se formo.
          //Potencial crash en estatica, poner un if despues si queremos
          aux.n = personas[1];
          aux.c = 'U';
          Queue (&filas[1], aux);       //Mete al usuario 'n' a la cola.
        }

      if ((tiempomod % tiempos[3]) == 0)        //Si el modulo del tiempo con la llegada del preferente es 0, hace push a la fila 3.
        {
          personas[2] = personas[2] + 1;        //Sumar uno al valor de preferentes en la cola que se formo.
          //Potencial crash en estatica, poner un if despues si queremos
          aux.n = personas[2];
          aux.c = 'P';
          Queue (&filas[2], aux);       //Mete al cliente preferente 'n' a la cola.
        }
      if ((tiempomod % tiempos[0]) == 0)        //Modulo del tiempo con el que son atendidos es 0 hace push de los cajeros.
        {
          for (cont = 0; cont < numero; cont++) //Primero saca a los que fueron atendidos
            {
              if (Empty (&cajero[cont]) == FALSE)       //Verifica si no esta vacia la fila y evitar matar el programa.
                {
                  Dequeue (&cajero[cont]);      //Lo saca de la cajero en el que estaba.
                }
            }
          Imprimir_banco (cajero, filas, tiempos, cont, tiempomod, atendidos,
                          ClyPr, aux);

          //Bloque preferentes
          while ((Empty (&filas[2]) == FALSE) && (ClyPr < 4)
                 && (cont2 < numero))
            /*menor a 4 para que el 5 sea el cliente y el 6 el usuario, por lo menos deja una caja para los clientes y si es solo una caja, solo atienda a los importantes
               y el quinto sea el cliente y el sexto el usuario y no romper el sistema de atendido.
               While para hacer Pop de los preferentes ya que son la maxima prioridad pero tambien los demas deben ser atendidos. */
            {
              aux = Dequeue (&filas[2]);
              for (cont = 0; cont < numero; cont++)     //Verifica que cajeros estan vacios para atender al preferente.
                {
                  if (Empty (&cajero[cont]))    //Si lo esta, lo acomodan en ese cajero y sale del for
                    {
                      Queue (&cajero[cont], aux);
                      ClyPr++;  //Suma uno a los clientes/preferentes.
                      cont = 20;
                      cont2++;  //Suma uno al contador dos las cajas ocupadas
                    }
                  Imprimir_banco (cajero, filas, tiempos, cont, tiempomod,
                                  atendidos, ClyPr, aux);
                }
            }

          //Bloque clientes
          while ((Empty (&filas[0]) == FALSE) && (ClyPr <= 4)
                 && (cont2 != numero) )
            /*Cuando la fila de clientes no esta vacia, el contador clientes/preferentes no pasa los 5 y los preferentes ya se formaron,
               los clientes son atendidos en las cajas o caja que sobra ya que siempre estan siendo atendidos.
               While para hacer Pop de los preferentes ya que son la maxima prioridad pero tambien los demas deben ser atendidos. */
            {
              aux = Dequeue (&filas[0]);
              for (cont = 0; cont < numero; cont++)     //Verifica que cajeros estan vacios para atender al cliente.
                {
                  if (Empty (&cajero[cont]))    //Si lo esta, lo acomodan en ese cajero y sale del for
                    {
                      Queue (&cajero[cont], aux);
                      ClyPr++;  //Suma uno a los clientes/preferentes.
                      cont = 20;
                      cont2++;  //Suma uno al contador dos las cajas ocupadas
                    }
                  Imprimir_banco (cajero, filas, tiempos, cont, tiempomod,
                                  atendidos, ClyPr, aux);
                }
            }

          //Bloque usuarios
          while ((Empty (&filas[1]) == FALSE) && (cont2 != numero))
            /*Si las fila de usuarios no esta vacia y cuando esten los cajeros disponibles van a ser atendidos
               While para hacer Pop de los usuarios cuando los clientes y preferentes ya estan siendo atendidos. */
            {
              aux = Dequeue (&filas[1]);
              for (cont = 0; cont < numero; cont++)     //Verifica que cajeros estan vacios para atender al preferente.
                {
                  if (Empty (&cajero[cont]))    //Si lo esta, lo acomodan en ese cajero y sale del for
                    {
                      Queue (&cajero[cont], aux);
                      ClyPr = 0;        //Pone en cero el contador de clientes/preferentes porque 1 ya esta siendo atendidos.
                      cont = 20;
                      cont2++;  //Suma uno al contador dos las cajas ocupadas
                    }
                  Imprimir_banco (cajero, filas, tiempos, cont, tiempomod,
                                  atendidos, ClyPr, aux);
                }
              //En caso de que llegue un momento donde los usuarios son atendidos, tiene que haber una caja por lo menos para el cliente y el preferente en caso de que sus filas no esten vacias.

              if (((Empty (&filas[0]) == FALSE) || (Empty (&filas[2]) == FALSE)) && (cont2 == numero - 1))      //Si sus filas no son vacias y solo queda una caja libre
                {
                  if (Empty (&filas[2]) == FALSE)
                    {
                      aux = Dequeue (&filas[2]);        //Lo saca de su fila al preferente y lo forma en la caja vacia
                      Queue (&cajero[cont2], aux);
                      ClyPr++;  //Suma uno al contador de ellos
                      cont2++;  //Suma uno a las cajas ocupadas porque la va ocupar un cliente o un preferente
                      Imprimir_banco (cajero, filas, tiempos, cont, tiempomod,
                                      atendidos, ClyPr, aux);
                    }

                  else          //Si no es preferente, entonces la fila que tiene gente es los clientes
                    {
                      aux = Dequeue (&filas[0]);        //Sacan a uno de la fila y lo pone en la caja vacia
                      Queue (&cajero[cont2], aux);
                      ClyPr++;  //Suma uno al contador de ellos
                      cont2++;  //Suma uno a las cajas ocupadas porque la va ocupar un cliente o un preferente
                      Imprimir_banco (cajero, filas, tiempos, cont, tiempomod,
                                      atendidos, ClyPr, aux);
                    }
                }
            }
          cont2 = 0;
          /*El contador 2 se pone en cero hasta al final porque si se pone en 0 cada final de ciclo se pierden clientes porque los saca y no los pone en ningun lado
             ejemplo: si hay 5 preferentes, 2 clientes, 7 usuarios con 5 cajas disponibles, lo que hace el contador dos es contar el numero de cajas ocupadas, entonces si el contador de clientes/preferentes es 0
             entonces se atienden 3 preferentes y el cont 2 ya es 3, se atienden los 2 clientes y el cont 2 es 5 por lo tanto todas las cajas ya estan ocupadas, y siguen los usuarios pero ya no son atendidos hasta la siguiente ronda porque 
             ya esta todo ocupado, si el cont 2 se hubiera reiniciado en cada ciclo hubiera sacado aun asi a 5 usuarios pero no hay donde meterlos, por eso hasta el final del todo se pone en 0  */

        }

    }
  return 0;
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                 294,1       Final

