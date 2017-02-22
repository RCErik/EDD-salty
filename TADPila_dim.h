#define TRUE 1
#define FALSE 0
#include <stdlib.h>

typedef char boolean;

typedef struct elemento
{
  int num; //numero
  char let; //letra
  float dec; //decimal
}elemento;

typedef struct nodo
{
  elemento e;
  struct nodo *abajo;
}nodo;

typedef struct pila
{
  nodo *tope;
}pila;

void Initialize (pila *s);  //Inicializa una pila
void Push (elemento e, pila *s); //Mete un elemento a la pila
elemento Pop (pila *s); //Saca el elemento tope de la pila
boolean Empty (pila *s); //Verifica el estado de la pila
int Size (pila *s); //Muestra el tamaño de la pila
elemento Top (pila *s); //Muestra el elemento tope de la pila
void Destroy (pila *s); //Destruye la pila

