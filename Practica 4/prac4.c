/*
	AUTOR: Equipo "Salty boys" (C) Mayo 2017
	VERSIÓN: 1.0
	
	DESCRIPCIÓN: 
	
	OBSERVACIONES: 
	
	COMPILACION:  
*/

#include<stdio.h>
#include<stdlib.h>

void hanoi(int n,int ini, int aux, int fin){
    //En este algoritmo se indica movimiento de un disco de la torre de inicio hacia la final, con el apoyo de una auxiliar en caso de necesitarse
    //Si la cantidad de discos enviada es 1 realizamos el movimiento de la torre A a la C
	if(n == 1){
		printf("Mover disco de la torre %c hacia la torre %c",ini,fin);
	}
	//Si la cantidad de discos es mayor a 1 en la torre entonces:
	else{
        //Llamamos a hanoi con la cantidad de discos menos uno y las torres en este orden,
        //Inicio = A    Auxiliar = C    Final = B
		hanoi(n - 1,ini,fin,aux);
		printf("\nMover disco de la torre %c hacia la torre %c\n",ini,fin);
        //Posteriormente realizamos el amague del movimiento, llamando de nuevo a la función con la nueva cantidad de discos menos uno y las torres en este orden
        //Inicio = B    Auxiliar = A    Final = C
		hanoi(n-1,aux,ini,fin);
	}
}


int tribo(int n){
    //Si la posición consultada es la 0 o 1 devolvemos el número 1
    if((n == 0) || (n == 1))
        return 1;
    //Si la posición consultada es 2 devolvemos el 2
    else if(n == 2)
        return 2;
    //Si la posición del objeto es mayor a dos llamamos de nuevo a la función con la suma del antepenúltima, penúltima y última posición
    else if(n > 2)
        return tribo(n - 1) + tribo(n - 2) + tribo(n - 3);
}

int fibo(int n){
    //Si la posición que se desea consultar es la cero devolvemos automáticamente el cero
    if(n == 0)
        return 0;
    //Si la posición consultada es la 1 o 2 devolvemos el número 1
    else if((n == 1) || (n == 2))
        return 1;
    //Si la posición consultada es mayor a 2 realizamos la recursividad
    else if(n > 2)
        //Consultamos de nuevo la función fibo sumando la posición anterior y la anterior a la anterior
        return fibo(n - 1) + fibo(n - 2);
}

int main(void){
    char ini = 'A'; //Variable que guarda la torre A de hanoi
	char aux = 'B'; //Variable que guarda la torre B de hanoi
	char fin = 'C'; //Variable que guarda la torre C de hanoi
    int n, opcion; //Variable n funciona para las posiciones en fibo, tribo y como número de discos en Hanoi
    int num, salir = 0; //num recibe el número que nos arrojan fibo y tribo
    while(salir != 1){
        system("cls");
        //Menú del programa
        printf("Por favor, elige la opción que deseas :D\n\n");
        printf("1.- Fibonacci :D\n");
        printf("2.- Tribonacci :D\n");
        printf("3.- Torres de Hannoi :D\n");
        printf("4.- Salir\n");
        scanf("%d", &opcion);
        system("cls");
        //Leemos la opción y dependiendo de lo que quiera el usuario realizamos determinada acción
        switch(opcion){
            case 1:
                printf("Serie de Fibonacci \n\n");
                printf("Indica la posicion que deseas consultar \n");
                scanf("%d", &n); //Leemos la posición que el usuario desea consultar con Fibonacci
                num = fibo(n); //Recibimos el número correspondiente a la posición consultada en la sucesión
                printf("%d\n\n", num);
                system("pause");
                break;
            case 2:
                printf("Serie de Tribonacci \n\n");
                printf("Indica la posicion que deseas consultar \n");
                scanf("%d", &n); //Leemos la posición que el usuario desea consultar con Tribonacci
                num = tribo(n); //Recibimos el número correspondiente a la posición consultada en la sucesión
                printf("%d\n\n", num);
                system("pause");
                break;
            case 3:
                printf("\nCantidad de discos en la torre A: "); //Leemos la cantidad de discos que contendrá la torre de inicio
                scanf("%d",&n);
                fflush(stdin);
                printf("\n\nHistorial de movimientos: \n");
                hanoi(n,ini,aux,fin); //Ejecutamos el algoritmo recursivo de Hanoi
                printf("\n\n");
                system("pause");
                break;
            case 4:
                salir = 1;
                break;

        }
        printf("Gracias por usar nuestro programa.");
    }

    return 0;
}
