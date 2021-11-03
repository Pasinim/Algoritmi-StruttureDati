#include <stdlib.h>
#include <stdio.h>

struct node {
    int value;
    struct node *next;
};

struct node *add_head(struct node *l, int n){
    struct node *new = malloc(sizeof(struct node));
    new -> value = n;
    new -> next = l;
    l = new;
    return l;
}

void print_l (struct node *l){
    for (; l -> next != NULL; l = l -> next)
        printf("%d ", l -> value);
    printf("\n");

}

void list_delete(struct node *l, int n){
    struct node *curr, *prev;
    for (curr = l, prev = NULL; curr != NULL; prev = curr, curr = curr -> next){
        printf("\t %d \n", curr -> value);
        if (curr -> value == n) break;
    }
    if (curr == NULL)
        return;
    if (prev == NULL)
        *curr = *curr -> next;
    else
        prev -> next = curr ->next;
    free(curr);
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

struct node *search(struct node *l, int n){
    for (; l -> next != NULL; l = l -> next)
        if (l -> value == n) break;
    return l;
}

struct node *list_search_ric (struct node *l, int n){
    if (l -> value == n)
        return l;
    return list_search_ric(l -> next, n);
}

void print_node (struct node *l){
    printf("%d \n", l -> value);
}

// Riscrivete la funzione list_insert in modo che modifichi direttamente il puntatore alla testa della lista passata
// come argomento. Per farlo è opportuno passare tale puntatore per riferimento, quindi il secondo argomento passato
// alla funzione deve essere l’indirizzo del puntatore in cui è memorizzato l’indirizzo del primo elemento della lista.

void insert_riferimento (struct node **l, int n){
    struct node *new = malloc(sizeof(struct node));
    new -> next = *l;
    new -> value = n; 
    *l = new;
}
int main(){
    struct node *root = malloc(sizeof(struct node));
    root = add_head(root, 1);
    root = add_head(root, 2);
    root = add_head(root, 3);
    insert_riferimento(&root, 3);
    print_l(root);

    struct node *found = list_search_ric (root, 2);
    print_node(found);
    //print_l(root);
    // list_delete(root, 2);
    // print_l(root);
    // list_delete(root, 3);
    // print_l(root);
    // list_delete(root, 1);
    // print_l(root);
}