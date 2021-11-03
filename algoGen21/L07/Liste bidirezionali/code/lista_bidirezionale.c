#include <stdio.h>
#include <stdlib.h>
#include "bidirezionali.h"

int main (void){
    Bi_list start = malloc(sizeof(struct bi_list));
    insert(start, 1);
    insert(start, 2);
    insert(start, 3);
    stampa(start);
}

void insert (Bi_list b, int n){
    Bi_node new = new_node(n);
    if (b->first==NULL){ //se la lista è vuota
        b->first=b->last=new;
    }else{
        Bi_node tmp = malloc(sizeof(struct bi_node));
        tmp=b->first;
        b->first=new;
        new->next=tmp;
        tmp->prev=new->next;
    }
    //devo anche ricordarmi di modificare il prev del nodo successivo
    printf("last: %d\n", b->last->info);
    printf("fisrt: %d\n", b->first->info);
}
Bi_node new_node(int v){
    Bi_node new = malloc(sizeof(struct bi_node));
    new->info=v;
    new->next=NULL;
    new->prev=NULL;
    return new;
}

void stampa (Bi_list b){
    //scorro la lista fino a NULL
    Bi_node tmp=malloc(sizeof(struct bi_node));
    tmp=b->first;
    while (tmp){
        printf("%d ", tmp->info);
        tmp=tmp->next;
    }
    printf("\n");
}

