#include<stdio.h>
#include<string.h>
#include<iostream>
#include<fstream>
#include"TADArbolBin.h"

using namespace std;

elemento *
Frecuencias (char texto[5000], elemento alfabeto[53])
{
  int contador = 0;
  int largo = 0;
  int letra;
  largo = strlen(texto);
  for(contador = 0; contador<largo; contador++)	//Ciclo que saca la frecuencia de las letras.
  {
    letra = (int)texto[contador];	//Obtiene el valor ASCII de la letra en turno.
    if(letra>64 && letra<91)		//Si esta en el rango de las mayusculas (A-Z).
      {
        alfabeto[letra - 65].valor++;		//Suma una unidad a la frecuencia correspondiente (0-25).
        alfabeto[letra - 65].caracter = (char)letra;	//Asignamos la letra correspondiente al arreglo.
      }
    else if (letra>96 && letra<123)	//Si esta en el rango de minusculas (a-z).
      {
        alfabeto[letra - 97 + 26].valor++;	//Suma una unidad a la frecuencia correspondiente (26-51), se suman 26 para estar en el rango correcto del arreglo.
        alfabeto[letra - 97 + 26].caracter = (char)letra;	//Asignamos la letra correspondiente al arreglo.
      }
    else if (letra == 32)	//Si es el espacio.
      {
        alfabeto[52].valor++;		//Suma una unidad a su frecuencia (52).
        alfabeto[52].caracter = (char)letra;	//Asignamos el espacio al arreglo.
      }
  }

  return alfabeto;
}

void InOrden(arbol_bin *a,posicion p)
{
	elemento e;
	if(!NullNode(a,p))
	{
		InOrden(a,LeftSon(a,p));
		e=ReadNode(a,p);
		printf("bit %d\t valor %d\n",e.bit, e.valor);
		InOrden(a,RightSon(a,p));
	}
	return;
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

int
main (void)
{
  int total = 0;		//Entero total de las frecuencias.
  int contador = 0;		//Contador para ciclos.
  int datos = 0;		//Entero que obtiene la cantidad de datos.
  char texto[5000];		//Arreglo que contiene el texto y sacar la frecuencia de letras.
  elemento alfabeto[53]; 	//Arreglo para las frecuencias de las letras. ASCII 65-90 mayusculas, 97-122 minusculas, 32 espacio.
  elemento nodos[130];		//Arreglo de los nodos sumados por los elementos basicos.
  elemento auxiliar;		//Elemento auxiliar para las funciones de arbol.
  posicion pos;			//Posicion auxiliar para las funciones de arbol.
  arbol_bin Arbol_f;		//Arbol final construido por las frecuencias.
  ifstream Archivo;		//Hace un archivo de salida.
  string buffer;		//Una cadena auxiliar para recibir las lineas de texto con getline.

  for(contador = 0; contador<53; contador++)	//Inicializamos nuestro arreglo para las frecuencias.
  {
    alfabeto[contador].valor = 0;
    alfabeto[contador].caracter = '0';
  }
  for(contador = 0; contador<130; contador++)
    nodos[contador].valor = 0;
  Initialize(&Arbol_f);				//Inicializamos nuestro arbol final.

  Archivo.open ("ejemplo.txt");		//Abrimos el archivo de texto.
  getline (Archivo, buffer);		//Obtenemos el texto.
  strcpy (texto, buffer.c_str ());	//Lo copiamos al arreglo y sacar las frecuencias.
  Archivo.close ();			//Cerramos el archivo.

  Frecuencias(texto, alfabeto);		//Obtenemos los datos del arreglo.

  for(contador = 0; contador<53; contador++)   //Ciclo for que pasa los nodos del arbol sin arreglar a un nuevo arreglo sin los nodos con valor igual de cero.
    {
      if(alfabeto[contador].caracter != '0')
        {
          nodos[datos] = alfabeto[contador];
          datos++;
        }
    }

  construir_arbol(nodos, datos, &Arbol_f, pos);	//Construimos a nuestro arbol mediante la recursividad.
  pos=Root(&Arbol_f);
  referencia_bits(&Arbol_f, pos);
  InOrden(&Arbol_f,pos);

return 0;
}
