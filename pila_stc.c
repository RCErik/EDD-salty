#include "pila_stc.h"

int Size(pila *s){
    return s -> tope + 1;
}

boolean Empty(pila *s){
    boolean r;
    if(s -> tope >= 0)
        r = FALSE;
    else
        r = TRUE;
    return r;
}

void Initialize(pila *s){
    s -> tope = -1;
    return;
}

void Destroy(pila *s){
    Initialize(s);
    return;
}

void Push(elemento e, pila *s){
    s -> tope++;
    s -> A[s -> tope] = e;
    return;
}

elemento Pop(pila *s){
    elemento r;
    r = s -> A[s -> tope];
    s -> tope--;
    return r;
}

