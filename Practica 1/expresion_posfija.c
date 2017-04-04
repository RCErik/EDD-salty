/*

AUTOR: Equipo "Salty Boys" (C) Febrero 2017
VERSIÓN: 1.3

DESCRIPCIÓN: Funcion que hace uso de la pila para convertir una expresion infijo
dada por el usuario a una expresion posfijo.

OBSERVACIONES: Se emplea la libreria TADPilaDin.h o TADPilaEst.h

*/


#include "TADPilaDin.h"
#include "expresion_posfija.h"

char *
Expresion_Posfija (char cadena[150], char cadena_aux[150], int tam_cadena)
{
  pila operadores;       //Se declara una pila llamada operadores.
  elemento aux;          //Elemento auxiliar que se usa para hacer Push de los elementos.
  elemento aux_2;        //Elemento auxiliar que ayuda a comparar el Tope de la pila con las condiciones de la función.
  int i = 0;             //Entero que sirve como contador de la cadena infijo.
  int j = 0;             //Entero que sirve como contador de la cadena posfijo.
  int k = 0;             //Entero auxiliar de j para contar los parentesis que van en la cadena auxiliar.
  Initialize (&operadores);      //Inicializa la pila operadores.

  for (i = 0; i < tam_cadena; i++)  //Ciclo donde se compara el elemento de la cadena en la posición 'i' con las condiciones de la funcion.
    {

      if ((cadena[i] == '^') || (cadena[i] == '/') || (cadena[i] == '*')        //Condicional if el cual separa los operadores de las letras
          || (cadena[i] == '+') || (cadena[i] == '-') || (cadena[i] == '(')     //para asignarlos en la cadena posfijo de forma correcta.
          || (cadena[i] == ')'))
        {
          if (cadena[i] == '(')         //Si el elemento en la cadena infijo en la posicion 'i' es igual a '('
            {                           //entonces que haga Push del parentesis a la pila.

              aux.c = '(';
              Push (&operadores, aux);
              k++;                      //Suma uno al entero K para llevar el control de los elementos de la cadena.

            }

          if (cadena[i] == ')')         //Si el elemento en la cadena infijo en la posición 'i' es igual a ')'
            {                           //entra dentro del bloque de condicional

              aux_2 = Top (&operadores);        //Asigna al auxiliar 2 el elemento tope de la pila operadores.

              while (aux_2.c != '(')            //Mientras auxiliar 2 sea diferente del parentesis que abre ejecuta el ciclo.
                {
                  aux_2 = Pop (&operadores);    //Al auxiliar 2 se le asigna el elemento que se le hace Pop de la pila.
                  cadena_aux[j] = aux_2.c;      //Asignamos ese valor a la cadena posfijo.
                  aux_2 = Top (&operadores);    //Y volvemos asignar el valor tope de la pila al auxiliar 2 para la comparacion del ciclo.
                  j++;                          //Aumentamos en uno al contador de la cadena posfijo.
                }

              Pop (&operadores);                //Hace Pop en la pila para quitar al parentesis que abre.
              k++;                              //Aumenta el contador de los parentesis para no causar errores en el numero de la cadena posfijo.

            }

          if ((cadena[i] == '+') || (cadena[i] == '-')) //Si el elemento de la cadena infijo en la posición 'i' es igual al caracter
            {                                           //de suma o de la resta se mete al bloque de instrucciones.

              if (FALSE == Empty (&operadores))         //Si la Pila no esta vacia puede hacer este bloque de instrucciones.
                {
                  aux_2 = Top (&operadores);            //Asigna a auxiliar 2 el elemento tope de la pila.

                  while ((aux_2.c != '(') && (Empty (&operadores) == FALSE))
                  //Mientras el elemento del auxiliar 2 sea diferente del parentesis que abre o la pila no este vacia
                  //hará Pop de la pila y lo asigna a la cadena posfijo.
                    {
                      aux_2 = Pop (&operadores);
                      cadena_aux[j] = aux_2.c;
                        if (Empty (&operadores) == FALSE)       //Condicion que evita el subdesbordamiento
                      aux_2 = Top (&operadores);                //Prepara al elemento auxiliar 2 para la comparacion del ciclo.
                      j++;                                      //Suma uno al contador de la cadena posfijo.
                    }

                  if ((aux_2.c == '(') || (Empty (&operadores) == TRUE))
                  //Si la pila no esta vacia y el elemento tope es un parentesis que abre
                  //hace push del operador de la cadena infijo en la posicion 'i'.
                    {
                      if (cadena[i] == '+')
                        {
                          aux.c = '+';
                          Push (&operadores, aux);
                        }

                      if (cadena[i] == '-')
                        {
                          aux.c = '-';
                          Push (&operadores, aux);
                        }
                    }
                }
              if (TRUE == Empty (&operadores)) //Si la pila esta vacia, hace push del elemento de la cadena infijo
                {                              //en la posicion 'i'.

                  if (cadena[i] == '+')
                    {
                      aux.c = '+';
                      Push (&operadores, aux);
                    }

                  if (cadena[i] == '-')
                    {
                      aux.c = '-';
                      Push (&operadores, aux);
                    }

                }
            }


          if ((cadena[i] == '*') || (cadena[i] == '/')) //En caso de que el elemento de la cadena infijo sea un operador de 
            {                                           //multiplicacion o division se ejecuta lo siguiente.

              if (FALSE == Empty (&operadores))         //Si la pila no esta vacia, asigna al auxiliar 2 el elemento tope de la pila.
                {
                  aux_2 = Top (&operadores);            //Si el elemento es el operador de la potencia entonces hace Pop de la pila 
                  if (aux_2.c == '^')
                    {
                      aux_2 = Pop (&operadores);
                      cadena_aux[j] = aux_2.c;
                      j++;                              //Aumenta el contador j para llevar el control de la cadena posfijo.
                    }

                  if ((aux_2.c == '*') || (aux_2.c == '/')) //Si despues el elemento tope es el operador de multiplicacion
                    {                                       //o division, hace pop de la pila y lo asigna a la cadena posfijo.
                      aux_2 = Pop (&operadores);
                      cadena_aux[j] = aux_2.c;
                      j++;

                      if (cadena[i] == '*')                 //Si el elemento i de la cadena infijo es el operador de multiplicacion hace Push.
                        {
                          aux.c = '*';
                          Push (&operadores, aux);
                        }

                      if (cadena[i] == '/')                 //Si el elemento i de la cadena infijo es el operador de division hace Push.
                        {
                          aux.c = '/';
                          Push (&operadores, aux);
                        }
                    }
  if ((aux_2.c == '(') || (aux_2.c != '*') || (aux_2.c != '/'))
                  //Si el elemento de tope de la pila es un parentesis o un operador diferente al de multiplicacion o la division,
                  //hace push del operador en la posicion 'i' de la cadena infijo.
                    {

                      if (cadena[i] == '*')
                        {
                          aux.c = '*';
                          Push (&operadores, aux);
                        }

                      if (cadena[i] == '/')
                        {
                          aux.c = '/';
                          Push (&operadores, aux);
                        }
                    }
                }
              if (TRUE == Empty (&operadores)) //Si la pila esta vacia, hace push del operador en la posicion 'i' de la cadena infijo.
                {

                  if (cadena[i] == '*')
                    {
                      aux.c = '*';
                      Push (&operadores, aux);
                    }
                  if (cadena[i] == '/')
                    {
                      aux.c = '/';
                      Push (&operadores, aux);
                    }
                }
            }


          if (cadena[i] == '^') //Si el operador en la posicion 'i' de la cadena infijo es la potencia, entonces hace lo siguente.
            {
              if (FALSE == Empty (&operadores)) //Si la pila no esta vacia, asigna al auxiliar 2 el elemento tope de la pila
                {
                  aux_2 = Top (&operadores);
                  if (aux_2.c == '^')           //Si ese elemento es la potencia, hace Pop, lo asigna a la cadena posfija
                    {                           //suma el contador j y hace push del operador de la cadena infija en la posicion 'i'.
                      aux_2 = Pop (&operadores);
                      cadena_aux[j] = aux_2.c;
                      j++;
                      aux.c = '^';
                      Push (&operadores, aux);
                    }

                  if ((aux_2.c == '(') || (aux_2.c != '^'))
                  //Si el elemento tope de la pila es el parentesis que abre o es diferente de la potencia, hace push. 
                    {
                      aux.c = '^';
                      Push (&operadores, aux);
                    }
                }
              if (TRUE == Empty (&operadores))  //En caso de que la pila este vacia, hace push del operador potencia a la pila.
                {
                  aux.c = '^';
                  Push (&operadores, aux);
                }
            }

        }

      else               //En caso de que el elemento de la cadena infijo no sea un operador, asigna directamente la letra a la
        {                //cadena posfijo.

          cadena_aux[j] = cadena[i];
          j++;                          //Aumenta el contador de la cadena posfijo uno.

        }
    }

  while ((j+k) < tam_cadena)            //Ciclo while que sirve para sacar todos los elementos faltantes de la pila en caso de que sea asi,
    {                                   //Para eso son el entero j (que es el contador de la cadena posfijo) y el entero k (que cuenta los
      aux_2 = Pop (&operadores);        //parentesis), mientras que la suma de j y k sea menor al tamaño de la cadena se ejecutara el ciclo.
      cadena_aux[j] = aux_2.c;
      j++;
    }
  Destroy (&operadores);                //Destruye la pila operadores.
  return cadena_aux;                    //Retorna la cadena posfijo.
}
