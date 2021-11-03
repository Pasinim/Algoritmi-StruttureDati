#include <stdlib.h>
#include <stdio.h>
#define L 8
struct bit_node{
    int item;
    struct bit_node *l, *r;
};
typedef struct bit_node *Bit_node;

int *array(int n);
void stampa(int a[], int n);
Bit_node bit_new(int n);
Bit_node arr2tree(int a[], int size, int i);
void bit_printassummary(Bit_node p, int spaces);
void bit_preorder(Bit_node);
void bit_inorder(Bit_node);
void bit_postorder(Bit_node);

int main (){
    int a[L]={1,2,3,4,5,6,7,8};
    stampa(a, L);
    Bit_node root;
    root=arr2tree(a, L, 0);
    bit_preorder(root);
    printf("\n");
    bit_printassummary(root, 0);
}

int *array(int n){
    int *a=malloc(sizeof(int)*n);
    for (int i=0; i<n; i++){
        a[i]=rand()%100;
    }
    return a;
}

void stampa (int a[], int n){
    for (int i=0; i<n;i++){
        printf("%d\t", a[i]);
    }
    printf("\n");
}

Bit_node bit_new(int n){
    Bit_node new=malloc(sizeof(struct bit_node));
    //se metto sizeof(Bit_node) mi da segfault
    if (new==NULL){
        printf("Errore allocazione\n");
        exit(EXIT_FAILURE);
    }
    new->item=n;
    new->l=NULL;
    new->r=NULL;   
    return new; 
}
Bit_node arr2tree(int a[], int size, int i){
    Bit_node root=NULL;
    //printf("Valore iniziale root; %d\n", root->item);
    if (i<size){
        root=bit_new(a[i]);
        root->l=arr2tree(a, size, 2*i+1);
        root->r=arr2tree(a, size, 2*i+2);        
    }
    return root;
}

void bit_printassummary(Bit_node p, int spaces){
    for (int i=0; i<spaces; i++){
        printf(" ");
    }
    printf("*");
        if (p){
            printf("%d \n", p->item);
            if (p->r||p->l){
                bit_printassummary(p->l, spaces+1);
                bit_printassummary(p->r, spaces+1);
                }
            }else{ //se non ha un figlio stampo solamente l'asterisco
                printf("\n");
        }
}

void bit_preorder(Bit_node p){
    if (p){
        printf("%d ", p->item);
        bit_preorder(p->l);
        bit_preorder(p->r);
    }
}