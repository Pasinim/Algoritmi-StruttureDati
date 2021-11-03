#include <stdio.h>
#include <stdlib.h>
typedef int Item;
typedef Item *Heap;
struct pqueue{
    Heap h;
    int size, count;
};
typedef struct pqueue *Pqueue;

/* crea una coda di priorità vuota che potrà contenere al massimo n Item */
Pqueue pqueue_new( int n );
/* distrugge la coda di priorità */
void pqueue_destroy ( Pqueue );
/* restituisce la lunghezza della coda di priorità */
int pqueue_length ( Pqueue );
/* inserisce l’Item nella coda di priorità */
void pqueue_insert ( Pqueue , Item );
/* estrae dalla coda di priorità l’Item con chiave minima */
Item pqueue_extractmin ( Pqueue );
/* restituisce l’Item con chiave minima nella coda di priorità */
Item pqueue_min( Pqueue );

void pqueue_sort(Item a[], int l, int r);
void heapify_up(Heap h, int i);
void heapify_down(Pqueue p, int i);
void swap(Heap h, int i, int j);

void swap(Heap h, int i, int j){
    Item tmp=h[i];
    h[i]=h[j];
    h[j]=tmp;
}

Pqueue pqueue_new(int n){
    Pqueue p=malloc(sizeof(struct pqueue));
    Heap x=malloc(sizeof(int)*10);
    p->h=x;
    p->size=n;
    p->count=0;
    return p;
}

void pqueue_destroy(Pqueue p){
    for (int i=0; i<p->count; i++){
        free(p->h+i);
    }
    free(p);
}
int pqueue_length(Pqueue p){
    return p->count;
}

void pqueue_insert(Pqueue p, Item i){
    p->count++; //lo incremento subito dato che la posizione 0 non viene considerata
    if (p->count<=p->size){
        p->h[p->count]=i;
        heapify_up(p->h, p->count);
    }
}

void pqueue_print(Pqueue p){
    for (int i=1; i<=p->count; i++){
        printf("%d ", p->h[i]);
    }
    printf("\n");
}

void heapify_up(Heap h, int i){
    if (i>1){
        int j=i/2;
        if (h[i]< h[j]){
            swap(h,i,j);
            heapify_up(h, j);
        }
    }
}

void heapify_down(Pqueue p, int i){
    int n=p->count;
    if (2*i<=n){
        int j;
        if (2*i==n)
            j=2*i;
        else{
            if (p->h[2*i]<p->h[2*i+1]){
                j=2*i;
            }else{
                j=2*i+1;
            }
        }
        if (p->h[j]<p->h[i]){
            swap(p->h, i, j);
            heapify_down(p, j);
        }
    }  
}