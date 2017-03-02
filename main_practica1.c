#include "TADPila_stc.h"
#include "expresion_posfija.h"
#include "evaluacion.h"

#define TAMANIO 100

int main(void){
	int tam_cadena;  //se inicializa la variable que mantendrá el tamaño de la expresión registrado
	char expresion[TAMANIO], expresion_posfija[TAMANIO]; //el primer areglo corresponde a la expresion que el usuario escribe
	//La segunda variable es la que recibe la expresion convertida en posfijo
	printf("Bienvenido al mundo de la manzana\n\n");
	printf("Seleccione alguna de las opciones del menu a continuación:\n");
	printf("\n\t\tEscribe la expresión que deseas evaluar :3");
	scanf("&s", &expresion);
	tam_cadena = strlen(expresion); //Calculamos el tamaño de la expresión del usuario
	/* 
	    Ciclo que se ejecuta en caso de que exista un error en 
	    la evaluación de los paréntesis, para que el usuario
	    introduzca de nueva cuenta la cadena.
	*/
	while(validar_expresion(expresion, tam_cadena) == FALSE){
		printf("\n\t\tEscribe la expresión que deseas evaluar :3");
		scanf("&s", &expresion);
		tam_cadena = strlen(expresion);
		validar_expresion(expresion, tam_cadena);	
	}
	//A partir de aquí se ejecutan las demás funciones de forma normal
	printf("\n\n\t\tEstamos convirtiendo tu expresión a posfijo, espera porfi n.n\n\n\t\t");
	//Recibimos en el arreglo de expresion_posfija la nueva cadena correctamente convertida a posfijo
	expresion_posfija = Expresion_Posfija(expresion, expresion_posfija, tam_cadena);
	printf("\n\n\t\tTu expresión en forma posfija es la siguiente: \n\n\t\t %s", expresion_posfija);
	printf("\n\n\t\tExcelente, ahora indica los valores de las letras UwU\n\n\t\t");
	//Enviamos la expresion convertida a posfijo y el tamaño de la misma, los resultados los imprime la misma función
	evaluar_expresion(expresion_posfija, tam_cadena);
	printf("\n\n\t\t ¡Gracias por usar el programa :3, te hamamos <3\n\n");
	return 0;
}
