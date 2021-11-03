#include <stdlib.h>
#include <stdio.h>



Node new_node(int n){
    Node new = malloc(sizeof(struct item));// calloc(1, sizeof(struct item));
    new -> data = n;
    new -> next = NULL;
    return new;
}

Node add(Node h, int n){
    Node new=malloc(sizeof(struct item));
    new->data=n;
    //Node new = new_node(n);
    new -> next = h;
    return new;
}

void print_list(Node l){
    Node tmp;
    for ( tmp=l; tmp!=NULL; tmp=tmp->next){
        printf("%d ", tmp->data);
    }
    printf("\n");
}

int f(Node p){
    return (  //1 se la lista è ordinata in modo non decrescente
        (p == NULL) ||
        (p -> next == NULL) ||
        ((p -> data <= p -> next -> data)
            && f(p -> next))
    );
}

int main (void){
    Node root = NULL;
    root = add(root, 4);
    root = add(root, 3);
    root = add(root, 2);
    root = add(root, 1);


    print_list(root);
    printf("%d\n", f(root));
}