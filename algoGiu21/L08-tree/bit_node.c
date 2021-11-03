#include <stdlib.h>
#include <stdio.h>

struct bit_node {
    int v; 
    struct bit_node *l, *r;
};
typedef struct bit_node *Bit_node;

Bit_node bit_new( int n ){
    Bit_node new = malloc(sizeof(struct bit_node));
    if (new == NULL) 
        EXIT_FAILURE;
    new -> v = n;
    new -> r = new -> l = NULL;
    return new;
    
};


void print_node(Bit_node b){
    printf("%d ",b->v );
}

void bit_preorder ( Bit_node b){
    if (b != NULL){
        print_node(b);
        bit_preorder(b -> l);
        bit_preorder(b -> r);
    }
}

void bit_inorder(Bit_node b){
    if (b!=NULL){
        bit_inorder(b->l);
        print_node(b);
        bit_inorder(b->r);
    }
}
void bit_postorder ( Bit_node b ){
    if (b!=NULL){
        bit_inorder(b->l);
        bit_inorder(b->r);
        print_node(b);
    }
};

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
Bit_node bit_arr2tree ( int a[], int size , int i){
    Bit_node b = NULL; //malloc (sizeof (struct bit_node));
    if (i<size){
        b = bit_new(a[i]);
        b -> l = bit_arr2tree(a, size, 2*i + 1);
        b -> r = bit_arr2tree(a, size, 2*i + 2);
    }
    return b;
}

void bit_printassummary(Bit_node p, int spaces){
    for (int i=0; i<spaces; i++)
        printf(" ");
    printf("*");
    if (p){
        print_node(p);
        printf("\n");
        if (p -> r || p -> l){
            bit_printassummary(p -> r, spaces+1 );
            bit_printassummary(p -> l, spaces+1 );
        }
    }
        else{
            printf("\n");      
    }
    return;
}


int main (){
    Bit_node root = malloc (sizeof(struct bit_node));
    int a[] = {69, 89, 28, 39, 66, 44, 12, 2, 71};
    root = bit_arr2tree(a, 9, 0);    
    bit_inorder(root);
    printf("\n");      
    bit_printassummary(root, 0);

}