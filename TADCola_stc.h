#define TRUE 1
#define FALSE 0
#define MAX_ELEMENT 1000

typedef char boolean;

typedef struct elemento
{
  int num;  //numero
  char let;  //letra
  float dec;  //decimal
}

typedef struct cola
{
  int frente;
  int final;
  elemento A[MAX_ELEMENT];
}

void Initialize (cola *c);
void Queue (elemento e, cola *c);
elemento Dequeue (cola *c);
boolean Empty (cola *c);
int Size (cola *c);
elemento Front (cola *c);
elemento Final (cola *c);
elemento Element (int n, cola *c);
void Destroy (cola *c);

