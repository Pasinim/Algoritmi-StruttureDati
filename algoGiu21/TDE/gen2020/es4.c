#include <stdlib.h>
#include <stdio.h>

struct item{
    int data;
    struct item *next;
};

struct item *new_node(int n){
    struct item *new = malloc(sizeof(struct item));// calloc(1, sizeof(struct item));
    new -> data = n;
    new -> next = NULL;
    return new;
}

struct item *add(struct item *h, int n){
    struct item *new = new_node(n);
    new -> next = h;
    h = new;
    return h;
}

void stampa(struct item *h){
    struct item *tmp = h;
    while (tmp != NULL){
        printf("%d ", tmp -> data);
        tmp = tmp -> next;
    }
    printf("\n");
}

int f(struct item *p){
    return (  //1 se la lista è ordinata in modo non decrescente
        (p == NULL) ||
        (p -> next == NULL) ||
        ((p -> data <= p -> next -> data)
            && f(p -> next))
    );
}

int main (void){
    struct item *root = calloc(1, sizeof(struct item));
    root = add(root, 4);
    root = add(root, 3);
    root = add(root, 2);
    root = add(root, 1);


    stampa(root);
    printf("%d\n", f(root));
}