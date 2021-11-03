#include <stdio.h>
#include <stdlib.h>
struct node {
    struct node *next;
    int v;
};
typedef struct node *Node;

struct graph{
    int V; //numero di nodi
    int E; //numero di archi 
    struct node **A; //array di liste di adiacenze. Per ogni vertice ho una lista di adiacenza
};
typedef struct graph *Graph;

Node vertex_insert(Node list, int n){
    //aggiungo alla lista di adiacenza del nodo indicato in list, in nodo n;
    Node p=malloc(sizeof(struct node));
    p->v=n;
    p->next=list; //metto il vertice nella testa della lista, quindi ritorno il nodo appena creato
    return p;
}
/* crea un grafo con n nodi */
Graph graph_new( int n ){
    Graph g=malloc(sizeof(struct graph));
    if (g==NULL){ //equivalente a (!g)
        printf("Errore di allocazione\n");
        exit(EXIT_FAILURE);
    }
    g->V=n;
    g->E=0; //al momento della creazione non ho archi
    g->A=calloc(n, sizeof(struct node *));
    return g;
};

/* distrugge il grafo g */
void graph_destroy ( Graph g ){
    for (int i=0; i<g->V; i++){
        //ciclo ciasun vertice per elimnare tutte le liste di adiacenza
        Node tmp=malloc(sizeof(struct node));
        tmp=g->A[i];
        Node next=malloc(sizeof(struct node));
        for (;tmp!=NULL;){
            next=tmp->next;
            free(tmp);
            tmp=next;
        }
    }
    //il numero di archi e di vertici deve essere impostato a 0 dato che ho cancellato tutto
    g->V=0;
    g->E=0;
    printf("Ho cancellato tutto il grafo\n");
};

/* inserisce l’arco (v,w) nel grafo g */
void graph_edgeinsert ( Graph g, int v, int w ){
    g->A[v-1]=vertex_insert(g->A[v-1], w);
    g->A[w-1]=vertex_insert(g->A[w-1], v);
    g->E++;
    return;
};


/* legge da standard input un grafo (specificare il formato!!) */
//non testata
Graph graph_read( void ){
    int v, w, Vcount=0; 
    printf("Inserici il numero di vertici "); 
    scanf("%d %d %d", &Vcount, &v, &w);
    Graph g=graph_new(Vcount);
    while (v!=0 || w!=0){
        graph_edgeinsert(g, v, w);
        scanf("%d %d", &v, &w);
    }
    return g;
};

/* stampa su standard output un grafo (specificare il formato!!) */
void graph_print ( Graph g ){
    for (int i=0; i<g->V; i++){
        //per ogni nodo del grafo devo stampare la sua lista di adiacenza
        Node tmp=malloc(sizeof(struct node));
        tmp=g->A[i];
        printf("Verice %d:\t", i+1);
        for (; tmp!=NULL; tmp=tmp->next){
            printf(" %d->", tmp->v);
        }
        printf( "\n");
    }
};

void graph_dfs(Graph g){
    
}