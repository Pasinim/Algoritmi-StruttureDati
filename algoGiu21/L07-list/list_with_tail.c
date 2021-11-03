#include <stdlib.h>
#include <stdio.h>

struct node{
    int info;
    struct node *next;
};
typedef struct node *Node;

typedef struct{
    Node head;
    Node tail;
} *Bi_list;

Node new_node (int n){
    Node new = malloc(sizeof(Node));
    new -> info = n;
    new -> next = NULL;
    return new;
}

void add_end(Bi_list b, int n){
    Node new = new_node(n);
    if (b -> tail == NULL) { //lista vuota
        b -> tail = new;
        b -> head = new;
    }else{
        b -> tail -> next = new;
        b -> tail = new;
    }
}

void print_bi(Bi_list b){
    Node curr = b -> head;
    while (curr != NULL){
        printf("%d ", curr -> info);
        curr = curr -> next;
    }
}


int main (void){
    Bi_list b = malloc(sizeof(Bi_list));
    //Node l = malloc(sizeof(Node));
    add_end(b, 1);
    add_end(b, 2);
    print_bi(b);


}

