#include <stdio.h> 
#include <stdlib.h>

struct node {
    char *w;
    struct node *next;
};
typedef struct node *Node;
Node flist( Node l ) {
	if ( l -> w[0] != '\0' && l -> w[1] == '\0' )
		return l; //se i primi due caratteri della testa della lista sono a capo ritorna
	Node n = malloc( sizeof(struct node) );
	n -> w = ( l -> w ) + 1; //prende la parola di l togliendo il primo carattere
	n -> next = l; //collega la nuova lista a quella precedente, concatenando così le due stringhe
    printf("\t\t%s \n", (n->w));
	return flist( n );		//flist viene eseguita fin quando i caratteri della parola sono finit

	//cane ->  anecane-> neanecane -> eneanecane
	}
Node build( char *w ) {
	Node lista = malloc (sizeof(struct node) );
	lista -> w = w;
	lista -> next = NULL;
	return flist( lista );
}

int main (void){
    Node n=malloc(sizeof(struct node));
    char *s="cane";
    n=bulid(s);
    //flist(n);
    printf("%s \n", (n->w));
}