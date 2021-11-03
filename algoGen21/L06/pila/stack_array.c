#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#define N 4 //lugnhezza iniziale della pila

int *stack=NULL; 
int size=0, dim=4;

int main (){
    push(4);
    push(3);
    printf("stack[0]: %d\tstack[1]:%d\n", *(stack), *(stack+1));
    push(2);
    push(1);
    //print_stack();
    printf("top= %d\n", top());
    pop();
    print_stack();
    make_empty();
    print_stack();

}

void make_empty(void){
    free(stack);
    stack=NULL;
    size=0;
}

int is_empty(void){
    if (stack==NULL){
        return 1;
    }else{
        return 0;
    }
}

int top (void){
    if (is_empty()) {
        printf("Stack vuoto\n");
        exit(EXIT_FAILURE);
    }
        return stack[size-1];
}


int pop(void){
    if (is_empty()) {
        printf("Stack vuoto\n");
        exit(EXIT_FAILURE);
    }
    int n=*(stack+size);
   // *(stack+size-1)=0;
  //  size--;
    stack=realloc(stack, (--n));
    return n; 
}
void push (int n){
    if (stack==NULL){
        stack=malloc(dim);
    }
    if (size>dim){
        printf("Non c'è più spazio\n");
        exit(EXIT_FAILURE);
    }
    size++;
    *(stack+size-1)=n;
}

void print_stack(void){
    printf("size=%d\n", size);
    for (int i=size; i>0;i--){
        printf("| stack[%d]: %d |\n", i-1, *(stack+i-1));
    }
    printf("\n");
}
