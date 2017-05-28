#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<iostream>
#include<fstream>
#include<locale.h>
/*
Función Hash que cuenta los números de caracteres de la palabra, después ese número lo multiplica por la constante 1.686229 
y con el entero ASCII de la antepenúltima letra, luego hace la suma del entero ASCII de la 3 letra antes de que acabe la palabra 
y la segunda letra, el resultado de la suma y la multiplicación anterior les aplica la operación de multiplicación, 
finalmente aplica módulo 83 al resultado para generar la clave. En caso de que la clave sea menor a 0 se multiplica por -1 
y evitar errores en el programa.
*/
int
Clavehash (char palabra[50])
{
    int caracteres = 0, clave, tam = 83;
    float suma, final, aux;
    caracteres = strlen(palabra);
    aux = caracteres * 1.686229 * (int) palabra[caracteres - 2];
    suma = (int) palabra[caracteres - 3] + (int) palabra[2];
    final = aux * suma;
    clave = (int) final % tam;
    if (clave < 0)
        clave = clave * -1;
    return clave;	
}
