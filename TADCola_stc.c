#include "TADCola_stc.h"

void 
Initialize (cola *c)
{
  c->frente = -1;
  c->final = -1;
  return;
}

void
Queue (elemento e, cola *c)
{
  c->final++;
  c->A[c->final] = e;
  if (c->frente == -1)
    c->frente++;
  return;
}

elemento 
Dequeue (cola *c)
{
  int i;
  elemento r;
  r = c->A[c->frente];
  for (i=0; i<c->final; i++)
  {
    c->A[i] = c->A[i + 1];
  }
  c->final--;
  if (c->final == -1)
    c->frente = -1;
  return r;
}

boolean 
Empty (cola *c)
{
  boolean r = TRUE;
  if (c->frente != -1)
    r=FALSE;
  return r;
}

int 
Size (cola *c)
{
  return c->final + 1;
}

elemento 
Front (cola *c)
{
  return c->A[c->frente];
}

elemento 
Final (cola *c)
{
  return c->A[c->final];
}

elemento 
Element (int n, cola *c)
{
  return c->A[c->n-1];
}

void 
Destroy (cola *c)
{
  Initialize (c);
  return;
}
