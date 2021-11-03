#include <stdio.h>
#include <stdlib.h>
struct bit_node{
    struct bit_node *r, *l;
    int value;
};
typedef struct bit_node *Bit_node;

void inorder(Bit_node b);

//inserisco n nella posizione corretta
void insert(Bit_node b, int n); 

void print_tree(Bit_node b, int spaces);

void bit_printnode(Bit_node p) {
     printf("%d ", p->value);
}
Bit_node bit_new(int n){
    Bit_node b = malloc(sizeof(struct bit_node));
    b->value=n;
    b->l=b->r=NULL;
    return b;
}

Bit_node bit_arr2tree ( int a[], int size , int i) {
     // int a[] = {69, 89, 28, 39, 66, 44, 12, 2, 71};      size = 9, i = 0 : indice dell'elemento che vuoi mettere nell'albero
     Bit_node root = NULL;
     if (i < size) {
          root = bit_new(a[i]);
          root -> l = bit_arr2tree(a, size, 2*i+1);
          root -> r = bit_arr2tree(a, size, 2*i+2);
     }
     return root;
}
