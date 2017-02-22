#include"TADPila_dim.h"

void 
Initialize (pila *s)
{
  s->tope=NULL;
  return;
}

void 
Push (elemento e, pila *s)
{
  nodo *aux;
  aux = malloc(sizeof(nodo));
  aux->abajo = s->tope;
  s->tope = aux;
  aux->e = e;
  return;
}

elemento 
Pop (pila *s)
{
  elemento r;
  nodo *aux;
  r = s->tope->e;
  aux = s->tope;
  s->tope = s->tope->abajo;
  free(aux);
  return r;
}

boolean 
Empty (pila *s)
{
  if (s->tope == NULL)
    return TRUE;
  return FALSE;
}

int 
Size (pila *s)
{
  nodo *aux;
  int tamaño = 0;
  aux = s->tope;
  while (aux != NULL)
  {
  aux = aux->abajo;
  tamaño ++;
  }
  return tamaño;
}

elemento 
Top (pila *s)
{
  return s->tope->e;
}

void 
Destroy (pila *s)
{
  nodo *aux;
  while (s->tope != NULL)
  {
    aux = s->tope->abajo;
    free(s->tope);
    s->tope = aux;
  }
  return;
}
