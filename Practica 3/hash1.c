#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<iostream>
#include<fstream>
#include<locale.h>
/*
Función Hash que cuenta los números de caracteres de la palabra, después ese número le suma el número ASCII del tercer carácter del final,
luego lo multiplica con la suma de Pi con el ASCII de la primera letra, el resultado lo divide entre el numero Euler, 
finalmente hace modulo a la clave para que entre en el rango de la tabla.
*/
int
Clavehash (char aux[50])
{
  int largo = 0;
  int cont = 0;
  float clave = 0;
  largo = strlen (aux);
  clave = (largo + (int) aux[largo - 3]) * (3.1415 + (int) aux[1]);
  clave = (clave + (int) aux[largo]) / 2.7182;
  clave = (int) clave % 83;
  return (int) clave;
}
