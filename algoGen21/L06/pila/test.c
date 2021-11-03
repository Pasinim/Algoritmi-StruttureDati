#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
struct node {
    int value;
    struct node *next;
};
typedef struct node *Node;

int main (){

    Node a;
    a->value = 1;
    printf("%d\n", a->value);
}