#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int convertirASCII(char c){
	return (int)c;
}

int main(void){
	int caracteres = 0, random;
	char buffer[400];
	char palabra[30], definicion[370];
	int suma = 0, i, resta, mult, clave, aux, potencia, tam = 100;
	//elemento e;
	fgets(palabra, 30, stdin);
	printf("\n");
	caracteres = strlen(palabra);
	resta = (int)palabra[0] - (int)palabra[caracteres - 1];
	if(resta < 0)
		resta = resta * -1;
	mult = resta * caracteres;
	for(i = 0; i < caracteres; i++)
		suma = suma + (int)palabra[i];
	random = rand() % 40;
	aux = ((suma * mult) / resta) / (rand() % suma);
	random = rand() % 5;
	potencia = pow(aux, random);
	clave = potencia % tam;
	printf("Caracteres %d \n", caracteres - 1);
	printf("Resta %d \n", resta);
	printf("Mult %d \n", mult);
	printf("suma %d \n", suma);
	printf("random %d \n", random);
	printf("aux %d \n", aux);
	printf("potencia %d \n", potencia);
	printf("clave %d \n", clave);
	return 0;
}

int hashCharly(char palabra[50]){
	int caracteres = 0, random;
	int suma = 0, i, resta, mult, clave, aux, potencia, tam = 100;
	caracteres = strlen(palabra);
	resta = (int)palabra[0] - (int)palabra[caracteres - 1];
	if(resta < 0)
		resta = resta * -1;
	mult = resta * caracteres;
	for(i = 0; i < caracteres; i++)
		suma = suma + (int)palabra[i];
	random = rand() % 40;
	aux = ((suma * mult) / resta) / (rand() % suma);
	random = rand() % 5;
	potencia = pow(aux, random);
	clave = potencia % tam;
	printf("clave %d \n", clave);
	return clave;	
}

int main(void){
	int opcion = 0;
	printf("Diccionario del conocimiento completo del universo\n\n");
	printf("1.- Cargar un archivo de definiciones\n");
	printf("2.- Agregar una palabra y su definicion\n");
	printf("3.- Buscar una palabra y ver su definicion\n");
	printf("4.- Modificar una definicion\n");
	printf("5.- Eliminar una palabra\n");
	printf("6.- Salir\n\n");
	scanf("%d", &opcion);
	switch(opcion){
		case 1:
			menuArchivos();
			break;
		case 2:
			//Inciso 2 de la practica
			break;
		case 3:
			//Inciso 3 de la practica
			break;
		case 4:
			//Inciso 4 de la practica
			break;
		case 5:
			//Inciso 5 de la practica
			break;
		case 6:
			exit(0);
			break;
	}
}

void menuArchivos(){
	int opcion = 0;
	ifstream Diccionario;
	printf("Elija el archivo que desea abrir\n\n");
	printf("1.- Lunfardo\n");
	printf("2.- Glosario BIOQUANTUM\n");
	scanf("%d", &opcion);
	switch(opcion){
		case 1:
			
			break;
		case 2:
			//Inciso 2 de la practica
			break;
	return;
}
