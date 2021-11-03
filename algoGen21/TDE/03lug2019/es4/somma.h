#include <stdio.h>
#include <stdlib.h>

struct bit_node {
    int n; 
    struct bit_node *l, *r;
    int lavoratori; 
};
typedef struct bit_node *Bit_node;

Bit_node new_node(int n){
    Bit_node new;
    new= malloc(sizeof(struct bit_node));
    new->n=n;
    new->l=new->r=NULL;
    return new;
}

Bit_node arr2tree(int a[], int size, int i){
    Bit_node root=NULL;
    if (i<size){
    root=new_node(a[i]);
    root->l=arr2tree(a, size, 2*i+1);
    root->r=arr2tree(a, size, 2*i+2);
    }
    return root;
}

//vorrei implementare una funzione in grado di fare la somma di tutti i nodi
//posso trasformare l'albero in un vettore e poi sommare i suoi componenti

int *arr (Bit_node root){
    int size=0;
    
}
int lavoratoriTotali (Bit_node root, int lavoratori){
    int sum=lavoratori;


}