#include <iostream>
#include <fstream>
#include <conio.h>
#include <locale.h>

using namespace std;
 
int main()
{
    setlocale(LC_ALL, "Spanish");   //Cambia la localidad total al Español y pueda reconocer acentos y la ñ.
    ifstream Diccionario;           //Hace un archivo de salida.
    string linea;                   //Una cadena auxiliar para recibir las lineas de texto con getline
    
    Diccionario.open("Lunfardo.txt");   //Abre el diccionario para su uso
    while(!Diccionario.eof())   // mientras no se terminen de las lineas del archivo sigue leyendo
    { 
        getline(Diccionario,linea); //toma la linea del archivo de entrada
        cout << linea << endl;      //imprime la linea con cout, la cadena es linea y pasa al siguiente parrafo (\n) con endl
        getch();                    //Cambiar por hash y funcion separar cadena
    }
    Diccionario.close();            //Cierra el diccionario para no causar problemas
    getch();
    return 0;
}
