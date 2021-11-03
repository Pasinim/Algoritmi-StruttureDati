#include "pqueue.h"

int main (void){
    Pqueue p=pqueue_new(5);
    pqueue_insert(p, 10);
    pqueue_insert(p, 2);
    pqueue_insert(p,1);
    pqueue_print(p);
}
