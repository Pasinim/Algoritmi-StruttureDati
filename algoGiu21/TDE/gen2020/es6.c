#include <stdio.h>
#include <stdlib.h>
/**
 * Voglio una funzione che incrementa tutti i nodi dell'albero
 */
struct node{
        int value;
        struct item *next;
    };
typedef struct node *Node;

struct bit_node{
    int value;
    struct bit_node *l, *r;
};
typedef struct bit_node *Bit_node;

Bit_node bit_new(int v){
    Bit_node new;
    new=malloc(sizeof(struct bit_node));
    new->value=v;
    new->l=new->r=NULL;
    return new;
}

void print_node(Bit_node b){
    printf("%d ",b->value );
}

void bit_inorder(Bit_node b){
    if (b!=NULL){
        bit_inorder(b->l);
        print_node(b);
        bit_inorder(b->r);
    }
}



void print_asummary(Bit_node b, int spaces){
    for (int i=0; i<spaces;i++)
        printf(" ");
    printf("*");
    if (b){
        print_node(b);
        printf("\n");
        if (b->l||b->r){
            print_asummary(b->l, spaces+1);
            print_asummary(b->r, spaces+1);
        }
    }else{
        printf("\n");
    }
    return;
}

void incrementa(Bit_node b){
    if (b != NULL){
        b -> value ++;
        if (b -> l != NULL)
            incrementa(b -> l);
        if (b -> r != NULL)
            incrementa(b -> r);
    }
    return;
}


int main (void){
    Bit_node root=NULL;
    root = bit_new(5);
    root -> r = bit_new(1);
    root -> l = bit_new(4);
    root -> r -> r = bit_new(11);
    root -> l -> l = bit_new(42);

    bit_inorder(root);
    printf("\n");
    incrementa(root);
    bit_inorder(root);    
}