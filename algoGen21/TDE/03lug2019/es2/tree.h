#include <stdio.h>
#include <stdlib.h>

struct bit_node{
    struct bit_node *l, *r;
    int value;
};
typedef struct bit_node *Bit_node;

Bit_node bit_new (int v);
void print_node(Bit_node b);
//inserisce il valore nell'albero binario DI RICERCA
Bit_node insert_inorder(Bit_node b, int n);
void print_asummary(Bit_node b, int spaces);
void bit_preorder( Bit_node b );
void bit_inorder( Bit_node b);
void bit_postorder( Bit_node b);

Bit_node bit_new(int v){
    Bit_node new;
    new=malloc(sizeof(struct bit_node));
    new->value=v;
    new->l= NULL;
    new->r=NULL;
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

void bit_postorder(Bit_node b){
    if (b){
        bit_postorder(b->l);
        bit_postorder(b->r);
        print_node(b);
    }
}

void bit_preorder(Bit_node b){
    if (b){
        print_node(b);
        bit_inorder(b->l);
        bit_preorder(b->r);
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

//non credo che questa funzione sia corretta. Infatti quando inserisco un nuovo figlio
//non restituisco più l'albero "iniziale" ma ho solamente il figlio
Bit_node insert_inorder(Bit_node b, int n){
    Bit_node new;
    if ( b==NULL){
        new=bit_new(n);
        return new;
    }
    if (n<b->value){
        b->l=insert_inorder(b->l, n); //qui richiamo la funzione passando il ramo sx. Come posso riotterenere l'albero iniziale?
    }else{
        b->r=insert_inorder(b->r, n);
    }
    //con il return esce dalla chiamata a funzione, se è la prima torna nel main,
    //altrimenti torna prima delle altre. Accumula così le chiamate a funzione
    return b;
}

Bit_node arr2tree( int a[], int size, int i){
    Bit_node root=NULL;
    if (i<size){
    root=bit_new(a[i]);
    root->l = arr2tree(a, size,2*i+1 );
    root->r=arr2tree(a, size, 2*i+2);
    }
    return root;
}