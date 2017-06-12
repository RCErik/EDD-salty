#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct nodo 
{
  struct nodo *hijo_d;
   struct nodo *hijo_i;
   int valor;
   int elem1;
   int elem2;
   int fase;
   int balance;
   char nombre[15];
   int habil1;
   int habil2;
   int habil3;
 };
struct nodo_l 
{
  struct nodo_l *sig;
   int valor;
   char nombre[15];
   int alma1;
   int alma2;
   int alma3;
   int alma4;
   int alma5;
 };
struct nodo *inicializar (void);
struct nodo_l *inicializar_l (void);
void insertar (struct nodo *elem, struct nodo *node);
void insertar_l (struct nodo_l *elem, struct nodo_l *node);
void preorden (struct nodo *node);
int altura (struct nodo *node);
int diferencia (struct nodo *node);
struct nodo *rot_iz_s (struct nodo *node);
struct nodo *rot_de_s (struct nodo *node);
struct nodo *rot_iz_d (struct nodo *node);
struct nodo *rot_de_d (struct nodo *node);
struct nodo *balancear (struct nodo *node);
struct nodo *buscar (int n, struct nodo *node);
struct nodo_l *buscar_l (int n, struct nodo_l *node);
struct nodo *cargar (struct nodo *node, int m);
struct nodo_l *cargar_l (struct nodo_l *node);
int 
main (void) 
{
  int i = 0;
  int a = 0;
  int b = 0;
  int max = 0;
  int repetir = 0;
  char elem1[6] = "";
  char elem2[6] = "";
  char balance[6] = "";
  char habil1[20] = "";
  char habil2[20] = "";
  char habil3[20] = "";
  char alma[20] = "";
  struct nodo *aux = NULL;
  struct nodo_l *aux2 = NULL;
  struct nodo *arbol = NULL;
  struct nodo *almas = NULL;
  struct nodo *habil = NULL;
  struct nodo_l *rivales = NULL;
  srand (time (NULL));
  arbol = inicializar ();
  habil = inicializar ();
  almas = inicializar ();
  rivales = inicializar_l ();
  habil = cargar (habil, 0);
  almas = cargar (almas, 1);
  rivales = cargar_l (rivales);
  repetir = 1;
  while (repetir == 1)
    {
      printf ("Simulacion de base de datos de Soulbound\n");
      printf ("Seleccione opcion para buscar\n1. Rival\n2. Alma\n");
      scanf ("%d", &b);
      switch (b)
	{
	case 1:
	  printf ("Escribe Rival a buscar:\n");
	  scanf ("%d", &b);
	  aux2 = buscar_l (b, rivales);
	  printf ("DATOS\nNombre:%s\n", aux2->nombre);
	  strcpy (alma, buscar (aux2->alma1, almas)->nombre);
	  printf ("Alma1:%s\n", alma);
	  strcpy (alma, buscar (aux2->alma2, almas)->nombre);
	  printf ("Alma2:%s\n", alma);
	  strcpy (alma, buscar (aux2->alma3, almas)->nombre);
	  printf ("Alma3:%s\n", alma);
	  strcpy (alma, buscar (aux2->alma4, almas)->nombre);
	  printf ("Alma4:%s\n", alma);
	  strcpy (alma, buscar (aux2->alma5, almas)->nombre);
	  printf ("Alma5:%s\n", alma);
	  break;
	case 2:
	  printf ("Escribe Alma a buscar:\n");
	  scanf ("%d", &b);
	  aux = buscar (b, almas);
	  if (aux->valor != -1)
	    {
	      switch (aux->elem1)
		{
		case 1:
		  strcpy (elem1, "Agua");
		 break;
		case 2:
		  strcpy (elem1, "Fuego");
		  break;
		case 3:
		  strcpy (elem1, "Tierra");
		  break;
		case 4:
		  strcpy (elem1, "Aire");
		  break;
		case 5:
		  strcpy (elem1, "Luz");
		  break;
		case 6:
		  strcpy (elem1, "Oscuro");
		  break;
		}
	      switch (aux->elem2)
		{
		case 1:
		  strcpy (elem2, "Agua");
		  break;
		case 2:
		  strcpy (elem2, "Fuego");
		  break;
		case 3:
		   strcpy (elem2, "Tierra");
		   break;
		 case 4:
		   strcpy (elem2, "Aire");
		   break;
		 case 5:
		   strcpy (elem2, "Luz");
		   break;
		 case 6:
		   strcpy (elem2, "Oscuro");
		   break;
		 }
	       switch (aux->balance)
		
		{
		 case 0:
		   strcpy (balance, "Mixto");
		   break;
		 case 1:
		   strcpy (balance, "Magico");
		   break;
		 case 2:
		   strcpy (balance, "Fisico");
		   break;
		 }
	       printf 
		("\nDATOS\nNombre:%s\nElemento1:%s\nElemento2:%s\nFase:%d\nBalance:%s\nHabilidad 1:",
		 aux->nombre, elem1, elem2, aux->fase, balance);
	       strcpy (habil1, buscar (aux->habil1, habil)->nombre);
	       printf ("%s\n", habil1);
	       strcpy (habil2, buscar (aux->habil2, habil)->nombre);
	       if (buscar (aux->habil2, habil)->valor != -1)
		
		{
		   printf ("Habilidad 2:%s\n", habil2);
		 }
	       strcpy (habil3, buscar (aux->habil3, habil)->nombre);
	       if (buscar (aux->habil3, habil)->valor != -1)
		
		{
		   printf ("Habilidad 3:%s\n", habil3);
		 }
	     }
	  
	  else
	    
	    {
	       printf ("\nEl elemento no existe\n");
	     }
	   break;
	 default:
	   printf ("Opcion incorrecta, intente de nuevo");
	   break;
	 }
       printf ("\n\n");
       printf ("Desea repetir el programa?\n0.No\n1.Si");
       scanf ("%d", &repetir);
     }
   getch ();
   return 0;
 }

    struct nodo *
inicializar (void) 
{
   struct nodo *node;
   node = malloc (sizeof (struct nodo));
   node->hijo_d = NULL;
   node->hijo_i = NULL;
   node->valor = 0;
   node->elem1 = 0;
   node->elem2 = 0;
   node->fase = 0;
   node->balance = 0;
   strcpy (node->nombre, "");
   node->habil1 = 0;
   node->habil2 = 0;
   node->habil3 = 0;
   return node;
 }

   struct nodo_l *
inicializar_l (void) 
{
   struct nodo_l *node = NULL;
   node = malloc (sizeof (struct nodo_l));
   node->valor = 0;
   node->sig = NULL;
   int alma1 = 0;
   int alma2 = 0;
   int alma3 = 0;
   int alma4 = 0;
   int alma5 = 0;
   strcpy (node->nombre, "");
   return node;
 }

   void 
insertar (struct nodo *nuevo, struct nodo *node) 
{
   if (node != NULL)
     if (nuevo->valor < node->valor)
      
      {
	 if (node->hijo_i != NULL)
	  
	  {
	     insertar (nuevo, node->hijo_i);
	   }
	
	else
	  
	  {
	     node->hijo_i = inicializar ();
	     node->hijo_i = nuevo;
	   }
       }
   if (nuevo->valor > node->valor)
    
    {
       if (node->hijo_d != NULL)
	
	{
	   insertar (nuevo, node->hijo_d);
	 }
      
      else
	
	{
	   node->hijo_d = inicializar ();
	   node->hijo_d = nuevo;
	 }
     }
 }

   void 
insertar_l (struct nodo_l *elem, struct nodo_l *node) 
{
   if (node != NULL)
    
    {
       if (node->sig != NULL)
	
	{
	   insertar_l (elem, node->sig);
	 }
      
      else
	
	{
	   node->sig = inicializar_l ();
	   node->sig = elem;
	 }
     }
 }

   void 
preorden (struct nodo *node) 
{
   printf ("%d  ", node->valor);
   if (node->hijo_i != NULL)
     
    {
       preorden (node->hijo_i);
     }
   if (node->hijo_d != NULL)
     
    {
       preorden (node->hijo_d);
     }
 }

   int 
altura (struct nodo *node) 
{
   if (node == NULL)
     return 0;
   
  else
    
    {
       int a = 0;
       int b = 0;
       if (node == NULL)
	 return 0;
       if (node->hijo_i != NULL)
	 a = altura (node->hijo_i);
       if (node->hijo_d != NULL)
	 b = altura (node->hijo_d);
       if (a > b)
	 
	{
	   return a + 1;
	 }
       
      else
	 
	{
	   return b + 1;
	 }
     }
 }

   struct nodo *
rot_iz_s (struct nodo *node) 
{
   struct nodo *a = node;
   struct nodo *b = a->hijo_i;
    a->hijo_i = b->hijo_d;
   b->hijo_d = a;
    return b;
 }

   struct nodo *
rot_de_s (struct nodo *node) 
{
   struct nodo *a = node;
   struct nodo *b = a->hijo_d;
    a->hijo_d = b->hijo_i;
   b->hijo_i = a;
    return b;
 }

   struct nodo *
rot_iz_d (struct nodo *node) 
{
   struct nodo *a = node;
   struct nodo *b = a->hijo_i;
   struct nodo *c = b->hijo_d;
    a->hijo_i = c->hijo_d;
   b->hijo_d = c->hijo_i;
   c->hijo_i = b;
   c->hijo_d = a;
    return c;
 }

   struct nodo *
rot_de_d (struct nodo *node) 
{
   struct nodo *a = node;
   struct nodo *b = a->hijo_d;
   struct nodo *c = b->hijo_i;
    a->hijo_d = c->hijo_i;
   b->hijo_i = c->hijo_d;
   c->hijo_d = b;
   c->hijo_i = a;
    return c;
  }

   int 
diferencia (struct nodo *node) 
{
   int a = 0;
   if (node == NULL)
    
    {
       return 0;
     }
   if (node->hijo_i != NULL)
    
    {
       a = a + altura (node->hijo_i);
     }
   if (node->hijo_d != NULL)
    
    {
       a = a - altura (node->hijo_d);
     }
   return a;
 }

   struct nodo *
balancear (struct nodo *node) 
{
   struct nodo *aux = node;
   int a = 0;
   a = diferencia (node);
   if (node->hijo_i != NULL)
    
    {
       node->hijo_i = balancear (node->hijo_i);
     }
   if (node->hijo_d != NULL)
    
    {
       node->hijo_d = balancear (node->hijo_d);
     }
   if (diferencia (node) < -1)
    
    {
       if (diferencia (node->hijo_d) >= 1)
	
	{
	   aux = rot_de_d (aux);
	 }
      
      else
	
	{
	   aux = rot_de_s (aux);
	 }
     }
   if (diferencia (node) > 1)
    
    {
       if (diferencia (node->hijo_i) >= 1)
	
	{
	   aux = rot_iz_s (aux);
	 }
      
      else
	
	{
	   aux = rot_iz_d (aux);
	 }
     }
   return aux;
 }

   struct nodo *
buscar (int n, struct nodo *node) 
{
   struct nodo *res = NULL;
   if (n == node->valor)
    
    {
       res = node;
     }
   if (n > node->valor)
    
    {
       if (node->hijo_d != NULL)
	
	{
	   res = buscar (n, node->hijo_d);
	 }
      
      else
	
	{
	   res = inicializar ();
	   res->valor = -1;
	 }
     }
   if (n < node->valor)
    
    {
       if (node->hijo_i != NULL)
	
	{
	   res = buscar (n, node->hijo_i);
	 }
      
      else
	
	{
	   res = inicializar ();
	   res->valor = -1;
	 }
     }
   return res;
 }

    struct nodo_l *
buscar_l (int n, struct nodo_l *node) 
{
   struct nodo_l *res = NULL;
   res = inicializar_l ();
   if (n == node->valor)
    
    {
       res = node;
     }
   if (n > node->valor)
    
    {
       if (node->sig != NULL)
	
	{
	   res = buscar_l (n, node->sig);
	 }
      
      else
	
	{
	   res->valor = -1;
	 }
     }
   return res;
 }

   struct nodo *
cargar (struct nodo *node, int m) 
{
   struct nodo *aux = NULL;
   int i = 0;
   int n = 0;
   int a1 = 0;
   int a2 = 0;
   int a3 = 0;
   if (m == 1)
     
    {
       node->valor = 1000;
       node->elem1 = 0;
       node->elem2 = 0;
       node->fase = 0;
       node->balance = 0;
       strcpy (node->nombre, "DEFAULT");
       node->habil1 = 1;
       node->habil2 = 0;
       node->habil3 = 0;
       a1 = 1;
       while (a1 < 7)
	
	{
	   a2 = 1;
	   while (a2 < 7)
	    
	    {
	       a3 = 1;
	       while (a3 < 4)
		
		{
		   switch (a3)
		    
		    {
		     case 1:
		       aux = inicializar ();
		       aux->valor = a1 * 1000 + a2 * 100 + a3 * 10;
		       aux->elem1 = a1;
		       aux->elem2 = a2;
		       aux->fase = a3;
		       aux->balance = 0;
		       snprintf (aux->nombre, 15, "%s-%d", "Default",
				   aux->valor);
		       aux->habil1 = a1 * 100 + 1;
		       insertar (aux, node);
		       node = balancear (node);
		       break;
		     case 2:
		       for (i = 1; i < 3; i = i + 1)
			
			{
			   aux = inicializar ();
			   aux->valor = a1 * 1000 + a2 * 100 + a3 * 10 + i;
			   aux->elem1 = a1;
			   aux->elem2 = a2;
			   aux->fase = a3;
			   aux->balance = i;
			   snprintf (aux->nombre, 15, "%s-%d", "Default",
				       aux->valor);
			   aux->habil1 = a1 * 100 + 1;
			   aux->habil2 = a2 * 100 + 2;
			   insertar (aux, node);
			   node = balancear (node);
			 }
		       break;
		     case 3:
		       for (i = 0; i < 3; i = i + 1)
			
			{
			   aux = inicializar ();
			   aux->valor = a1 * 1000 + a2 * 100 + a3 * 10 + i;
			   aux->elem1 = a1;
			   aux->elem2 = a2;
			   aux->fase = a3;
			   aux->balance = i;
			   snprintf (aux->nombre, 15, "%s-%d", "Default",
				       aux->valor);
			   aux->habil1 = a1 * 100 + 1;
			   aux->habil2 = a2 * 100 + 2;
			   aux->habil3 = a1 * 100 + 3;
			   insertar (aux, node);
			   node = balancear (node);
			 }
		       break;
		     }
		   a3 = a3 + 1;
		 }
	       a2 = a2 + 1;
	     }
	   a1 = a1 + 1;
	 }
     }
  
  else
    
    {
       node->valor = 100;
       node->elem1 = 1;
       node->fase = 1;
       strcpy (node->nombre, "DEFAULT");
       a1 = 1;
       while (a1 < 7)
	 
	{
	   a2 = 1;
	   while (a2 < 4)
	    
	    {
	       aux = inicializar ();
	       aux->valor = a1 * 100 + a2;
	       aux->elem1 = a1;
	       aux->fase = a2;
	       snprintf (aux->nombre, 15, "%s-%d", "Default", aux->valor);
	       a2 = a2 + 1;
	       insertar (aux, node);
	       node = balancear (node);
	     }
	   a1 = a1 + 1;
	 }
      }
   return node;
 }

    struct nodo_l *
cargar_l (struct nodo_l *node) 
{
   struct nodo_l *aux = NULL;
   int a = 0;
   node->valor = 0;
   strcpy (node->nombre, "Default");
   node->alma1 = 0;
   node->alma2 = 0;
   node->alma3 = 0;
   node->alma4 = 0;
   node->alma5 = 0;
   while (a < 25)
    
    {
       aux = inicializar_l ();
       aux->valor = a;
       snprintf (aux->nombre, 15, "%s-%d", "Default", aux->valor);
       aux->alma1 = generar ();
       aux->alma2 = generar ();
       aux->alma3 = generar ();
       aux->alma4 = generar ();
       aux->alma5 = generar ();
       insertar_l (aux, node);
       a = a + 1;
     }
   return node;
 }

   int 
generar (void) 
{
   int n = 0;
   int a = 0;
   a = rand () % 6 + 1;
   n = a * 1000;
   a = rand () % 6 + 1;
   n = n + a * 100;
   a = rand () % 3 + 1;
   n = n + a * 10;
   switch (a)
    
    {
     case 1:
       a = 0;
       break;
     case 2:
       a = rand () % 2 + 1;
       break;
     case 3:
       a = rand () % 3;
       break;
     }
   n = n + a;
   return n;
 }

    
