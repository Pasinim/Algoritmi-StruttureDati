#include <stdio.h>
#include <stdlib.h>
#include "albero.h"


void print_tree ( Bit_node b, int spaces ) {
     for (int i = 0; i < spaces; i++)
          printf(" ");

     printf("*");
     if (b!=NULL) {
          bit_printnode(b);
          printf("\n");
          if (b->l || b->r) {
              //se uno dei due è null stampa solamente l'asterisco
               print_tree(b->l, spaces+1);
               print_tree(b->r, spaces+1);
          }
     } else {
          printf("\n");
     }
     return;
}

void insert(Bit_node b, int n){
    Bit_node new= malloc(sizeof(struct bit_node));
    new=bit_new(n);
    if (b==NULL) {
        b=new;
    }
    if (n>=b->value){ //vado a dx
        if (b->r==NULL){ //se il figlio è vuoto lo inserisco
            b->r=new;
            return;
        }else{
            insert(b->r, n);
        }
    }else{ //se n<b vado a sx
        if (b->l==NULL){ //se il figlio è vuoto lo inserisco
            b->l=new;
            return;
        }else{
            insert(b->l, n);
        }
    }
    printf("errore\n");
    return;
}