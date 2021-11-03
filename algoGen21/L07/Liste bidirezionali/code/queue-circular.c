#include "queue.h"
//cerco di capire come utilizzare la struttura della coda
#include <stdio.h>
#include <stdlib.h>
#define L 4

//NON HO IMPLEMENTATO L'ARRAY CIRCOLARE. DOVREI UTILIZZARE IL MODULO PER RIPARTIRE DA CAPO

void print_queue(Queue q){
    for (int i=q->arrSize-1; i>=0; i--){
        printf("|\t%d\t|\n", *(q->circular+i));
    }
    printf("\n");
}
int is_empty_queue(Queue q){
    if (q->circular==NULL)
        return 1;
    return 0;
}

void enqueue(Queue q, Item item){
    int *new;    
    if (is_empty_queue(q)==1){
    //alloco lo spazio per l'array, altrimenti ottengo un segfault
        q->circular=malloc(L);
        new = q->circular+q->arrSize;
        *new=item;
        q->front=q->rear=new;
        q->arrSize++;
        return;
    }
    if (q->arrSize%L==0){ //se ho finito lo spazio nella coda circolare
     q->arrSize=0;   
    }
    new = q->circular+q->arrSize; //assengo un nuovo nome alla posizione corrente dell'array (per semplicità)
    *new=item;
    q->rear=new;
    (q->arrSize)++;
    return;
}

Item dequeue(Queue q){
    q->arrSize--;
    int value;
    value=*(q->front);
    //l'elemento che precede front si trova sempre in posizione circular[1], 
    //a meno che non ci sia solamente un elemento nella coda
    q->front=&(q->circular[1]);
    return value;
}

int main(void){
    Queue q=malloc(sizeof(struct queue));
    q->arrSize=0;
    enqueue(q, 1);enqueue(q, 2);enqueue(q, 3);enqueue(q, 4);enqueue(q,5);
    print_queue(q);
    printf("dequeue value: %d\n", dequeue(q));
    print_queue(q);
    printf("dequeue value: %d\n", dequeue(q));
    print_queue(q);


}