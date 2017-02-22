#define TRUE 0
#define FALSE 1
#define MAX_ELEMENT 10000

typedef char boolean;

typedef struct
{
    int num;
}elemento;

typedef struct
{
    elemento A[MAX_ELEMENT];
    int tope;
}pila;

int Size(pila *s);
boolean Empty(pila *s);
void Initialize(pila *s);
void Destroy(pila *s);
void Push(elemento e, pila *s);
elemento Pop(pila *s);

