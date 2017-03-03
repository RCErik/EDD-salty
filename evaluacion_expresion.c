/*
	AUTOR: Carlos Armando Ochoa Ginera
	VERSIÓN: 1.2
	
	DESCRIPCIÓN: Función que nos permite obtener los valores que el usuario
	desea dar a la expresión postfija y nos permite calcular el resultado de dicha expresión
	
	OBSERVACIONES: En esta versión se precisa de una pila de elementos de tipo entero, 
	sin embargo esto puede cambiar según Erik me la haga de a tos xD
*/

#include <stdio.h>
#include <math.h>
#include "TADPila_stc.h"

#define TAMABECEDARIO 27
#define ASCIIUNO 64
#define ASCIIFIN 91

void evaluar_expresion(char expresion[100], int tam_cadena){
	Pila pila_evaluacion;
	int i, caracter, valor, operando_uno, operando_dos;
	int abecedario[TAMABECEDARIO] = {-1};
	Initialize(&pila_evaluacion);
	for(i = 0; i < tam_cadena ; i++){
		caracter = (int) expresion[i];
		if(caracter > ASCIIUNO && caracter < ASCIIFIN){
			if(abecedario[caracter - ASCIIUNO] != -1){
				printf("Indique el valor que le quiere dar a %c por favor :3", expresion[i]);
				scanf("%d", &valor);
				abecedario[caracter - ASCIIUNO] = valor;	
			}	
		}
	}
	for(i = 0; i < tam_cadena ; i++){
		caracter = (int) expresion[i];
		if(caracter > ASCIIUNO && caracter < ASCIIFIN)
			valor = abecedario[caracter - ASCIIUNO];
			Push(&pila_evaluacion, valor);
		} else if (expresion[i] == '+'){
			operando_uno = Pop(&pila_evaluacion);
			operando_dos = Pop(&pila_evaluacion);
			valor = operando_uno + operando_dos;
			Push(&pila_evaluacion, valor);
		} else if (expresion[i] == '-'){
			operando_uno = Pop(&pila_evaluacion);
			operando_dos = Pop(&pila_evaluacion);
			valor = operando_uno - operando_dos;
			Push(&pila_evaluacion, valor);
		} else if (expresion[i] == '*'){
			operando_uno = Pop(&pila_evaluacion);
			operando_dos = Pop(&pila_evaluacion);
			valor = operando_uno * operando_dos;
			Push(&pila_evaluacion, valor);
		} else if (expresion[i] == '/'){
			operando_uno = Pop(&pila_evaluacion);
			operando_dos = Pop(&pila_evaluacion);
			valor = operando_uno / operando_dos;
			Push(&pila_evaluacion, valor);
		} else if (expresion[i] == '^'){
			operando_uno = Pop(&pila_evaluacion);
			operando_dos = Pop(&pila_evaluacion);
			valor = pow(operando_uno, operando_dos);
			Push(&pila_evaluacion, valor);
		}
	}
	valor = Pop(&pila_evaluacion);
	printf("El resultado de la expresión es: %d", valor);
	return;	
}

