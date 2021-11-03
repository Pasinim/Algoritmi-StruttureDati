#include <stdio.h>
#include <stdlib.h>
#define SIZE 3//lunghezza iniziale dell'array
struct node {   
  int info;   
  struct node *next;
};
typedef struct node *Node;

struct node *list_insert( int n, struct node *l ){
  struct node *new = malloc( sizeof(struct node) );
  if (new==NULL){
      printf("Allocazione fallita\n");
      exit(EXIT_FAILURE);
  }
  new -> info = n;
  new -> next = l;
  return new; 
}

struct node *list_search( int n, struct node *l ){
  while ( l != NULL && l -> info != n )
        l = l -> next;
  return l;
}

void stampa(Node n){
    while (1){
        if (n==NULL) break;
        printf("%d\t", n->info);
        n=n->next;
    }
    printf("\n");
}

void stampa_inv(struct node *n){
    if (n->next==NULL) return;
    stampa_inv(n->next);
    //printf("%d\t%p\n", n->info, &n);
    printf("%d\t", n->info);
}

int *toArray(struct node *n){
    int counter=0, len=SIZE;
    int *a = malloc(len); //array in cui inserisco i valori
    //struct node *p=malloc(sizeof(struct node));
    int *p;
    //int *tmp;
    for (p=a; ; p++) {
        if (n->next==NULL) break;
        if (counter>len){
            printf("Aumento la dimensione...\n");
            a=realloc(a, len+=2);
        }
        *p=n->info;
        //printf("\nValore di *p: %d:\t Indirizzo di p: %p", *p, &p);
        //printf("\tValore di *a: %d:\t Indirizzo di a: %p", *a, &a);
        n=n->next;
        counter++;
    }
    printf("\n");
    return a;
}
//non so come fare la ricorsione
// void destroy_rec(struct node *n){
//     if (n->next==NULL) return;
//    free(n);
//     destroy_rec(n->next);

// }


void destroy(struct node *n){
    printf("Cancello la lista...\n"); 
    Node tmp=malloc(sizeof(struct node));
    while (n!=NULL){
        tmp=n->next;
        free(n);
        n=tmp;
    }
    return;
}

struct node *cerca(struct node *l, int n){
    struct node *p;
    for (p=l; p!=NULL;p=p->next){   
        printf("\tSto cercando %d nella lista...\n", n);
        printf("\t\tValore; %d\n", p->info);
        if (p->info==n){
            printf("\t\tTrovato!\n");
            return p;
        }
    }
    printf("\t\tNon trovato\n");
    return l;
}    


int main(){
    struct node *first =malloc(sizeof(struct node));
    //printf("%d\n", first->info); //All'inizio il valore del primo nodo è impostato a 0.
    first=list_insert (1, first);
    first=list_insert (2, first);
    first=list_insert(3, first);
    printf("Ordine corretto: ");stampa(first);
    printf("Orine inverso  : "); stampa_inv(first);
    int *arr = malloc(SIZE);
    arr=toArray(first);
    printf("Array   :%d\t%d\t%d\n", arr[0], arr[1], arr[2]);
    //destroy(first);
    //first = malloc(sizeof(struct node));
    //first=list_insert(10, first);
    //stampa(first);
    printf("_____________\n");
    //----ESERCIZIO 4
    struct node *search=malloc(sizeof(struct node));
    search=cerca(first, 2);    
    printf("valore *search: %d\n", search->info);

}

