#include "TADPila_stc.h"
#include "expresion_posfija.h"
/*Ver 1.2 */

char *
Expresion_Posfija (char cadena[150], char cadena_aux[150], int tam_cadena)
{
  pila operadores;
  elemento aux;
  elemento aux_2;
  int i = 0;
  int j = 0;
  int h = 0;

  Initialize (&operadores);

  for (i = 0; i < tam_cadena; i++)
    {
      aux.c = cadena[i]; 
      if ((aux.c == '^') || (aux.c == '/') || (aux.c == '*') || (aux.c == '+')
          || (aux.c == '-') || (aux.c == '(') || (aux.c == ')'))
        {
          if (aux.c == '(')
            {
              Push (&operadores, aux);
            }

          if (aux.c == ')')
            {
              aux_2 = Top (&operadores);
              while (aux_2.c != '(')
                {
                  aux_2 = Pop (&operadores);
                  cadena_aux[j] = aux_2.c;
                  aux_2 = Top (&operadores);
                  j++;
                } 
              Pop (&operadores);
            }

          if ((aux.c == '+') || (aux.c == '-'))
            {
              aux_2 = Top (&operadores); 
              while ((aux_2.c == '*') || (aux_2.c == '/') || (aux_2.c == '^'))
                {
                  aux_2 = Pop (&operadores);
                  cadena_aux[j] = aux_2.c;
                  aux_2 = Top (&operadores);
                  j++;
                  if (aux.c == '+')
                    {
                      Push (&operadores, aux);
                    }
                  if (aux.c == '-')
                    {
                      Push (&operadores, aux);
                    }
                }
              if ( (aux_2.c != '(') && h != Empty(&operadores) )
                {
                  if ((aux.c == '+') || (aux.c == '-'))
                    {
                      aux_2 = Pop (&operadores);
                      cadena_aux[j] = aux_2.c;
                      j++;
                      if (aux.c == '+')
                        {
                          Push (&operadores, aux);
                        }
                      if (cadena[i] == '-')
                        {
                          Push (&operadores, aux);
                        }
                    }
                }
              else
                {
                  if (aux.c == '+')
                    {
                      Push (&operadores, aux);
                    }
                  if (cadena[i] == '-')
                    {
                      Push (&operadores, aux);
                    }
                }
            }

          if ((aux.c == '*') || (aux.c == '/'))
            {
              aux_2 = Top (&operadores);
              while (aux.c == '^')
                {
                  aux_2 = Pop (&operadores);
                  cadena_aux[j] = aux_2.c;
                  aux_2 = Top (&operadores);
                  j++;
                }
              if (aux.c == '*')
                {
                  Push (&operadores, aux);
                }
              if (aux.c == '/')
                {
                  Push (&operadores, aux);
                }
            }

          if (aux.c == '^')
            {
              Push (&operadores, aux);
            }
        }
      else
        {
          cadena_aux[j] = cadena[i];
          j++;
        }
      printf ("%s \n", cadena_aux);
    }
  while ((j < tam_cadena) && (h != Empty (&operadores)))
    {
      aux_2 = Pop (&operadores);
      cadena_aux[j] = aux_2.c;
      j++;
    }
  Destroy (&operadores);
  printf ("%s \n", cadena_aux);
  return cadena_aux;
}

