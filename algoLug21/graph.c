#include <stdio.h>
#include <stdlib.h>
struct node{
    int v;
    struct node *next;
};
typedef struct node *Node;

struct graph{
    int V;
    int E;
    struct node **A;
};
typedef struct graph *Graph;

Graph new_graph(int v){
    Graph g = calloc(1, sizeof(struct graph));
    g -> V = v;
    g -> E = 0;
    g -> A = calloc(v + 1, sizeof(struct node *));
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
    g -> E++; 
    Node new = new_node(w);
    new -> next = g -> A[v];
    g -> A[v]= new;

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
// NOn ha tanto senso cercare in un grafo
// Node cerca(Graph g, int n){
//     for (int i = 1; i <= g -> V; i++){
//         Node curr = g -> A[i];
//         Node prev = NULL;
//         for (; curr != NULL && curr -> v != n; ){
//             prev = curr;
//             curr = curr -> next;
//         }
//         if (prev == NULL) return curr;
//         if (curr == NULL) return NULL;
//         return prev;

//     }
// }

int main (void){
    Graph g = new_graph(4);
    addArco(g, 1, 2);
    addArco(g, 2, 3);
    addArco(g, 3, 1);
    cerca(g, )
    stampa(g);
}