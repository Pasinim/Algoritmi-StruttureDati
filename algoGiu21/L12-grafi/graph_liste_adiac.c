//Rappresentazione con liste di adiacenza
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "coda.h"

//definita in coda.h
// struct node{
//     int value;
//     struct node *next;
// };
// typedef struct node *Node;

struct graph {
    int V; //Vertici
    int E; //Archi
    struct node **A;
};
typedef struct graph *Graph;

Node new_node(int n){
    Node new = malloc(sizeof(struct node));
    new -> value = n;
    new -> next = NULL;
    return new;
}

Graph new_graph (int n){
    Graph new = malloc(sizeof(struct graph));
    if (!new)
        exit(EXIT_FAILURE);
    new -> V = n; 
    new -> E = 0;
    // new -> A = malloc(sizeof(struct node) * n);
    // for (int i = 0; i < n; i++)
    //     new -> A[i] = NULL;
    //per evitare di assegnare ad ogni nodo NULL posso anche 
    //usare la calloc che lo fa automaticamente:
    new -> A = calloc(n + 1, sizeof(struct node*));
    return new;
}

bool isIn (Node p, int v){
    for ( ; p != NULL; p = p -> next)
        if (p -> value == v)
            return true;
    return false;
}

//EFFECTS: aggiunge l'arco v -> w (se non è presente)
void edge_insert(Graph g, int v, int w){ 
    if (isIn(g -> A[v], w)) return;
    //devo creare un nuovo nodo da mettere nella lista di adiacenza del nodo
    Node new1 = new_node(w);
    new1 -> next = g -> A[v];
    g -> A[v] = new1;

    Node new2 = new_node(v);
    new2 -> next = g -> A[w];
    g -> A[w] = new2;

    g -> E++;
    return;
}

void graph_destroy(Graph g){
   for (int i=0; i <= g -> V; i++){
        Node tmp;
        Node curr = g -> A[i];
        while (curr != NULL){
            tmp = curr;
            curr = curr -> next;
            free(tmp);
        }
     }
     g -> V = 0;
     g -> E = 0;
   }
   

void print_graph (Graph g){
    if (g -> V == 0) printf("\tIl grafo non ha vertici. Impossibile stampare\n");
    for (int i = 1; i <= g -> V; i++){
        printf("\t  V %d: ", i);
        for (Node tmp = g -> A[i]; tmp != NULL; tmp = tmp -> next){
            printf("%d -> ", tmp -> value);
        }
        printf("\n");
    }
}

void dfs(Graph g, int vertex, int *visited) {    // Visita in profondità
     Node temp = g->A[vertex];
     
     visited[vertex] = 1;
     printf("Visited %d\n", vertex);

     while (temp != NULL) {
          int connectedV = temp->value;
          if (visited[connectedV] == 0) {
               dfs(g, connectedV, visited);
          }
          temp = temp -> next;
     }
}

void bfs(Graph g, int startV) {      // Visita in ampiezza
     Coda q = new_coda();
     int *visited = calloc(g->V, sizeof(int));
     visited[startV] = 1;
     enQueue(q, startV);

     while (!isEmpty(q)) {
          //printCoda(q);
          int currentV = deQueue(q);
          printf("Visited %d\n", currentV);

          Node temp = g->A[currentV];
          while (temp) {
               int adjV = temp->value;
               if (visited[adjV] == 0) {
                    visited[adjV] = 1;
                    enQueue(q, adjV);
               }
               temp = temp -> next;
          }
     }
     printf("Visita BFS completata.\n");
     free(visited);
}

Graph graph_read(void){
    int n, v, w;
    printf("Inserire il numero di vertici: ");
    scanf("%d", &n);
    Graph g = new_graph(n);
    printf("Inserire gli archi. (0, 0) per terminare: \n");
    for (int i=1; i<= g -> V; i++ ){
        scanf("%d %d", &v, &w);
        if (v == 0 && w == 0) break;
        edge_insert(g, v, w);
        printf("\n");
    }
    return g;
}

int main (){
    Graph g = graph_read();
    // edge_insert(g, 1, 2); //colego 1 a 2
    // edge_insert(g, 1, 4); //collego 1 a 4
    // edge_insert(g, 4, 1); //colego 1 a 2
    print_graph(g);
    dfs(g, 0, 0);   
    graph_destroy(g);
    print_graph(g);   

}