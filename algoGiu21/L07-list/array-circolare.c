#include <stdio.h>
#include <stdlib.h>
#define size 5
#define Item int

//Quando la coda è vuota lo = hi = -1

struct queue {
    int n;
    Item *arr;
    int lo;
    int hi;
};
typedef struct queue *Queue;

int is_empty_queue(Queue q){
    return (q -> hi == -1);
}

int is_full_queue(Queue q){
    return (q -> n == size);
}
Queue new_queue(){
    Queue q = malloc(sizeof(struct queue));
    q -> n = 0;
    q -> hi = q -> lo = -1;
    Item *a = calloc(size, sizeof(Item));
    q -> arr = a;
    return q; 
}

void enqueue (Queue q, Item i){
    if (is_full_queue(q)){
        printf("Coda piena, impossibile aggiungere\n");
        return;
    }
    printf("\t q -> hi: %d\n", q ->hi);
    if (is_empty_queue(q))
        q -> hi = q -> lo = 0;
    q -> arr[(q -> hi) % size] = i;
    q -> hi = (q -> hi + 1) % size;
    q -> n++;
    return;
}

Item dequeue (Queue q){
    if (is_empty_queue(q)){
        printf("Coda vuota, impossibile restituire\n");
        return 0;
    }
    printf("\t q -> lo: %d\n", q ->lo);
    Item ret = q -> arr[q -> lo % size];
    q -> n--;
    q -> lo = (q -> lo + 1) % size;

    if (q -> n == 0)
        q -> lo = q -> hi = -1;

    return ret;
}

Item frontValue(Queue q){
    return q -> lo;
}

void print_queue(Queue q){
    for (int i = 0; i < q -> n; i++)
        printf("%d ", q -> arr[(q -> lo + i) % size]);
    printf("\n");
}

int main (void){
    Queue q = new_queue();
    //printf("%d\n", is_empty_queue(q));
    print_queue(q);
    enqueue(q, 5);
    enqueue(q, 5);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3); 
    print_queue(q); // 5 5 1 2 3
    dequeue(q);  
    dequeue(q);
    print_queue(q); // - - 1 2 3
    enqueue(q, 4);
    enqueue(q, 5);
    print_queue(q); // 4 5 1 2 3
    dequeue(q);   
    dequeue(q);  
    dequeue(q);  
    // printf("%d\n", frontValue(q));

}