//Funcion que evalúa la expresión final en posfijo
float evaluar(pila *s){
  float valor;
  float valor_letra[27];
  //Inicializamos el arreglo de valores en -1
  for(int i = 0; i < 27; i++)
    valor_letra[i] = -1;
  printf("Indique el valor de la letra:\n");
  scanf("%f",&valor); 
  //Solicitamos los valores de las letras encontradas en la expresion
  verificar_valor_disponible(valor, convertir_ASCII(caracter), valor_letra);
};


int convertir_ASCII(char letra){
  int valor_ASCII;
  valor_ASCII = (int)letra - 64;
  return valor_ASCII;
}

void verificar_valor_disponible(float numero, int posicion, float valores[27]){
  if(valores[posicion] != -1)
    valores[posicion] = numero;
  return;
}
