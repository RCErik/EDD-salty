#include <stdio.h>
#include "TADPilaEst.h/TADPilaDin.h"

boolean validar_expresion (char cadena[100], int tam_cadena)
{
	pila parentesis;
	elemento aux;
	int contador = 0;
	Initialize (&parentesis);
	
	for(contador = 0; (contador < tam_cadena); contador++)
	{
		if ( (Empty (&parentesis)) == TRUE)
		{
				if (cadena[contador] == '(')
				{
					aux.c = '(';
					Push (&parentesis, aux);
				}
		
		if (cadena[contador] == ')')
				{
					printf("Error, la expresión está mal escrita (la expresion empieza con un parentesis que cierra o tiene un parentesis que cierra de más. :( \n");
					return 0;
				}
		}
		
		if	( (Empty (&parentesis)) == FALSE)
		{
			if (cadena[contador] == '(')
			{
				aux.c = '(';
				Push (&parentesis, aux);
			}
			
			if (cadena[contador] ==')')
			{
				Pop (&parentesis);
			}
		}
	}
	if ( (Empty (&parentesis)) == FALSE)
	{
		printf("Error, faltan parentesis que cierran en la expresión. :( ");
		return 0;
	}
	
	if ( (Empty (&parentesis)) == TRUE)
	{
		printf ("Su expresión está bien escrita. :)");
	}
	return 1;
}

