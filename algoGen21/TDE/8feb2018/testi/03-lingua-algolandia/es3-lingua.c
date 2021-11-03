#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



struct element {  // elemento di lista
  char ch;
  struct element *next;    // prossimo elemento
};


struct graph {
  int n, m;
  struct element **A; // vettore delle liste di adiacenza
};

typedef struct graph *Graph;

Graph newGraph( int n ); /* alloca una struttura grafo con n nodi */
void addEdge( Graph g, char x, char y); /* inserisce l'arco x -> y */
void printGraph( Graph g ); /* stampa su standard output le liste di adiacenza di g */


// funzione read
Graph read(){
    int r;
    char x, y;
    printf("Numero regole: ");scanf(" %d", &r);
    Graph g=newGraph(24);
    for (int i=0; i<r; i++){
        scanf( " %c%c", &x, &y );
        addEdge(g, x, y);
    }
    return g;
}


// funzione followers
void followers(Graph g, char x){
    struct element *tmp=malloc(sizeof(struct element));
    printf("La lettera %c può essere seguita da: ", x);
    for (tmp=g->A[x-'A']; tmp!=NULL;tmp=tmp->next ){
        printf("%c, ", tmp->ch);
    }
    printf("\n");
}

// funzione max
//devo trovare la lista di adiacenza maggiore?
void max(Graph g){
    struct element *max=malloc(sizeof(struct element));
    int cMax=0; //"posizione" della lista di adiacenza maggiore

    //devo fare due cicli per contare i nodi di ciascuna lista
    struct element *tmp=malloc(sizeof(struct element));
    for (int i=0; i<g->n; i++){
        //mi da segfault alla riga seguente
        printf("Sono in %c\n;", g->A[i]->ch);
        int c=0;
        for (tmp=g->A[i]; tmp!=NULL; tmp=tmp->next){
            c++;
        }
        printf("Lunghezza di %c: %d\t", g->A[i-'A']->ch, c);
        if (c>=cMax){ //se la lista di adiacenza del vertice corrente è la maggiore
            max=g->A[i];
            cMax=c;
        }
    }
    //ora stampo la lista maggiore
    //struct element *tmp2=malloc(sizeof(struct element));
    printf("aaaaaaaaAAlista max: ");
    // for (tmp2=max; tmp2!=NULL;tmp2=tmp2->next){
    //     printf ("%c->", tmp->ch);
    // }
        for (int i=0; i<g->n; i++){
        int c=0;
        for (tmp=g->A[i]; tmp!=NULL; tmp=tmp->next){
            c++;
        }
        printf("Lunghezza di %c: %d\t", g->A[i-'A']->ch, c);
        if (c==cMax){ //se la lista di adiacenza del vertice corrente è la maggiore
            printf("%c", 'A'+i);
        }
    }
    printf("\n");
}


int main( int argc, char *argv[]){
    //
    Graph g = read();
    char c;
    printf("follower\t");scanf( " %c", &c );
    followers(g,c);
    max(g);
    printGraph(g);
    //
    return 0;
}

/* crea una struttura grafo con n nodi */
Graph newGraph( int n ){
	Graph g = malloc(sizeof(struct graph));
	if(!g) {
        	fprintf(stderr,"Errore di Allocazione\n");
	        exit(EXIT_FAILURE);
	}
	g -> n = n;
	g -> A = calloc( n, sizeof( struct element* ) ); // vettore delle liste di adiacenza: g -> A [i] e' la lista dell'i-esimo nodo
	return g;
}

// inserimento in liste di adiacenza
struct element *list_insert( struct element *list, char ch ) {
	struct element *new = malloc( sizeof( struct element ) );
	new -> ch = ch;
	new -> next = list;
	return new;

}

// inserisce nel grafo l'arco x -> y
void addEdge( Graph g, char x, char y){
  g->A[x-'A'] = list_insert(g->A[x-'A'],y);
  g->m++; //incremento il numero dell'arco
}

/* stampa su standard output le liste di adiacenza di g */
void printGraph( Graph g ){
	printf( "\n************** stampo grafo\n" );
	int n = g -> n;
	struct element **al = g -> A;
	struct element *curr;

	printf( "%d nodi\n%d archi\n", n, g -> m );

	for ( int i = 0; i < n; i++ ) {
		printf( "%c:", 'A'+i );
		for ( curr = al[i]; curr != NULL; curr = curr -> next ) {
			printf( " %c", curr -> ch );
		}
		printf( "\n" );
	}
	printf( "fine stampa grafo *************************\n\n");

}