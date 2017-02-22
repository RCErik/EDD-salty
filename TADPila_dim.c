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

elemento Pop (pila *s)
{
elemento r;
nodo *aux;
r = s->tope->e;
aux = s->tope;
s->tope = s->tope->abajo;
free(aux);
return r;
}

boolean Empty (pila *s)
{
if (s->tope == NULL)
  return TRUE;
return FALSE;
}

int Size
