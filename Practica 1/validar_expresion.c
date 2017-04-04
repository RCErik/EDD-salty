/*
AUTOR: Salty Boys (C) Marzo 2017
VERSIÓN: 1.1

DESCRIPCIÓN: Aplicación de la pila, donde verifica la expresion del usuario
para ver si los parentesis estan escritos de manera correcta.

OBSERVACIONES: Se emplea la libreria TADPilaDin.h o TADPilaEst.h y la funcion regresa
un boolean para la verificacion while del main el cual si no esta escrito
correctamente la expresion, le pide al usuario que la escriba de nuevo de forma correcta.

*/

#include "TADPilaEst.h"
#include "validar_expresion.h"

boolean validar_expresion (char cadena[100], int tam_cadena)
{
        pila parentesis;        //Se crea la pila "parentesis" la cual contieene a los parentesis qe abren.
        elemento aux;           //Elemento que ayuda a la funcion hacer Push de los parentesis que abren de la expresion y verificarla.
        int contador;           //Contador que se usa para el ciclo for y hacer las comparaciones de la cadena con las condiciones de la función.
        Initialize (&parentesis);       //Inicializa la pila de los parentesis.

        for(contador = 0; contador < tam_cadena; contador++)    //Inicia el ciclo for y se acaba cuando el contador es igual al tamaño de la cadena.
        {
                if (cadena[contador] == '(')    //Si el elemento de la cadena es un parentesis que abre, hace Push a la pila.
                        {
                                aux.c = '(';            //Se le asigna al auxiliar el parentesis que abre para hacer Push a la pila.
                                Push (&parentesis, aux);
                        }

                if ((cadena[contador] == ')') && (Empty (&parentesis) == TRUE))         //Si es un parentesis que cierra y esta vacia la pila, entonces hay parentesis de más
                        {
                                printf("Error, la expresión está mal escrita (la expresion empieza con un parentesis que cierra o tiene un parentesis que cierra de más. :( \n");
                                return 0;
                        }
                if ((cadena[contador] == ')') && (Empty (&parentesis) == FALSE))        //Si es un parentesis que cierra y no esta vacia la pila, entonces hace Pop.
                        Pop (&parentesis);
        }
        if ( (Empty (&parentesis)) == FALSE)            //Si la Pila no esta vacia al final del ciclo, entonces hay parentesis que faltan o sobran y retorna 0 que es FALSE.
        {
                printf("Error, faltan parentesis que cierran en la expresión. :( \n");
                return 0;
        }

        if ( (Empty (&parentesis)) == TRUE)             //Si la pila esta vacia al final del ciclo, entonces la expresion es correcta y regresa 1 que es TRUE.
        {
                printf ("Su expresión está bien escrita. :)\n");
        }
        Destroy (&parentesis);          //Destruye la pila.
        return 1;
}
