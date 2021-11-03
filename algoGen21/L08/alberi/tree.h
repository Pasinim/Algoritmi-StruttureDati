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

Bit_node insert_inorder(Bit_node b, int n){
    Bit_node new;
    if ( b==NULL){
        new=bit_new(n);
        return new;
    }
    if (n<b->value){
        b->l=insert_inorder(b->l, n);
    }else{
        b->r=insert_inorder(b->r, n);
    }
    //con il return esce dalla chiamata a funzione, se è la prima torna nel main,
    //altrimenti torna prima delle altre. Accumula così le chiamate a funzione
    return b;
}


Bit_node insert_inorder_sbagliato(Bit_node b, int n){
    Bit_node new;
    new=bit_new(n);
    if (b==NULL){ //se l'albero new è la radice
        return new;
    }
    if (n>=b->value) { //se è maggiore mi sposto a dx
        if (b->r==NULL){ //se non ha foglie aggiungo il nodo
        //fare così è sbagliato, dato che il caso di null è già incluso nell'if sopra
            b->r=new;
            return b; 
        }else{ //se ha figli scendo ancora, quindi richiamo la funzione
            b=insert_inorder(b->r, n);
        }
    }else{ //se n è minore mi sposto a sinistra
        if (b->l==NULL){
            b->l=new;
            return b;
        }else{
            b=insert_inorder(b->l, n);
        }
    }
    return b;
}

void print_asummary(Bit_node b, int spaces){
    for (int i=0; i<spaces;i++)
        printf(" ");
    printf("*");
    if (b){
        print_node(b);
        printf("\n");
        if (b->l||b->r){
            print_asummary(b->l, spaces++);
            print_asummary(b->r, spaces++);
        }
    }else{
        printf("\n");
    }
    return;
}
