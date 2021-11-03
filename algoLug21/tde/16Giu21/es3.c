/**
 * Realizzo una foresta di alberi non binari che mantengono anche il collegamento con il padre nel nodo.
 * Creo una struttura dati per rappresentare un albero, in cui memorizzo il MaxSupervisore, il vettore che 
 * tiene traccia dei padri e la lista che tiene traccia dei figli.
 * Creo una ulteriore struttura dati per rappresentare un nodo dell'albero.
 */
#include <stdio.h>
#include <stdlib.h>
struct node {
    int key;
    struct node *next;
};
typedef struct node *Node;
/**
 * Un nodo v ha nella lista i propri figli.
 * Utilizzo una struttura simile ad un grafo anzichè un albero perchè 
 * è molto comodo il fatto che key = indice. Per questo motivo il tempo per la
 * ricerca è costante.
 * la dimensione di radice è lungo come la lunghezza degli alberi
 */
struct foresta{
    int numAlberi;
    int *padre;
    int *figli; //contiene gli indici dei nodi che sono radici
    int numDipendeti;
    struct node **listaFigli;
    //listafigli[0] rappresenta il primo albero, ecc
};
typedef struct foresta *F;

Node new_node(int n){
    Node new = malloc(sizeof(struct node));
    new -> v = n;
    new -> next = NULL;
    return new;
}

F new_foresta(int dipMax, int dipTot){
    F new = calloc(1, sizeof(struct foresta));
    new -> numDipendeti = dipTot;
    new -> numAlberi = dipMax;
    Node *figli = calloc(dipTot, sizeof(struct node *));
    int *p = calloc(dipTot, sizeof(int));
    new -> listaFigli = figli;
    new -> padre = p;
}

void stampaSubordinati(Node n){
    while (n != NULL){
        printf("%d, ", )
    }
}
/**
 * StampaSubordinati
 * supervisore
 * quantiSenzaSubordinati
 * stampaImpigatiSopra
 * stampaImpiegatiConSupervisore
 * stampaPerLivello
 */

void addSu

√