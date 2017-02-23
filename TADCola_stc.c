#include "TADCola_stc.h"

void Initialize (cola *c)
{
  c->frente = -1;
  c->final = -1;
  return;
}

void Queue (elemento e, cola *c)
{
c->final++;
c->A[c->final] = e;
if (c->frente == -1)

}
