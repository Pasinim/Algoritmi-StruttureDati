#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct node *olist_insert( int n, struct node *l ) {
    struct node *prev = NULL;
    struct node *curr = l;
    struct node *new = malloc (sizeof(struct node));
    new -> value = n;
    while (curr != NULL && curr -> value < n){
        prev = curr; 
        curr = curr -> next; 
    }
    if (prev == NULL){ //inizio lista 
        l = new;
        return l;
    }
    prev -> next = new;
    new -> next = curr;
    return l;
}

struct node *olist_search(int n, struct node *l){
    struct node  *tmp = l;
    while (tmp != NULL && tmp -> value < n)
        tmp = tmp -> next;
    return tmp; 
}

void print_node (struct node *l){
    printf("%d ", l -> value);
}

void print_list(struct node *l){
    while (l != NULL){
        print_node(l);
        l = l -> next;
    }
    printf("\n");
}

int main (){
    struct node *root = malloc(sizeof(struct node));
    root = olist_insert(1, root);
    root = olist_insert(3, root);
    root = olist_insert(2, root);
    root = olist_insert(10, root);
     root = olist_insert(5, root);
    //struct node *search = olist_search(2, root);
    //print_node(search);
    print_list(root);
}