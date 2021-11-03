#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct queue {
    int size;
    int len;
    int *q;
    int front; 
    int rear;
};
typedef struct queue *Queue;

//EFFECTS: crea una lista di dimensione n
Queue new_queue (int n){
    Queue els = malloc(sizeof(struct queue));
    int *arr = malloc(sizeof(int)*10);
    els -> size = n;
    els -> q = arr; 
    els -> front = -1;
    els -> rear = -1;
    return els;
}

bool isEmpty(Queue els){
    if (els -> len == 0)
        return true;
    return false;
}

//EFFECTS: put n on q -> rear
void enqueue (Queue els, int n){
    if (els -> len == els -> size){ // se l'array è pieno raddoppio la sua dimensione
        printf( "Coda piena, impossibile aggiungere\n");
        return;
    }
    if (els -> len == 0) //se l'array è vuoto sistemo front e rear
        els -> front = els -> rear = 0;
    //printf("sto mettendo %d in rear: %d\n", n, els->rear);
    els -> q [(els -> rear) % (els -> size)] = n;
    els -> rear = ((els -> rear) % (els -> size) + 1);
    (els -> len)++;
    return;
}

int dequeue(Queue els){
    if (els -> len == 0) return -1;
    int value = els -> q[els -> front];
    els -> front = (els -> front % els -> size) + 1;
    (els -> len)--;
    if (els -> len == 0) //controllo se la coda è vuota
        els -> rear = els -> front = -1;
    return value;

}

void stampa_attributi (Queue els){
    printf("\t size: %d\n\t len: %d\n\t front: %d \n\t rear: %d \n ", els -> size, els -> len, els -> front, els -> rear);
    return;
}

void print_queue(Queue els){
    printf("[ ");
    for (int i = 0; i < els -> len; i++)
        printf("%d ", els -> q[(els -> front + i) % els -> size]);
    printf("]\n");
}

int main (void){
    Queue els = new_queue(3);
    enqueue(els, 1);
    enqueue(els, 2);
    enqueue(els, 3);
    stampa_attributi(els);
    print_queue(els);
    dequeue(els);
    enqueue(els, 5);
    stampa_attributi(els);
    dequeue(els);
    dequeue(els);
    print_queue(els);

}