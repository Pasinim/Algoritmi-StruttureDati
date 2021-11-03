#include <stdlib.h>
#include <stdio.h>
/**
 * 1.
 * I nodi rappresentano le posizioni della griglia mentre gli archi indicano in quale
 * posizione ci si può muovere da quella attuale. I serpenti saranno degli archi che andranno
 * in una posizione più bassa, mentre le scale andranno in una posizione più alta.
 * Il grafo è orientato, ad esempio se ci si trova sulla bocca di un serpente è solo possibile
 * andare alla coda e non viceversa.
 * 
 * 2.
 * 
 */

 struct node{
     int value;
     struct node *next;
 };
typedef struct node *Node;

 struct graph {
     int V;
     int E;
     Node *A;
 };
 typedef struct graph *Graph;

Node new_node(int v){
    Node new = malloc(sizeof(struct node));
    new -> value = v;
    new -> next = NULL;
    return new;
}

Graph new_graph (int v){
    Graph new = malloc(sizeof(struct graph));
    new -> A = calloc(v+1, sizeof(struct node*));
    new -> V = v;
    new -> E = 0;
    return new; 
}

//arco che va solamente da v a w: v -> w, non il contrario
void edge_insert(Graph g, int v, int w){
    Node new = new_node(w);
    new -> next = g -> A[v];
    g -> A[v] = new;

    // new = new_node(v);
    // new -> next = g -> A[w];
    // g -> A[w] = new;
    return;
    }

//creo una griglia grande r*c collegando le caselle
Graph new_griglia(int r, int c){
    int caselle = r*c;
    Graph griglia = new_graph(caselle);
    for (int i=1; i <= caselle; i++){
        edge_insert(griglia, i, i+1);
    }
    return griglia;
    }
 
 void stampa_grafo (Graph g){
     printf("V\n");
    for (int i=1; i <= g -> V; i++){
        Node tmp = g -> A[i];
        printf ("%d: ", i);
        while (tmp != NULL){
            printf("%d -> ", tmp -> value);
            tmp = tmp -> next;
        }
        printf("\n");
    }
 }

 void stampa_griglia(Graph griglia){
     for (int i=1; i <= griglia -> V; i++){
         printf("%d -> ", griglia -> A[i] -> value);
         if (i%10 == 0) printf("\n");
        }
        printf("\n");
    }
 /**
  * Devo sovrascrivere l'arco che va alla casella successiva, infatit
  * se capito su un serpente esco nella coda
  */
 void crea_serpente(Graph g, int m, int t){
     Node new = new_node(t);
     g -> A[m] = new; 
 }

void crea_scala(Graph g, int start, int end){
     Node new = new_node(end);
     g -> A[start] = new; 
}
 

 int main (void){
     Graph g = new_griglia(3, 4);
     printf("\n");
     crea_serpente(g, 12, 1);
     crea_scala(g, 1, 10);
     stampa_grafo(g);
 }