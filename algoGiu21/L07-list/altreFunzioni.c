#include <stdlib.h>
#include <stdio.h>

struct node {
    int value;
    struct node *next;
};
typedef struct node *Node;

void l_insert_riferimento(Node *l, int v){
    Node new = malloc(sizeof(struct node));
    new -> value = v;
    new -> next = *l;
    *l = new;
}

void list_printInv( Node l ) {
     if (l -> next == NULL) 
          return;
     list_printInv(l->next);
     printf("%d\n", l->value);
}
//Scrivete una funzione che, data una lista, costruisce un array con gli elementi della lista e ne restituisce l’indirizzo;
//l’array va allocato dinamicamente.

int *toArr(Node l){
     int *a = malloc(sizeof(int) * 10);
     for (int i=0; l -> next != NULL; i++, l = l -> next){
          a[i] = l -> value;
     }
     return a;
}

void print_arr(int *a, int size){
     int *p;
     for (p = a; p < a + size; p++)
          printf("%d ", *p);
     printf("\n");
}

void list_destroy (Node root){
     Node tmp;
     while (root != NULL){
          tmp = root;
          root = root -> next;
          free(tmp);
     }
}

int main(){
     Node root = malloc(sizeof(struct node));
     l_insert_riferimento(&root, 1); 
     l_insert_riferimento(&root, 2); 
     l_insert_riferimento(&root, 3); 
     list_printInv(root);
     int *a = toArr(root);
     print_arr(a, 3);
     list_destroy(root);
     list_printInv(root);

}