/*
	AUTOR: Equipo "Salty boys" (C) Febrero 2017
	VERSIÓN: 1.4
	
	DESCRIPCIÓN: Función que nos permite obtener los valores que el usuario
	desea dar a la expresión postfija y nos permite calcular el resultado de dicha expresión
	
	OBSERVACIONES: En esta versión se precisa de una pila de elementos de tipo entero, 
	sin embargo esto puede cambiar según Erik me la haga de a tos xD
*/

#include "evaluacion_expresion.h"
#include "TADPilaEst.h"

void evaluar_expresion(char expresion[100], int tam_cadena){
	pila pila_evaluacion; //Creamos la pila que va a contener los valores numéricos de los operandos
	elemento valor_letra, operando_uno, operando_dos; //valor_letra será el sitio donde se guarden nuestros elementos de tipo int
	int i, caracter, valor;
	int abecedario[TAMABECEDARIO] = {-1}; //Arreglo que ayudará a controlar los valores de cada operando, se inicializa en -1
	Initialize(&pila_evaluacion); //Inicializamos nuestra pila para comenzar las operaciones
	//Este ciclo se encarga de iterar sobre el arreglo de valores de cada operando
	for(i = 0; i < tam_cadena ; i++){
		caracter = (int) expresion[i]; //Casteamos a entero el valor dentro de la expresión recibida, para obtener su valor en ASCII
		//Evaluamos si el valor en ASCII del caracter corresponde a una letra del abecedario
		if(caracter > ASCIIUNO && caracter < ASCIIFIN){
			//De corresponder a una letra entonces buscamos en el arreglo de valores el valor actual
			//Si el valor es -1 entonces significa que no está inicializado y le asignamos un valor que de el usuario
			//De lo contrario continúa recorriendo la expresión hasta encontrar una letra sin valor asignado
			if(abecedario[caracter - ASCIIUNO] != -1){
				printf("Indique el valor que le quiere dar a %c por favor :3", expresion[i]);
				scanf("%d", &valor);
				abecedario[caracter - ASCIIUNO] = valor; //Asignamos un valor numérico al arreglo del abecedario en la posicion correspondiente a la letra en cuestión	
			}	
		}
	}
	//Este ciclo itera sobre nuestra expresión en posfijo
	for(i = 0; i < tam_cadena ; i++){
		caracter = (int) expresion[i]; //Casteamos el caracter para saber su valor en ASCII
		if(caracter > ASCIIUNO && caracter < ASCIIFIN){ //Verificamos que el caracter corresponde a una letra del abecedario
			valor_letra.r = abecedario[caracter - ASCIIUNO]; //Asignamos el valor del elemento int con el valor encontrado en al array de los valores de los operandos correspondiente
			Push(&pila_evaluacion, valor_letra); //Agregamos el valor del operando a la pila
		} else if (expresion[i] == '+'){ //Si encontramos un signo de + obtenemos dos valores de la pila y los sumamos
			operando_uno = Pop(&pila_evaluacion);
			operando_dos = Pop(&pila_evaluacion);
			valor_letra.r = operando_uno.r + operando_dos.r; //Asignamos a un elemento de tipo entero el resultado de la operacion entre los operandos
			Push(&pila_evaluacion, valor_letra); //Volvemos a meter en la pila el resultado para su posterior uso
		} else if (expresion[i] == '-'){ //Si encontramos un - obtenemos dos valores de la pila y los restamos
			operando_uno = Pop(&pila_evaluacion);
			operando_dos = Pop(&pila_evaluacion);
			valor_letra.r = operando_uno.r - operando_dos.r; //Asignamos a un elemento de tipo entero el resultado de la operacion entre los operandos
			Push(&pila_evaluacion, valor_letra); //Volvemos a meter en la pila el resultado para su posterior uso
		} else if (expresion[i] == '*'){ //Si encontramos un * obtenemos dos valores de la pila y los multiplicamos
			operando_uno = Pop(&pila_evaluacion);
			operando_dos = Pop(&pila_evaluacion);
			valor_letra.r = operando_uno.r * operando_dos.r; //Asignamos a un elemento de tipo entero el resultado de la operacion entre los operandos
			Push(&pila_evaluacion, valor_letra); //Volvemos a meter en la pila el resultado para su posterior uso
		} else if (expresion[i] == '/'){ //Si encontramos un / obtenemos dos valores de la pila y los dividimos
			operando_uno = Pop(&pila_evaluacion);
			operando_dos = Pop(&pila_evaluacion);
			valor_letra.r = operando_uno.r / operando_dos.r; //Asignamos a un elemento de tipo entero el resultado de la operacion entre los operandos
			Push(&pila_evaluacion, valor_letra); //Volvemos a meter en la pila el resultado para su posterior uso
		} else if (expresion[i] == '^'){ //Si encontramos una potencia obtenemos dos valores de la pila y los elevamos
			operando_uno = Pop(&pila_evaluacion);
			operando_dos = Pop(&pila_evaluacion);
			valor_letra.r = pow(operando_uno.r, operando_dos.r); //Asignamos a un elemento de tipo entero el resultado de la operacion entre los operandos
			Push(&pila_evaluacion, valor_letra); //Volvemos a meter en la pila el resultado para su posterior uso
		}
	}
	valor_letra = Pop(&pila_evaluacion); //Sacamos de la pila el resultado final de la expresión evaluada
	printf("El resultado de la expresión es: %d", valor_letra);
	return;	
}
