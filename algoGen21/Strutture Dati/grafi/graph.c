#include "graph.h"
int main (void){
    Graph g =graph_new(4);
    graph_edgeinsert(g, 1, 2);
    graph_edgeinsert(g, 2, 3);
    graph_print(g);
    graph_destroy(g);
    graph_print(g);
}