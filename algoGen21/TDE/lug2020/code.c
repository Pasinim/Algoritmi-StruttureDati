#include <stdio.h>
#include <stdlib.h>

struct node {
    int item;
    struct node *next;
};
typedef struct {
    struct node *head;
} *List;

struct dlist {
    struct node *head;
    struct node *tail;
};
typedef struct dlist Dlist;

void dlist_addAtEnd(Dlist *l, int value){
    struct node *new=malloc(sizeof(struct node));
    new->item=value;
    new->next=NULL;
    if (l->head==NULL){
        l->head=l->tail=new;
        return;
    }
    l->tail->next=new;
    l->tail=new;
    return;
}

//void list_print(List l){
void list_print(struct node *l){
    struct node *tmp;
    for (tmp=l; tmp!=NULL; tmp=tmp->next){
        printf("%d ", tmp->item);
    }
    printf("\n");
    return;
}

void list_addAtEnd (List l, int value){
    struct node *new=malloc(sizeof(struct node));
    new->item=value;
    new->next=NULL;
    if (l->head==NULL){
        l->head=new;
        return;
    }
    struct node *curr=l->head, *prev=NULL;
    while(curr!=NULL){
        printf("\ttmp: %d", curr->item);
        prev=curr;
        curr=curr->next;
    }
    printf("\t_____\n");
    prev->next=new;
    return;
}

//la funzione mystery restituisce il nodo precedente a quello che contiene il nodo con il valore value
//oppure il penultimo elemento della lista

struct node *mystery( List l,int value ) {
    struct node *current = l -> head;
    struct node *temp = NULL;
    while( current != NULL && current -> item != value ) {
        temp = current;
        current = current -> next;
    }
        return temp;
        }

int main (){
    List l=malloc(sizeof(List));
    list_addAtEnd(l, 1);
    list_addAtEnd(l, 2);
    list_addAtEnd(l, 3);
    list_addAtEnd(l, 4);    
    list_print(l->head);

    Dlist *d=malloc(sizeof(struct dlist));
    dlist_addAtEnd(d, 1);
    dlist_addAtEnd(d, 2);
    dlist_addAtEnd(d, 3);
    list_print(d->head);
    struct node *trova=mystery(l, 3);
    printf("%d \n", trova->item );


}

