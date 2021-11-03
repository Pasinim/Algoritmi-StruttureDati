#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct node {
    int value;
    struct node *next;
    struct node *prev;
};
typedef struct node *Node;

struct bi_list {
    Node head; 
    Node tail;
} ;

typedef struct bi_list *Bi_list; 

int size (Bi_list b){
    int counter = 0;
    Node tmp = b -> head;
    while (tmp != NULL){
        counter++;
        tmp = tmp -> next;
    }
    return counter;
}

bool contains (Bi_list b, int n){
    Node l = b -> head;
    while (l != NULL ){
        if (l -> value == n) return true;
        l = l -> next;
    }
    return false;
}

Node new_node (int n){
    Node new = malloc(sizeof(struct node));
    new -> value = n; 
    new -> next = new -> prev = NULL;
    return new;
}

void delete_all(struct node *l){
    struct node *tmp;
    for (tmp = l; l -> next != NULL; ){
        printf("\tCancello %d ... \n", l -> value);
        tmp = l;
        l = l -> next;
        free(tmp);
    }
}

//EFFECTS: rimuove l'elemento in testa. Se la lista è vuota non fa nulla
void remove_start(Bi_list b){
    //printf("\tada\n");
    if (size(b) == 0) return;
    if ( size(b) == 1){
        free(b->head); //marco b->head come disponibile
        b -> head = NULL; //non ho piu` elementi
        return;
    }
    *b -> head = *b -> head -> next;
    return;
}

//EFFECTS: aggiunge n in testa alla lista.
void add_start (Bi_list b, int n){
    Node new = new_node(n);
    if (size(b) == 0){
        b -> head = b -> tail = new;
        return;
    }
    b -> head -> prev = new;
    new -> next = b -> head;
    b -> head = new;
    return;
}

Bi_list add_end (Bi_list b, int n){
    Node new = new_node(n);
    if (b -> tail == NULL){
        b -> head = b -> tail = new;
        return b;
    }
    b -> tail -> next = new;
    new -> prev = b -> tail;
    b -> tail = new;
    return b;
}

void remove_end (Bi_list b){
    if (size(b) == 0) return;
    if (size(b) == 1){
        free(b -> head);
        b -> head = NULL;
        return;
    }
    b -> tail = b -> tail -> prev;
    b -> tail -> next = NULL;
    return;
}

void print_bi_rev (Bi_list b){
    if (b -> tail == NULL){
        printf("[ ]\n"); 
        return;
    }
    Node tmp = b -> tail;
    printf("[ ");
    while (tmp != NULL)  {
        printf("%d ", tmp -> value );
        tmp = tmp -> prev;
    }
    printf("]\n");
}

void print_bi(Bi_list b){
    if (b -> head == NULL){
        printf("[ ]\n"); 
        return;
    } 
    Node tmp = b -> head;
    printf("[ ");
    while (tmp != NULL){
        printf("%d ", tmp -> value);
        tmp = tmp -> next;
    }
    printf("]\n");
}

void print_testacoda (Bi_list b){
    printf("\tHead: %d\n\tTail: %d\n", b -> head -> value, b -> tail -> value);
}

int main (void){
    Bi_list l = malloc(sizeof(Bi_list));
    add_start(l, 1);
    print_bi(l);
    add_start(l, 2);
    print_bi(l);
    add_start(l, 3);
    remove_end(l);
    //remove_end(l);
    remove_end(l);
    print_bi(l);
    printf("%s\n", contains(l, 2) ? "true":"false");
    // print_testacoda(l);
    // print_bi_rev(l);
    
}



