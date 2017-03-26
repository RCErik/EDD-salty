#include<stdio.h>
#include<windows.h>
#include "TADColaEst.h"

int main(){
    int cantidad, i, tiempo, tiempo_total = 0;
    char nombre[45], actividad[200], ID[45];
    cola c_listo, c_ejec, c_final;
    elemento e;
    Initialize(&c_listo);
    Initialize(&c_ejec);
    Initialize(&c_final);
    printf("Indique la cantidad de procesos a realizar\n\n");
    scanf("%d", &cantidad);
    for(i = 1; i <= cantidad ; i++){
        printf("Indica el nombre del proceso %d \n\n", i);
        scanf("%s", &nombre);
        printf("Indica la tarea que realiza el proceso %d \n\n", i);
        scanf("%s", &actividad);
        printf("Indica el ID del proceso %d \n\n", i);
        scanf("%s", &ID);
        printf("Indica el tiempo de ejecucion del proceso %d \n\n", i);
        scanf("%d", &tiempo);
        e.nombre = nombre;
        e.actividad = actividad;
        e.ID = ID;
        e.tiempo = tiempo;
        Queue(&c_listo,e);
        tiempo_total = tiempo_total + tiempo;
    }
    for(i = 0; i <= tiempo_total ; i++){
        e = Dequeue(&c_listo);
        Queue(&c_ejec, e);
        Sleep(1000);
        e = Dequeue(&c_ejec);
        e.tiempo_aux++;
        if(e.tiempo == e.tiempo_aux){
            Queue(&c_final, e);
            e.tiempo_ejec = i;
            printf("Proceso: %d \n", e.n);
            printf("Actividad: %s \n", e.actividad);

            printf("ID: %s \n", e.ID);
            printf("Tiempo total de ejecucion: %d \n", e.tiempo_ejec);
        }
        else
            Queue(&c_listo, e);
    }


    return 0;
}
