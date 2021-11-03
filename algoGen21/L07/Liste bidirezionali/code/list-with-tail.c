#include <stdlib.h> 
#include <stdio.h>

struct node {   
  int info;   
  struct node *next;
};
typedef struct node *Node;

typedef struct {
  Node head;
  Node tail;
} *List_with_tail;
void stampa_nodo(Node p);
void stampa(Node p);
Node new_node ( int e ) {
  Node new = malloc( sizeof (struct node) );
  new -> info = e;
  new -> next = NULL;
  return new;
}

void addAtEnd( List_with_tail l, int e ){
  if ( l -> tail == NULL ) {
    l -> tail = new_node(e);
    l -> head = l -> tail;
  }
  else {
    Node new = new_node(e);
    l->tail->next=new;
    l->tail=new;
    // MISSING CODE
  }
}
void addAtStart(List_with_tail l, int e){
    if ( l -> head == NULL ) {
    l -> tail = new_node(e);
    l -> head = l -> tail;
  }else{
    Node new=new_node(e);
    Node tmp=malloc(sizeof(struct node));
    tmp=l->head;
    l->head=new;
    l->head->next=tmp;
    //new->next=tmp; dovrebbe essere la stessa cosa
  }
}

//funzione alternativa per trovare la coda della lista
void removeAtEnd2(List_with_tail l){
  //faccio un ciclo mantentendo due puntatori
  Node prox=l->head->next;
  Node cur = l->head;
  
  while (prox->next!=NULL){
    cur=prox;
    prox=prox->next;
  }
  printf(" cur %d \t next %d \n", cur->info, prox->info);// cur->info);
  l->tail=cur;
  free(prox);
  //prox=NULL;
  //prox->info=0;
  printf("tail %d\n", l->tail->info);
}

void trovaPenultimo (List_with_tail l){
 Node tmp=malloc(sizeof(struct node));
  //faccio un ciclo per trovare l'ultimo elemento della lista, ossia la coda.
  tmp=l->head;
  while (1){
    if (tmp->next->next==NULL) break;
    tmp=tmp->next;
  }
  printf("precoda ");stampa_nodo(tmp);printf("\n");
}
void removeAtEnd(List_with_tail l){
  Node last=malloc(sizeof(struct node));
  //faccio un ciclo per trovare il penultimo elemento della lista, ossia il nodo che precede tail.
  last=l->head;
  while (1){
    if (last->next->next==NULL) break;
    last=last->next;
  }
  printf("last vale: %d\n", last->info);
  printf("prima della free tail vale: %p\n", l->tail);
  Node tmp=malloc(sizeof(struct node));
  tmp=l->tail;
  l->tail=last;
  free(tmp);
  //printf("tmp vale: %p\n", tmp);
  //Node lastNext = malloc(sizeof(struct node));
  //lastNext=last->next;
  //printf("last->next vale %d\n", lastNext->info );
  //free(lastNext); //free della coda originaria
}
void stampa_nodo(Node p){
  printf("%d ", p->info);
}

void stampa(Node p){ //mi aspetto di passargli l->head
  Node tmp=malloc(sizeof(struct node));
  for (tmp=p; tmp!=NULL; tmp=tmp->next){
    // if (tmp->next==NULL){
    //   printf("Questo è l'ultimo nodo: "); stampa_nodo(tmp);
    // }
    stampa_nodo(tmp);
  }
  printf("\n");
};

/* Nella soluzione B sto solamente aggiungendo un nuovo nodo alla coda, ma se accedo a tail avrò ancora il vecchio valore
C
*/

typedef struct {
  Node head;
} *List;


int main(void){
  //Node root=new_node(1);
  List_with_tail t=malloc(sizeof(List_with_tail));
  addAtEnd(t, 2);
  addAtEnd(t, 10);
  addAtEnd(t, 20);
  addAtEnd(t, 30);
  addAtStart(t, 40);
  addAtStart(t, 50);
  stampa(t->head);
  //trovaPenultimo(t);
  removeAtEnd(t);
  stampa(t->head);
}