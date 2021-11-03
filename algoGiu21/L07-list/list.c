#include <stdlib.h>
#include <stdio.h>

struct node {
    int value;
    struct node *next;
};
typedef struct node *Node;

Node new_node (int n, Node r){
    Node new = malloc(sizeof(struct node));
    new -> value = n;
    r -> next = new;
    new -> next = NULL;
    return r;
}

  Node list_insert_head(int v, Node first){
    Node new = malloc(sizeof(struct node));
    new -> value = v;
    new -> next = first; 
    first = new; 
    return first;
}

Node list_insert_tail(int v, Node n){
    Node tmp = NULL;
    printf("lsit inster\n");
    Node new = malloc(sizeof(struct node));
    new -> value = v;
    if (n == NULL){
        printf("v\n");
            n = new ;
            return n;
    }

    for (tmp = n; n != NULL ; ){
        n = n -> next; 
        tmp = n;
    }
    tmp -> next = new; 
    printf("lsit inster 2\n");

    return n;
}

void print_list(Node n){
    for (   ; n != NULL ; n = n -> next )
        printf("%d ", n -> value);
    printf("\n");
}

Node list_search(int v, Node first){
    Node tmp = NULL;
    for (tmp = first; ; ){
        if (first == NULL){
            printf("Non trovato \n");
            return first;
        }
        if (first -> value == v)
            return first;
        first = first -> next; 
        tmp = first;
    }
    return tmp;

}

void list_delete2(Node root, int n){
    Node curr, prev;
    for (curr=root, prev=NULL; curr!=NULL; prev=curr, curr=curr->next){
        if (curr->value==n) break;
    }
    if (curr==NULL) {
        printf("Elem non tovato\n");
        return;
    }
    if (prev==NULL) {
        printf("\tElemento in pria posizione\n");
        *root=*root->next; //devo passare l'indirizzo, passo per riferimento non per variabile
    }else{
        prev->next=curr->next;
    }
    printf("\tRimuovo %d\n", curr->value);
    free(curr);
    //return root;
}

void list_delete(int v, Node first){
    printf("111");
    Node curr, prev;
    for ( curr = first, prev = NULL; curr != NULL ; prev = curr, curr = curr -> next){
        printf("a222");
        if (curr -> value == v) break;
    }
    if (prev == NULL){
        printf("adada");
        *curr = *curr -> next;
    }
    if (curr == NULL)
        return; 
    else 
        prev -> next = curr -> next;
    free(curr);
    //return;
    }

int main (void){
    Node root = NULL;
    root = list_insert_head(1, root);
    root = list_insert_head(3, root);
    root = list_insert_head(2, root);
    print_list(root);
    //Node found = list_search(2, root);
  //  printf("Trovato %d \n", found -> value);
    printf("asd");
    list_delete2( root, 2);
    print_list(root);
    list_delete2( root, 1);
    //list_delete( 2, root);
    print_list(root);
}