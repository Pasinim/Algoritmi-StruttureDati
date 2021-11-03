#include <stdio.h>
#include <stdlib.h>
#define maxLiv 3
#define dipendenti 4
int *padri;
struct node{
    int v;
    struct node *next;
    };
typedef struct node *Node;

struct graph{
    int V;
    int E; //posso usare E per contare il numero di subordiati
    struct node **A;
    int *padri;
};
typedef struct graph *Graph;

/**
 * Inizializza un grafo con n dipendenti subordinati
 */
Graph new_graph(int v){
    Graph g = calloc(1, sizeof(struct graph));
    g -> V = v;
    g -> E = 0;
    g -> A = calloc(v + 1, sizeof(struct node *));
    g -> padri = calloc(10, sizeof(int));
    return g;
}

Node new_node( int n){
    Node new = malloc(sizeof(struct node));
    new -> v = n;
    new -> next = NULL;
    return new;
}

/**
 * Aggiungo un arco da v a w
 */
void addArco(Graph g, int v, int w){
    printf("acaa\n");
    Node new = new_node(w);
    new -> next = g -> A[v];
    g -> A[v]= new;
    g -> E++; 

}

void stampa (Graph g){
    for (int i = 1; i <= g -> V; i++){
        Node tmp = g -> A[i];
        printf("Nodo %d -> ", i);
        while (1){
            if (tmp == NULL) break;
            printf("%d -> ", tmp -> v);
            tmp = tmp -> next;
        }
        printf("\n");
    }
}
////////////////////////////////////////////////////////////

Graph *new_gerarchia(){
    Graph *g = calloc(maxLiv, sizeof(struct graph));
    for (int i = 0; i < maxLiv; i++)
        g[i] = new_graph(dipendenti);
    printf("mmmm\n");
    return g;
}
/**
 * aggiunge un dipendente w subordinato di v. 
 * v è quindi il padre di w
 */
void addDipendente(Graph g, int v, int w){
    printf("adad");
    g -> padri[w] = v;
    addArco(g, v, w);
}

void stampaGerarchia(Graph *g){
    for (int i = 0; i < maxLiv; i++){
        printf("____Albero %d:____\n", i);
        stampa(g[i]);
    }
}

void StampaSubordinati(Graph g, int chiave){
    Node tmp = NULL;
    printf("Subordinati di %d: ", chiave);
    for (tmp = g -> A[chiave]; tmp != NULL; tmp = tmp -> next)
        printf("%d, ", tmp -> v);
    printf("\n");
}

int supervisore (Graph g, int chiave){
    return g -> padri[chiave];
}

void stampaNodo(Node n){
    printf("%d, ", n -> v);
}

/**
 * Scorro il vettore dei padri e stampo il padre di ogni valore
 */
void stampaImpiegatiConSupervisore(Graph g){
    for ( int i = 0; i < g -> E; i++){
        stampaNodo(g -> A[g -> padri[i]]);
    }
    printf("\n");
}

void stampaPadri(Graph g, int l){
    for (int *p = g -> padri; p < g -> padri + l; p++)
        printf("%d, ", *p);
    printf("\n");
}
/**
 * StampaSubordinati
 * supervisore
 * quantiSenzaSubordinati
 * stampaImpigatiSopra
 * stampaImpiegatiConSupervisore
 * stampaPerLivello
 */

int main(void){
    Graph *g = new_gerarchia();
    addDipendente(g[0], 1, 2);
    printf("adadad\n");
    addDipendente(g[0], 1, 3);
    addDipendente(g[0], 2, 4);
    addDipendente(g[0], 3, 5);
    //addDipendente(g[0], 1, 2);
    stampaGerarchia(g);
    printf("Sup 3 : %d\n", supervisore(g[0],5));
    stampaPadri(g[0], 5);
    //stampaImpiegatiConSupervisore(g[0]);
}
