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

void Initialize (cola *c); //Inicializa la cola
void Queue (elemento e, cola *c);  //Mete un elemento al final de la cola
elemento Dequeue (cola *c);  //Saca al primer elemento de la cola
boolean Empty (cola *c);  //Verifica si la cola esta vacia o no
int Size (cola *c);  //Muestra el numero de elementos de la cola
elemento Front (cola *c);  //Muestra al primer elemento de la cola
elemento Final (cola *c);  //Muestra al ultimo elemento de la cola
elemento Element (int n, cola *c);  //Muestra el elemento que el usuario desea conocer
void Destroy (cola *c);  //Destruye la cola

