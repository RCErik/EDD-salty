/*
	AUTOR: Equipo "Salty boys" (C) Febrero 2017
	VERSIÓN: 1.0
	
	DESCRIPCIÓN: Main que se usa para conversion y evaluacion de una expresion infijo a posfijo.
	
	OBSERVACIONES: El programa tiene que ser agradable y amigable con el usuario.
	Se tiene que escribir la cadena con mayusculas y sin espacios.
  
  	COMPILACION: gcc main_practica1.c evaluacion_expresion.o expresion_posfija.o 
	validar_expresion.o TADPilaxxx.o -o "Nombre del ejecutable" -lm 
*/

#include "TADPilaDin.h"
#include "expresion_posfija.h"
#include "evaluacion_expresion.h"
#include "validar_expresion.h"

#define TAMANIO 100

int main(void){
	int tam_cadena;  //se inicializa la variable que mantendrá el tamaño de la expresión registrado
	char expresion[TAMANIO], expresion_posfija[TAMANIO]; //el primer areglo corresponde a la expresion que el usuario escribe
	//La segunda variable es la que recibe la expresion convertida en posfijo
	printf("Bienvenido al mundo de la manzana\n\n");
	printf("Seleccione alguna de las opciones del menu a continuación:\n");
	printf("\nEscribe la expresión que deseas evaluar: \n");
	scanf("%s", expresion);
	tam_cadena = strlen(expresion); //Calculamos el tamaño de la expresión del usuario
	/* 
	    Ciclo que se ejecuta en caso de que exista un error en 
	    la evaluación de los paréntesis, para que el usuario
	    introduzca de nueva cuenta la cadena.
	*/
	while(validar_expresion(expresion, tam_cadena) == FALSE){
		printf("\nEscribe la expresión que deseas evaluar: \n");
		scanf("%s", expresion);
		tam_cadena = strlen(expresion);
		validar_expresion(expresion, tam_cadena);	
	}
	//A partir de aquí se ejecutan las demás funciones de forma normal
	printf("\n\nEstamos convirtiendo tu expresión a posfijo, espere por favor :)\n\n");
	//Recibimos en el arreglo de expresion_posfija la nueva cadena correctamente convertida a posfijo
	 Expresion_Posfija(expresion, expresion_posfija, tam_cadena);
	printf("\n\nTu expresión en forma posfija es la siguiente: \n\t %s", expresion_posfija);
	printf("\n\nExcelente, ahora indica los valores de las letras\n\n");
	//Enviamos la expresion convertida a posfijo y el tamaño de la misma, los resultados los imprime la misma función
	evaluar_expresion(expresion_posfija, tam_cadena);
	printf("\n\n¡Gracias por usar el programa :3, te queremos <3\n\n");
	return 0;
}
