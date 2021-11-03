#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct graph {
    int n; //vertici
    int m; //archi
    int **A;
};
typedef struct graph *Graph;

Graph new_graph (int v){
    int i; Graph g;
    /* alloca lo spazio per una struct graph */
    g = malloc(sizeof(struct graph) );
    /* alloca lo spazio per un array di n puntatori a int */
    g -> A = calloc( v+1, sizeof(int *) );
    /* alloca lo spazio per l’array A[i] di n interi, inizialmente nulli */
    for ( i = 0; i <= v; i++ )
        g -> A[i] = calloc( v, sizeof( int ) );
    g -> n = v;
    return g;
}

void edgeinsert(Graph g, int v, int w){
    int *tmp = g -> A[v];
    if (tmp[w] == 0) tmp[w] = 1;
    tmp = g -> A[w];
    if (tmp[v] == 0) tmp[v] = 1;
    return;
}

void print_graph(Graph g){
    for (int i = 1; i <= g -> n; i++ ){
        int *tmp = g -> A[i];
        for (int j = 1; j <= g -> n; j++ )
            printf("%d ", tmp[j]);
        printf("\n");
    }
    return;
}

void graph_destroy(Graph g){
    int ver = g -> n;
    for ( int i = 0; i <= ver; i++ )
        free(g -> A[i]);
    free(g);
    }

int main(void){
    Graph g = new_graph(4);
    edgeinsert(g, 1, 2);
    edgeinsert(g, 4, 2);
    print_graph(g); 
    graph_destroy(g);
    print_graph(g); 
}