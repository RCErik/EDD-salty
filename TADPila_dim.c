#include"TADPila_dim.h"
void initialize (pila *s)
{
s->tope=NULL;
return;
}

void Push (elemento e, pila *s)
{
nodo *aux;
aux = malloc(sizeof(nodo));
aux->abajo = s->tope;
s->tope = aux;
aux->e = e;
return;
}

elemento Pop 
