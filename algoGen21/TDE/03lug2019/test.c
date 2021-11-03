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

 int main(void) {
     // Testing main
     Bit_node root ;
     // Testing vettore -> albero
     printf("\ntesting array to albero:\n");
     int a[] = {69, 89, 28, 39, 66, 44, 12, 2};
    root = bit_arr2tree (a, 8, 0);


     printf("stampa indentata:\n");
     print_tree ( root , 0 );

     printf("\n");
     return 0;
}