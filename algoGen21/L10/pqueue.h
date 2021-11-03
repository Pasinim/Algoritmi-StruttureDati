//da rifare, da segfault


#include <stdio.h>
#include <stdlib.h>
typedef int Item;
typedef struct pqueue *Pqueue;
typedef Item *Heap;
struct pqueue{
    Heap h; //ho un vettore di tipo Item
    int size, count;
    //size indica la dimensione massima, count indica la posizione riempita fino ad un certo momento
};

void heapify_up(Heap h, int i);

/*crea una coda di priorità vuota che potrà contenere al massimo n Item*/
Pqueue pqueue_new(int n ){
    Item new[n]; //sto creando un vettore di int, se Item è di tipo int
    Pqueue p = malloc(sizeof(struct pqueue));
    p->h=new;
    p->size=n+1; //aggiungo 1 perchè la posizione 0 non viene utlizzata
    //la prima posizione dell'array è IGNORE, inizio a calcolare gli elementi dell'array partendo da h[1]
    p->count=0;
    return p;
}

/*distrugge la coda di priorità*/
void pqueue_destroy( Pqueue p );

/*restituisce la lunghezza della coda di priorità*/
int pqueue_length( Pqueue p ){
    return p->size;
};

/*inserisce l’Item nella coda di priorità*/
void pqueue_insert( Pqueue p, Item item ){
    if (p->size==p->count){
        printf("La coda è già stata riempita completamente\n");
        return;
    }
    //printf("Sto inserendo %d: \n", item);
    p->count=p->count+1; //non sto considerando la posizione0, quindi prima incremento e poi aggiungo
    int index = p->count; //posizione in cui dovrò inserire il nuovo elemento dello heap
    p->h[index]=item; //inserisco item nel vettore
    //printf("ho inserito %d:\t count vale: %d\n", *(p->h+p->count), p->count);
    //if (p->count>1)
    heapify_up(p->h, index);
};

void swap(Item item[], int i, int j){
    Item tmp=item[i];
    item[i]=item[j];
    item[j]=tmp;
    return;
}

/*restituisce l’Item con chiave minima nella coda di priorità*/
Item pqueue_min( Pqueue p){
    return p->h[1];
};


void heapify_up(Heap h, int i){ //i è la posizione del nuovo elemento nell'array?
    if (i>1){
        int j=i/2; //j è la posizione del padre nell'array
        //printf("padre pos: %d\n", j);
          //  printf("h[%d]: %d >h[%d]: %d \n", j, i, h[j], h[i]);
        if (h[j]>h[i]){
            swap(h, i ,j);
            heapify_up(h, j);
        }
    }
};
void heapify_down(Pqueue p, int i){
    int n=p->count;
    if (i*2<=n){ //se i ha almeno un figlio
        int j; //indice del figlio con chiave minore
        if (2*i==n) //se i ha solamente il figlio sinistro
            j=2*i;
        else{ //se i ha due figli devo trovare la chiave minore
            if (p->h[2*i]<p->h[2*i+1])
                j=2*i;
            else 
                j=2*i+1;
        }
        if(p->h[i]>p->h[j]){
            swap(p->h,i,j);
            heapify_down(p,j);
        }
    }
}
/*estrae dalla coda di priorità l’Item con chiave minima*/
Item pqueue_extractmin( Pqueue p ){
    Item res = p->h[1];
    int index=p->count;
    swap(p->h,1,index); //sposto il primo elemento in fondo e successivamnete decremento la lunghezza, in questo modo è come se lo eliminassi
    p->count=p->count-1;
    //se l'heap non è corretto lo sistemo
    if ((p->h[1]>p->h[2]||p->h[1]>p->h[3])){
        heapify_down(p,1);
    }
    return res;
};

void stampa(Pqueue p){
    for ( int i=1; i<p->count;i++){
        //parto dal primo indice perchè h[0] non viene considerata
        printf("%d\t", p->h[i]);
    }
    printf("\n");
};

/* crea una nuova coda di priorità Q
  inserisci in Q un elemento di a alla volta
  finchè Q non è vuota
    estrai il minimo m da Q
    stampa m
*/
//ordina la porzione dell'array compresa tra gli indici l e r
void pqueue_sort(Item a[], int l, int r){
    int value, len=r-l;
    //Pqueue q=malloc(sizeof(struct pqueue));
    Pqueue q=pqueue_new(len);
    for (int i=l; i<r; i++){
        printf("Sto inserendo %d nella coda...\n", a[i]);
        pqueue_insert(q, a[i]);
    }
    for (int i=1; i<=len; i++){
        value=pqueue_extractmin(q);
        printf("%d ", value);
    }
    printf("\n");
}