#include <stdio.h>
#include <stdlib.h>
#define SIZE 3
struct node {
    int info;
    struct node *next;
};
typedef struct node *Node;
//creo una funzione che controlli che la memoria sia alloccata correttamente
Node node_check(){ 
    struct node *new=malloc(sizeof(struct node));
    if (new==NULL){
        printf("Errore allocazione\n");
        exit(EXIT_FAILURE);
    }
    return new;
}

Node list_insert( int n, struct node *l ){
  struct node *new =node_check();
  new -> info = n;
  new -> next = l;
  return new; 
}

Node olist_insert(int n, struct node *l){
    struct node *cur=node_check();
    struct node *prev=node_check();
    prev=NULL;
    cur=l;
    while (cur!=NULL && cur->info<n){
        prev=cur;
        cur=cur->next;
    }
    Node new=node_check();
    new->info=n;
    new->next=cur;
    prev->next=new;
    if (prev==NULL){
        l=new;
        return l;
    }
    return l; //ritorno tutta la lista, se ritornassi solo new mi toglierebbe dei nodi (quelli prima di esso)
}

struct node *cerca(struct node *l, int n){
    struct node *p;
    for (p=l; p!=NULL;p=p->next){   
        //printf("\tSto cercando %d nella lista...\n", n);
        //printf("\t\tValore; %d\n", p->info);
        if (p->info==n){
           // printf("\t\tTrovato!\n");
            return p;
        }
    }
    printf("\t\tNon trovato\n");
    return l;
}   

void stampa (struct node *n){
    while (n!=NULL){
        printf("%d\t", n->info);
        n=n->next;
    }
    printf("\n");
}

int main (){
    Node first=node_check();
    first=olist_insert(3, first);
    stampa(first);
    printf("\n");
    first=olist_insert(1, first);
    stampa(first);
    first=olist_insert(2, first);
    stampa(first);
}
