#include "queue.h"
//cerco di capire come utilizzare la struttura della coda
#include <stdio.h>
#include <stdlib.h>
void print_queue(Queue q){
    for (int i=0; i<q->arrSize; i++){
        printf("%d\t", *(q->circular+i));
    }
    printf("\n");
}

int main (){
    Queue q = malloc(sizeof(struct queue));
    q->arrSize=0;
    q->circular=malloc(2); //devo allocare lo spazio per l'array
    *(q->circular)=1;
    *(q->circular+1)=2;
    *(q->circular+2)=3;
    q->arrSize=3;
    print_queue(q);
}