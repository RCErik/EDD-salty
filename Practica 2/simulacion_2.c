#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include "TADColaEst.h"


//Imprimimos los procesos que han finalizado y se llama el método cuando todos los procesos fueron ejecutados
void imprimirFinalizados(cola *c){
	int i; //variable auxiliar para las iteraciones
	elemento e; //elemento auxiliar para los dequeues
	printf("Procesos finalizados\n\n\n");
	//recorremos desde el numero de elementos de nuestra cola hacia atras
	for(i = c -> num_elem; i > 1 ; i--){
		e = Dequeue(c); //desencolamos cada uno de los procesos finalizados
		//Imprimimos los datos principales de cada uno de los elementos
		printf("Proceso: %s \n", e.nombre);
		printf("ID: %s \n", e.ID);
		printf("Tiempo total de ejecucion: %d \n\n\n", e.tiempo_ejec + 1);
	}
	return;
}

//Esta función nos permite imprimir la  el primer elemento de la cola de procesos y la de espera
//recibe la cola a analizar y la posición del elemento a imprimir
//la posici+on cambia de la siguiente manera:
//	para la cola de procesos listos el proximo a ejecutar es de posicion 1
//	para la misma cola el ultimo ejecutado cambia al último índice de la misma
void imprimirOtro(cola *c, int pos){
	elemento e;
	int tiempo_faltante = 0; //vvariable que nos permitirá almacenar el tiempo faltante para que el proceso acabe su ejecución
	e = Element(c, pos); //Obtenemos el proceso correspondiente
	tiempo_faltante = e.tiempo - e.tiempo_aux; //Restamos el tiempo que se espera ejecutar menos el ejecutado hasta el momento
	//Imprimimos los datos relevantes del proceso
	printf("Proceso: %s \n", e.nombre);
	printf("ID: %s \n", e.ID);
	printf("Tiempo para concluir: %d \n\n\n", tiempo_faltante);
	return;
}

//Función para el proceso en ejecución actual, recibe un entero i que funciona como tiempo actual de ejecución total
void imprimir(int i, cola *c){
	elemento e; //Elemento auxiliar
	int tiempo_ejec = 0; //Variable que almacena el tiempo que lleva ejecutandose el proceso en cuestión 
	e = Front(c);
	tiempo_ejec = i;
	e.tiempo_ejec = i;
	//Imprimimos los datos principales del elemento
	printf("Proceso: %s \n", e.nombre);
	printf("Actividad: %s \n", e.actividad);
	printf("ID: %s \n", e.ID);
	printf("Tiempo total de ejecucion: %d \n\n", tiempo_ejec);
	return;
}

//Esta función permite consultar el estado actual de las colas para llamar a su posterior impresión
void evaluarEstadoColas(cola *c_listo, cola *c_ejec, cola *c_fin, int i){
	//Si la cola de procesos para ejecutar está vacía se indica, de lo contrario se procede al siguiente bloque de instrucciones
	if(Empty(c_listo))
		printf("\n\n La cola de procesos se encuentra vacia \n\n");
	else{
		//Se consulta la cola y se llama la función de impresión con la posición del primer elemento de la lista
		//correspondiente al que va a continuar en el segundo siguiente
		printf("\n\n Proximo a ejecutarse \n\n");
		imprimirOtro(c_listo, 1);
		//Si la cola no contiene solamente un elemento entonces llamamos la impresión con la posición del último proceso en cola
		if(c_listo -> num_elem > 1){
			printf("\n\n Ultimo ejecutado \n\n");
			imprimirOtro(c_listo, c_listo -> num_elem - 1);
		}
	}
	//Si la cola de ejecución se encuentra vacía se indica
	if(Empty(c_ejec))	
		printf("\n\n La cola de ejecucion se encuentra vacia \n\n");
	else{
		//En este caso mandamos a llamar la función de impresión
		printf("\n\n Cola de ejecucion \n\n");
		imprimir(i, c_ejec);
	}
	return;
}

int main(void){
	//Variables que almacenan respectivamente la cantidad de procesos a ejecutar, auxiliar de iteración, el tiempo para cada proceso
	//y la suma del tiempo de todos los procesos juntos
	int cantidad, i, tiempo, tiempo_total = 0;
	char nombre[45], actividad[200], ID[45], c;
	cola c_listo, c_ejec, c_final;
	elemento e, aux;
	//Inicializamos las tres colas para los procesos
	Initialize(&c_listo); //Cola lista para los procesos a ejecutar
	Initialize(&c_ejec); //Cola de procesos en ejecución
	Initialize(&c_final); //Cola de procesos finalizados
	printf("Indique la cantidad de procesos a realizar\n\n");
	scanf("%d", &cantidad);
	system("clear");
	fflush(stdin);
	//A continuación obtenemos los datos necesarios para nuestros procesos
	for(i = 1; i <= cantidad ; i++){
		c = getchar();
		printf("Indica el nombre del proceso %d \n\n", i);
		fgets(nombre,44,stdin);
		printf("Indica la actividad que realiza el proceso: %d \n\n", i);
		fgets(actividad,200,stdin);
		printf("Indica el ID del proceso %d \n\n", i);
		fgets(ID,45,stdin);
		printf("Indica el tiempo de ejecucion del proceso %d \n\n", i);
		scanf("%d", &tiempo);
		//Copiamos el contenido de lo que el usuario escribió a lo que tenemos en nuestro struct elemento
		strcpy(e.nombre, nombre);
		strcpy(e.actividad, actividad);
		strcpy(e.ID, ID);
		e.tiempo = tiempo;
		//Encolamos el proceso para que se encuentre preparado para ejecutarse
		Queue(&c_listo, e);
		//Sumamos el tiempo de todos los procesos para tener el tope máximo que durará nuestra simulación
		tiempo_total = tiempo_total + tiempo;
		system("clear");
	}
	for(i = 0; i <= tiempo_total ; i++){
		//Evaluamos el estado de las colas para su posterior impresión
		evaluarEstadoColas(&c_listo, &c_ejec, &c_final, i);
		//Si la cola de listos tiene elementos desencolamos y encolamos el elemento en la cola de ejecución
		if(!(Empty(&c_listo))){
			e = Dequeue(&c_listo);
			Queue(&c_ejec, e);
		}
		system("clear");
		evaluarEstadoColas(&c_listo, &c_ejec, &c_final, i);
		//Pausamos el programa por un segundo
		//La siguiente función está relacionada para funcionar en Linux
		sleep(1);
		//Si existe un proceso en ejecución lo desencolamos y aumentamos el tiempo auxiliar del mismo
		//El tiempo auxiliar nos permite contar la cantidad de veces que ha estado en ejecución para determinar cuándo finaliza
		if(!(Empty(&c_ejec))){
			e = Dequeue(&c_ejec);
			e.tiempo_aux++;
		}
		//Si el tiempo auxiliar del elemento desencolado es igual al que se designó como el tiempo que estaría en ejecución
		//lo encolaríamos a la cola de procesos finalizados
		if(e.tiempo == e.tiempo_aux){
			e.tiempo_ejec = i;
			Queue(&c_final, e);
		}
		//De lo contrario encolamos de nuevo el proceso en la cola de listos para ejecutar
		else 
			Queue(&c_listo, e);
		system("clear");
	}
	//Terminado el ciclo de ejecución imprimimos todos los procesos finalizados
	imprimirFinalizados(&c_final);
	return 0;
}
