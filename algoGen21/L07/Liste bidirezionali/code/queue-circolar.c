#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

#define dim 4  //dimensione massima dell'array
void enqueue(Queue q , Item item){
    if (q->arrSize==0){
        printf("aaa");
        *(q->circular+q->arrSize)=item; 
        q->arrSize++;
        q->rear=q->front=q->circular;
        return;
    }
    //se la coda non è vuota assegno il valore e modifico rear
    *(q->circular+q->arrSize)=item; 
    q->arrSize++;
    q->rear=(q->circular+q->arrSize);
    return;
}

void print_queue(Queue q){
    for (int i =0; i<q->arrSize;i++){
        printf("%d\t", *(q->circular+i));
    }
    printf("\n");    
}

int main (void){
    Queue q=malloc(sizeof(struct queue));
     printf("aaa");
    q->arrSize=0;
    enqueue(q, 5);
   
    print_queue(q);

}