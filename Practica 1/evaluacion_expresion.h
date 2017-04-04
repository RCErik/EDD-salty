/*
	AUTOR: Equipo "Salty boys" (C) Marzo 2017
	VERSIÓN: 1.2
	
	DESCRIPCIÓN: Función que nos permite obtener los valores que el usuario
	desea dar a la expresión postfija y nos permite calcular el resultado de dicha expresión
	
	OBSERVACIONES: En esta versión se precisa de una pila de elementos de tipo entero, 
	sin embargo esto puede cambiar según Erik me la haga de a tos xD
*/

#include <stdio.h>
#include <math.h>
#include <string.h>

#define TAMABECEDARIO 27
#define ASCIIUNO 64
#define ASCIIFIN 91

void evaluar_expresion(char expresion[100], int tam_cadena);
