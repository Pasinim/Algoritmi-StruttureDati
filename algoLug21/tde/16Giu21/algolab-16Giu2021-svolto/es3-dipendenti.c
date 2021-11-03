#include <stdlib.h>
#include <stdio.h>

struct listnode {
   int key;
   struct listnode *next;
};

struct listnode *newListNode( int i);
struct listnode *listAdd ( struct listnode *head, int i );

struct f{
   int num_trees; // numero di alberi
   int num; // numero di nodi
   struct listnode **listaFigli; // array (allocato dinamicamente) di liste di figli
   int *padre; // array di interi 
   int *radici; // array di interi
};

typedef struct f *foresta;

void stampaSubordinati( foresta f, int i ) {
   struct listnode *p;
   for ( p = f -> listaFigli[i]; p != NULL; p = p -> next)
      printf( "%d ", p -> key);
}

// i nodi sono visitati in ordine di chiave e non con una visita dell'albero
int quantiSenzaSubordinati( foresta f ) {
   int count = 0;
   for (int i = 0; i < f->num; i++) {
      if ( f -> listaFigli[i] == NULL )
         count++;
   }
   return count;
}

int supervisore( foresta f, int i ){
   return f -> padre[i];
}

void stampaImpiegatiSopra( foresta f, int i) {
   i = f -> padre[i];
   while( i != -1 ) {
      printf( "%d ", i );
      i = f -> padre[i];
   }
   printf( "\n");
}


void stampaImpiegatiConSupervisore ( foresta f ) {
   for ( int i = 0; i < f->num; i++ ) {
      printf( "%d", i );
      if ( f -> padre[i] != -1 )
	 printf( ":%d", f -> padre[i] );
      printf( " " );
   } 	
   printf( "\n" );
}

// Conteggio ricorsivo delle foglie, tramite visita dell'albero
int contaFoglieInAlbero ( foresta f, int i ) {
   if (i == -1) 
      return 0;
   if ( f-> listaFigli[i] == NULL ) // i è una foglia
      return 1;
	
   int sum = 0; 
   struct listnode *p;
   for ( p = f -> listaFigli[i]; p != NULL; p = p -> next)
      sum += contaFoglieInAlbero( f, p -> key );
   return sum;
}

int contaFoglieInForesta ( foresta f ) {
   int sum = 0;
   for (int i = 0; i < f->num_trees; i++) {
      sum += contaFoglieInAlbero( f, f->radici[i] );
   }
   return sum;
}

/*void stampaAlberoConSupervisore( foresta f, int r) { // assumo r radice >= 0
   if ( f -> listaFigli[r] == NULL ) { // r è una foglia
      printf( "%d ", r );
      if ( f -> padre[r] != -1 )
	 printf( "%d ", f -> padre[r] );
      return;
   }

   struct listnode *p;
   for ( p = f -> listaFigli[r]; p != NULL; p = p -> next)
      stampaAlberoConSupervisore( f, p );
}
*/

struct listnode *newListNode( int i){
   struct listnode *new = malloc(sizeof(struct listnode) );
   new -> next = NULL;
   new -> key = i;
   return new;
}

struct listnode *listAdd ( struct listnode *head, int i ){
   struct listnode *new = newListNode(i);
   new -> next = head;
   return new;
}


int main() {   
   int parent[9] = { -1,0,0,0,1,1,-1,6,5 };
   int radici[2] = { 0, 6};
   struct f g;
   g.padre = parent;
   g.radici = radici;
   g.num_trees = 2;
   g.num = 9;
   struct listnode **listaFigli = calloc( g.num, sizeof(struct listnode *) );

   listaFigli[0] = listAdd( listaFigli[0], 3 ); 
   listaFigli[0] = listAdd( listaFigli[0], 2 ); 
   listaFigli[0] = listAdd( listaFigli[0], 1 ); 

   printf( "puntatore listaFigli[0]: %p\n", listaFigli[0] );

   listaFigli[1] = listAdd( listaFigli[1], 5 ); 
   listaFigli[1] = listAdd( listaFigli[1], 4 ); 

   listaFigli[5] = listAdd( listaFigli[5], 8 ); 
   
   listaFigli[6] = listAdd( listaFigli[6], 7 ); 
   
   g.listaFigli = listaFigli;

   stampaImpiegatiConSupervisore( &g );

   for (int i = 0; i < 9; i++ ) {
      printf( "cammino da %d: ", i );
      stampaImpiegatiSopra( &g, i);
   }

   printf( "\n\n" );
   for (int i = 0; i < 9; i++ ) {
      printf( "dipendente %d:\n", i),
      printf( "\tsupervisore: %d\n", supervisore( &g, i) );
      printf( "\tsubordinati di %d: ", i );
      stampaSubordinati( &g, i);
      printf( "\n" );
   }


   printf( "quanti alberi? %d\n", g.num_trees);

   printf( "foglie: %d\n", quantiSenzaSubordinati( &g ) );
   

   printf( "foglie (ricorsivo): %d\n", contaFoglieInForesta( &g ) );
   for (int i = 0; i < g.num_trees; i++ ) {
      printf( "foglie in albero con radice %d: %d\n", g.radici[i], contaFoglieInAlbero( &g, g.radici[i]) );
   }


}



/*
listaFigli
 0: 1 2 3
 1: 4 5
 5: 8
 6: 7

Parent
 0: -1
 1: 0
 2: 

 parent[9] = { -1,0,0,0,1,1,-1,6,5 }

 0 (1 (4() 5 (8)) 2() 3())
 6 (7())

*/
