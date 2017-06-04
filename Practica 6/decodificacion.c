#include <stdio.h>
#include <stdlib.h>
 //Función que lee lo que tenemos en el archivo de texto que nos han enviado
char* obtener_codigo()
{
 	FILE *archivo; //Tipo de apuntador que nos va a permitir leer el archivo
 	
 	char caracteres[6000]; //Arreglo de datos de tipo char para almacenar los caracteres del archivo
 	
 	archivo = fopen("mensaje.txt","r"); //Abrimos el archivo y lo amacenamos en al apuntador de tipo FILE
 	//Si el vacío se encuentra vacío cerramos el programa
 	if (archivo == NULL)
 		exit(1);
	//Mientras el indicador del fichero se encuentre activado obtendremos los caracteres del archivo y los almacenados en el arreglo
 	while (feof(archivo) == 0)
 	{
 		fgets(caracteres,6000,archivo);
 	}
        system("PAUSE");
	//Cerramos el archivo
        fclose(archivo);
    return caracteres;
}
//Función de decodificación que devuelve un apuntador a char con el mensaje decodificado
//Recibe un arbol binario y el arreglo de caracteres obtenido de la función anterior
char* decodificar(arbol_bin *a, char caracteres[6000]){
	int i = 0, j = 0; //Tipos de dato entero que funcionarán como contadores
	char mensaje[5000]; //Arreglo de tipo char en donde pondremos el mensaje decodificado
	posicion p, letra; //Declaramos dos variables para recibir posiciones
	elemento e; //Variable de tipo elemento
	nodo aux, izquierdo, derecho; //Declaramos tres nodos, un auxiliar, izquierdo y derecho
	p = Root(a); //Asignamos a p la posición de la raíz de nuestro arbol binario
	izquierdo = p -> izq; //Asignamos al nodo izquierdo el nodo izquierdo de la raíz del árbol
	derecho = p -> der; //Asignamos al nodo derecho el nodo derecho de la raíz del árbol
	//Mientras el arreglo de caracteres no encuentre al caracter del fin de cadena
	while(caracteres[i] != '\0'){
		//Si el caracter que encontramos es un cero pasa lo siguiente
		if(caracteres[i] == '0'){
			//Asignamos al nodo auxiliar el izquierdo del nodo anterior
			aux = izquierdo;
			//Asignamos a la posición de letra la posición del nodo izquierdo anterior
			letra = &aux;
		}
		//Si el caracter encontrado corresponde a un uno
		if(caracteres[i] == '1'){
			//Asignamos al nodo auxiliar el derecho del nodo anterior
			aux = derecho;
			//Asignamos a la posición letra la posición del nodo derecho anterior
			letra = &aux;
		}	
		//Si nuestro nuevo nodo auxiliar no tiene más hijos llegamos a una de las hojas del arbol
		if((aux -> der) == NULL && (aux -> izq) == NULL){
			//Leemos lo que tiene el nodo en la posición del auxiliar
			e = ReadNode(a, letra);
			//Asignamos el caracter dentro del nodo a nuestro arreglo de mensaje decodificado
			mensaje[j] = e.c;
			//Aumentamos el contador para el mensaje
			j++;
		}
		//Reasignamos el nodo izquierdo y derecho a los hijos del auxiliar
		izquierdo = aux -> izq;
		derecho = aux -> der;
		i++;
	}
	//Devolvemos el mensaje decodificado
	return mensaje;
}
