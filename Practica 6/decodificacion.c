#include <stdio.h>
#include <stdlib.h>
 
char* obtener_codigo()
{
 	FILE *archivo;
 	
 	char caracteres[6000];
 	
 	archivo = fopen("mensaje.txt","r");
 	
 	if (archivo == NULL)
 		exit(1);

 	while (feof(archivo) == 0)
 	{
 		fgets(caracteres,6000,archivo);
 	}
        system("PAUSE");

        fclose(archivo);
    return caracteres;
}

char* decodificar(arbol_bin *a, char caracteres[6000]){
	int i = 0, j = 0;
	char mensaje[5000];
	posicion p, letra;
	elemento e;
	nodo aux, izquierdo, derecho;
	p = Root(a);
	izquierdo = p -> izq;
	derecho = p -> der;
	while(caracteres[i] != '\0'){
		if(caracteres[i] == 0){
			aux = izquierdo;
			letra = &izquierdo;
		}
		if(caracteres[i] == 1){
			aux = derecho;
			letra = &derecho;
		}	
		if((aux -> der) == NULL && (aux -> izq) == NULL){
			e = ReadNode(a, letra);
			mensaje[j] = e.c;
			j++;
		}
		izquierdo = aux -> izq;
		derecho = aux -> der;
		i++;
	}
	return mensaje;
}
