#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
struct node {
    int value;
    struct node *next;
};
typedef struct node *Node;
Node stack = NULL;
int size=0, dim=4;

void push (int n){
    if (size<dim){
    Node new=malloc(sizeof(struct node));
    new->value=n;
    new->next=stack;
    stack=new;
    size++;
    //printf("fine primo push\n");
    }else{
        printf("Alloco spazio\n");
        dim+=2;
        stack=realloc(stack, sizeof(int)*dim);
        push(n);
    }
}

int is_empty(void){
    if (stack==NULL){
        printf("Stack vuoto\n");
        return 1;
    }
    return 0;
}
void print_stack(void){
    Node tmp=malloc(sizeof(struct node));
    int s =size;
    for (tmp=stack; tmp!=NULL; tmp=tmp->next){
        printf("| stack[%d]: %d |\n", s--, tmp->value );
    }
    printf("\n");
    if (stack==NULL){
        printf("Lo stack è vuoto\n");
    }
}

int top(void){
    if (is_empty()){
        printf("Non posso fare la top, lo stack è vuoto\n");
        exit(EXIT_FAILURE);
    }
    return stack->value;
}
int pop (void){
    if (is_empty()){
        printf("Non posso fare la pop, lo stack è vuoto\n");
        exit(EXIT_FAILURE);
    }
    int n = stack->value;
    Node tmp=malloc(sizeof(struct node));
    tmp=stack->next;
    free(stack);
    stack=tmp;
    size--;
    return n;
}

void make_empty(void){
    Node tmp=malloc(sizeof(struct node));
    for (; stack!=NULL; stack=stack->next){
        tmp=stack->next;
        free(stack);
        stack=tmp;
    }
    printf("Ho cancellato lo stack\n");
}

int main (void){
    push(1); push(2); push(3); push(4);
    print_stack();
    push(5);    
    print_stack();
    printf("top %d\n", top());
    printf("pop %d\n", pop());
    print_stack();
    make_empty();
    print_stack();
}