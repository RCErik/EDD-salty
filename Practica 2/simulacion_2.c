#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include "TADColaEst.h"

void imprimirFinalizados(cola *c){
	int i;
	elemento e;
	printf("Procesos finalizados\n\n\n");
	for(i = c -> num_elem; i > 0 ; i--){
		e = Dequeue(c);
		printf("Proceso: %s \n", e.nombre);
		printf("ID: %s \n", e.ID);
		printf("Tiempo total de ejecucion: %d \n\n\n", e.tiempo_ejec);
	}
	return;
}

void imprimirOtro(cola *c, int pos){
	elemento e;
	int tiempo_faltante = 0;
	e = Element(c, pos);
	tiempo_faltante = e.tiempo - e.tiempo_aux;
	printf("Proceso: %s \n", e.nombre);
	printf("ID: %s \n", e.ID);
	printf("Tiempo para concluir: %d \n\n\n", tiempo_faltante);
	return;
}

void imprimir(int i, cola *c){
	elemento e;
	int tiempo_ejec = 0;
	e = Front(c);
	tiempo_ejec = i;
	e.tiempo_ejec = i;
	printf("Proceso: %s \n", e.nombre);
	printf("Actividad: %s \n", e.actividad);
	printf("ID: %s \n", e.ID);
	printf("Tiempo total de ejecucion: %d \n\n", tiempo_ejec);
	return;
}

void evaluarEstadoColas(cola *c_listo, cola *c_ejec, cola *c_fin, int i){
	if(Empty(c_listo))
		printf("\n\n La cola de procesos se encuentra vacia \n\n");
	else{
		printf("\n\n Proximo a ejecutarse \n\n");
		imprimirOtro(c_listo, 1);
		if(c_listo -> num_elem > 1){
			printf("\n\n Ultimo ejecutado \n\n");
			imprimirOtro(c_listo, c_listo -> num_elem - 1);
		}
	}
	if(Empty(c_ejec))	
		printf("\n\n La cola de ejecucion se encuentra vacia \n\n");
	else{
		printf("\n\n Cola de ejecucion \n\n");
		imprimir(i, c_ejec);
	}
	return;
}

int main(void){
	int cantidad, i, tiempo, tiempo_total = 0;
	char nombre[45], actividad[200], ID[45];
	cola c_listo, c_ejec, c_final;
	elemento e, aux;
	Initialize(&c_listo);
	Initialize(&c_ejec);
	Initialize(&c_final);
	printf("Indique la cantidad de procesos a realizar\n\n");
	scanf("%d", &cantidad);
	system("clear");
	fflush(stdin);
	for(i = 1; i <= cantidad ; i++){
		printf("Indica el nombre del proceso %d \n\n", i);
		fgets(nombre,44,stdin);
		printf("Indica la actividad que realiza el proceso: %d \n\n", i);
		fgets(actividad,200,stdin);
		printf("Indica el ID del proceso %d \n\n", i);
		fgets(ID,45,stdin);
		printf("Indica el tiempo de ejecucion del proceso %d \n\n", i);
		scanf("%d", &tiempo);
		strcpy(e.nombre, nombre);
		strcpy(e.actividad, actividad);
		strcpy(e.ID, ID);
		e.tiempo = tiempo;
		Queue(&c_listo, e);
		tiempo_total = tiempo_total + tiempo;
		system("clear");
	}
	for(i = 0; i <= tiempo_total ; i++){
		evaluarEstadoColas(&c_listo, &c_ejec, &c_final, i);
		if(!(Empty(&c_listo))){
			e = Dequeue(&c_listo);
			Queue(&c_ejec, e);
		}
		system("clear");
		evaluarEstadoColas(&c_listo, &c_ejec, &c_final, i);
		sleep(1);
		if(!(Empty(&c_ejec))){
			e = Dequeue(&c_ejec);
			e.tiempo_aux++;
		}
		if(e.tiempo == e.tiempo_aux){
			e.tiempo_ejec = i;
			Queue(&c_final, e);
		}
		else 
			Queue(&c_listo, e);
		system("clear");
	}
	imprimirFinalizados(&c_final);
	return 0;
}
