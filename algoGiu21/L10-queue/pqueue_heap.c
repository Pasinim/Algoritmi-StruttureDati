#include <stdio.h>
#include <stdlib.h>
#define Item int
typedef Item *Heap;
//La posizione 0 dello haep non può essere utilzzata
/**
 * Dato che lo heap è un albero completo (quindi tutti i livelli sono pieni a parte lúultimo)
 * posso rappresentare l'albero come un array.
 * La priorità di un elemento sarà dato dalla sua profondità nell'albero.
 * La radice (profondità 0) ha priorità massima.
 */

struct pqueue{
    Heap h;
    int size, count;
};
typedef struct pqueue *Pqueue;

//crea una coda con size = s 
Pqueue pqueue_new (int s){
    Pqueue new = malloc(sizeof(struct pqueue));
    int *arr = malloc(sizeof(Item)*s+1);
    new -> h = arr;
    new -> size = s;
    new -> count = 0;
    return new;
}

int pqueue_length (Pqueue p){
    return p -> count;
}

void swap (int *a, int i, int j){
    int tmp = a[j];
    a[j] = a[i];
    a[i] = tmp;
    return;
}

void heapify_up(Heap h, int i) {
    if (i > 1){
        int j = i/2;
        if (h[i] > h[j]){
            swap(h, i, j);
            heapify_up(h, j);
        }
    }
}

void heapify_down (Heap h, int i, int n){
    if (2*i <= n){
        int j;
        if (2*i == n)
            j = 2 * i;
        else 
            j = 
    }
}

void print_arr(int *a, int len){
    printf("[ ");
    int *p;
    for (p = a; p < a + len; p++)
        printf("%d ", *p);
    printf("]\n");
}

Item pqueue_min (void){//(Pqueue p){
}

void main (){
    int a[] = {1,2,3,4};
    print_arr(a, 4);
    swap(a, 0, 1);
    print_arr(a, 4);
    
}
