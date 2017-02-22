#define TRUE 0
#define FALSE 1
#define MAX_ELEMENT 10000

typedef char boolean;

typedef struct elemento
{
    int num; //numero
    char let; //letra
    float dec; //decimal
}elemento;

typedef struct pila
{
    elemento A[MAX_ELEMENT];
    int tope;
}pila;

void Initialize (pila *s);
void Destroy (pila *s);
void Push (elemento e, pila *s);
elemento Pop (pila *s);
int Size (pila *s);
boolean Empty (pila *s);
elemento Top (pila *s);
