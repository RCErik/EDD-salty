/*
	AUTOR: Equipo "Salty boys" (C) Junio 2017
	VERSIÓN: 1.0
	DESCRIPCIÓN: Programa que decodifica el mensaje del usuario para que se pueda leer.
	OBSERVACIONES: No abra el archivo codificado generado, solo con el decodificador. Hace uso de la estructura TAD_Arbol binario y la 		recursividad. Solo basta con ejecutar el porgrama para generar el mensaje decodificado.
	
	COMPILACION: g++ decodificador.c TADArbolBin.c -o "nombre del ejecutable" 
*/

#include<stdio.h>
#include<string.h>
#include<iostream>
#include<fstream>
#include"TADArbolBin.h"
#define PESOBIT(bpos) 1<<bpos
#define CONSULTARBIT(var,bpos) (*(unsigned*)&var & PESOBIT(bpos))?1:0
using namespace std;

elemento*
Obtener_tabla(elemento alfabeto[53])
{
  int contador = 0;	//Contador para el ciclo de los arreglos.
  int aux1;		//Auxiliar que obtiene el numero del archivo.
  int numero[53];	//Arreglo que obtiene el auxiliar numero y pasarlo al elemento.
  char letras[53];	//Arreglo que obtiene el auxiliar de la letra para pasarlo al elemento.
  char aux2;		//Auxiliar que obtiene la letra del archivo.
  FILE *Archivo;		//Hace un archivo de salida.	
  Archivo = fopen ("tabla.txt", "r");		//Abrimos el archivo de texto.
  do
  {
      fscanf(Archivo, "%c", &aux2); 
      letras[contador] = aux2;     
      fscanf(Archivo, "%d", &aux1);
      numero[contador] = aux1;
      contador++;
  }while(fgetc(Archivo) != EOF);
  //Se usa Do-While para obtener los elementos sin que se pierdan datos, con While se pierde el primer dato.

  fclose (Archivo);			//Cerramos el archivo.

  for(contador = 0; contador<53; contador++)
  {
    alfabeto[contador].valor = numero[contador];
    alfabeto[contador].caracter = letras[contador];
  }

  return alfabeto;
}

arbol_bin *
construir_arbol(elemento nodos[130], int datos, arbol_bin *Arbol_f, posicion pos)
{ 
  int contador = 0;	//Contador para ciclos.
  int contador2 = 0;	//Contador para el arreglo que se manda a la recursividad.
  int aux = 0;	//Guarda un entero que se usa para una posicion del arreglo.
  int seguro = 0;	//Entero que sirve de seguro para insertar de regreso de la recursividad.
  elemento auxiliar;
  elemento nodosaux[130];	//Arreglo de los nodos sumados por los elementos basicos.
  elemento menor_1;	//Entero más pequeño de los datos.
  elemento menor_2;	//Segundo entero más pequeño de los datos.
  menor_1.valor = 99999;
  menor_2.valor = 99999;	
  for(contador = 0; contador<datos; contador++)	//Menor 1.
    {
      if(menor_1.valor>nodos[contador].valor && nodos[contador].valor != 0)	//Compara al menor con el elemento siguiente
        {			//Si es menor lo cambia para ser el nuevo menor
          menor_1 = nodos[contador];
          aux = contador;
        }
    }
  nodos[aux].valor = 0;	//Ponemos en 0 al elemento menor para no volverlo a comparar.

  for(contador = 0; contador<datos; contador++)   //Menor 2.
    {
      if(menor_2.valor>nodos[contador].valor && nodos[contador].valor != 0)	//Compara para encontrar al segundo menor
        {
          menor_2 = nodos[contador];	//Cambia el elemento por el nuevo menor.
          aux = contador;
        }
    }
  nodos[aux].valor = 0;	//'Quita' al elemento del arreglo.

  auxiliar.valor=menor_1.valor + menor_2.valor;	//Obtiene el valor de la raiz. 
  for(contador = 0; contador<datos; contador++)	//Nodos del arbol sin arreglar
    {
      if(nodos[contador].valor != 0)	//Pasa los elementos a un arreglo y seguir buscando los menores.
        {
          nodosaux[contador2] = nodos[contador];
          contador2++;
        }
    }

  nodosaux[contador2] = auxiliar;
  datos = contador2 + 1;	//Inserta al nuevo elemento al arreglo porque tambien es un dato.

  if(datos>1)	//Si aun quedan datos por sumar
    {
      Arbol_f = construir_arbol(nodosaux, datos, Arbol_f, pos);	//Recursividad hasta encontrar la suma maxima.
      pos = Search(Arbol_f, auxiliar);	//Encontramos al padre(suma de los menores) para poner a sus hijos.
      NewLeftSon(Arbol_f, pos, menor_1);	//Inserta a su hijo izquierdo.
      NewRightSon(Arbol_f, pos, menor_2);	//Inserta a su hijo derecho.
    }
  else	//Si ya se encontro al valor de la suma total
    {
	  NewRightSon(Arbol_f, pos, auxiliar);		//Inserta al valor maximo de la suma.
	  pos = Search(Arbol_f, auxiliar);	//Obtiene su posicion para insertar a sus hijos.
	  NewLeftSon(Arbol_f, pos, menor_1);	//Inserta a su hijo izquierdo.
	  NewRightSon(Arbol_f, pos, menor_2);	//Inserta a su hijo derecho.
    }
  return Arbol_f;
}

arbol_bin *
referencia_bits(arbol_bin *Arbol_f, posicion pos)	//Funcion que pone la referencia de 0 y 1 a los nodos del arbol y construir el archivo binario.
{
  posicion auxiliar = pos;
  elemento remplazo;
  pos = RightSon(Arbol_f, auxiliar);
  if(pos != NULL)
    {
      remplazo = ReadNode(Arbol_f, pos);
      remplazo.bit = 1;
      ReplaceNode(Arbol_f, pos, remplazo);
      referencia_bits(Arbol_f, pos);
    } 

  pos = auxiliar;
  pos = LeftSon(Arbol_f, auxiliar);
  if(pos != NULL)
    {
      remplazo = ReadNode(Arbol_f, pos);
      remplazo.bit = 0;
      ReplaceNode(Arbol_f, pos, remplazo);
      referencia_bits(Arbol_f, pos);
    } 
  
  return Arbol_f;
}

void InOrden(arbol_bin *a,posicion p)
{
	elemento e;
	if(!NullNode(a,p))
	{
		InOrden(a,LeftSon(a,p));
		e=ReadNode(a,p);
		printf("bit %d\t valor %d cararcter %c\n",e.bit, e.valor, e.caracter);
		InOrden(a,RightSon(a,p));
	}
	return;
}


char*
decodificar(arbol_bin *Arbol_f, posicion pos, char texto[6000], char bytes[751])
{
  int contador = 0;	//Contador de ciclos.
  int largo = 0;	//Longitud del texto.
  int auxbit[8];	//Auxiliar que pasara de bits a numeros y recorrer el arbol.
  unsigned char byte = 0; //Variable de tipo char (byte)
  posicion posaux;		//Posicion auxiliar.
  elemento auxiliar;
  FILE *Archivo;		//Hace un archivo de salida.
	
  Archivo = fopen ("mensaje.txt", "r");		//Abrimos el archivo de texto.
  pos = Root(Arbol_f);		//Nos ponemos en la raiz.
InOrden(Arbol_f, pos);
  posaux = pos;		//Tambien a nuestro seguro.
  do
  {
    byte = fgetc(Archivo); 	//Obtenemos un caracter codificado.
    for (contador = 0; contador < 8; contador++)	//Lo traducimos en un arreglo.
      auxbit[contador] = CONSULTARBIT(byte,contador);
    for (contador = 0; contador < 8; contador++)
    {

      if(auxbit[contador] == 1)		//Si es uno nos movemos a la derecha.
      {
	posaux = pos;
	pos = RightSon(Arbol_f, posaux);
        if (pos == NULL)	//Si la posicion es nula, significa que el seguro tiene la letra.
	{
	  auxiliar = ReadNode(Arbol_f, posaux);	//Leemos el nodo en la posicion.
          texto[largo] = auxiliar.caracter;	//Lo ponemos en el texto.
	  largo++;	
	  pos = Root(Arbol_f);		//Nos ponemos en la raiz
cout<<auxiliar.caracter;
	}
      }
      else if(auxbit[contador] == 0)	//Si es cero nos movemos a la izquierda.
      {
	posaux=pos;
	pos = LeftSon(Arbol_f, posaux);
        if (pos == NULL)		//Si es nula la posicion, el seguro tiene el caracter.
	{
	  auxiliar = ReadNode(Arbol_f, posaux);	//Leemos el nodo en la posición.
          texto[largo] = auxiliar.caracter;	//Ponemos la letra en el texto.
	  largo++;
	  pos = Root(Arbol_f);		//Volvemos a la raiz.
cout<<auxiliar.caracter;
	}
      }		//Asi hasta que acabemos con los caracteres codificados.
    }
  }while(fgetc(Archivo) != EOF);
  //Se usa Do-While para obtener los elementos sin que se pierdan datos, con While se pierde el primer dato.
cout<<largo<<endl;
  fclose (Archivo);			//Cerramos el archivo.

  return texto;
}


int
main (void)
{
  int total = 0;		//Entero total de las frecuencias.
  int contador = 0;		//Contador para ciclos.
  int datos = 0;		//Entero que obtiene la cantidad de datos.
  char texto[6000];		//Arreglo que contiene el texto y sacar la frecuencia de letras.
  char bytes[751];		//Arreglo de bytes para el mensaje codificado.
  elemento alfabeto[53]; 	//Arreglo para las frecuencias de las letras. ASCII 65-90 mayusculas, 97-122 minusculas, 32 espacio.
  elemento nodos[130];		//Arreglo de los nodos sumados por los elementos basicos.
  elemento auxiliar;		//Elemento auxiliar para las funciones de arbol.
  posicion pos;			//Posicion auxiliar para las funciones de arbol.
  arbol_bin Arbol_f;		//Arbol final construido por las frecuencias.
  FILE *mensaje;		//Archivo a modificar.
  FILE *tabla;			//Tabla de frecuencias.

  for(contador = 0; contador<53; contador++)	//Inicializamos nuestro arreglo para las frecuencias.
  {
    alfabeto[contador].valor = 0;
    alfabeto[contador].caracter = '0';
  }
  for(contador = 0; contador<130; contador++)	//Inicializamos el arreglo de nodos limpios.
  {
    nodos[contador].valor = 0;
    nodos[contador].bit = 0;
    nodos[contador].caracter = '0';
  }
  Initialize(&Arbol_f);				//Inicializamos nuestro arbol final.
 
  Obtener_tabla (alfabeto);			//Obtenemos los datos de la tabla.

  for(contador = 0; contador<53; contador++)   //Ciclo for que pasa los nodos del arbol sin arreglar a un nuevo arreglo sin los nodos con valor igual de cero.
    {
      if(alfabeto[contador].caracter != '0')
        {
          nodos[datos] = alfabeto[contador];
          datos++;
        }
    }

  pos = Root(&Arbol_f); //Nos colocamos en la raiz.
  construir_arbol(nodos, datos, &Arbol_f, pos);	//Armamos el arbol.
  pos = Root(&Arbol_f); //Nos colocamos en la raiz de nuevo.
  referencia_bits(&Arbol_f, pos);		//Ponemos las referencias de 0 y 1
  pos = Root(&Arbol_f); //Nos colocamos en la raiz.
  decodificar(&Arbol_f, pos, texto, bytes);	//Decodificamos el mensaje.


return 0;
}
