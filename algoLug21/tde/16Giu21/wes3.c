/**
 * Realizzo una foresta di alberi non binari che mantengono anche il collegamento con il padre nel nodo.
 */
#include <stdio.h>
#include <stdlib.h>
int *padre;
struct node{
    int v;
    struct node **listFigli;
    int numFigli;
    //int *padre; 
    };
typedef struct node *Node;

// n è il numero di dipendenti di massimo livello.
//creo una foresta con n alberi
Node new_dipendenti(int max_livello){
    //creo un vettore di alberi
    Node *new = calloc(max_livello, sizeof(struct node));
    for (int i = 0; i < max_livello; i++){
        Node p = calloc(1, sizeof(struct node));
        p -> v = 0; //il dipendente max ha chiave 0
        p -> listFigli = calloc(100, sizeof(struct node *));
        new[i] = p;
        padre
    }
    return new;
}

void addSub(Node n, int v){
    Node new = malloc(sizeof(struct node));
    new -> v = v;
    new -> listFigli = calloc(100, sizeof(struct node *));
    padre[v] = n -> v;
    n -> numFigli++;
    n -> listFigli[numFigli] -> next = new;


}
/**
 * StampaSubordinati
 * supervisore
 * quantiSenzaSubordinati
 * stampaImpigatiSopra
 * stampaImpiegatiConSupervisore
 * stampaPerLivello
 */