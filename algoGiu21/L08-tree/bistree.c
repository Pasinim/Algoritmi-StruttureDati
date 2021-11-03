#include <stdio.h>
#include <stdlib.h>
#define Item int 
#define Key int

struct bit_node{
    Key value;
    struct node *l, *r;
};
typedef struct bit_node *Bit_node;

Bit_node search(Bit_node p, Key k){
    while (p -> r != NULL || p -> l != NULL){
        if (p -> value == k) return p;
        if (k < p -> value) 
            p = p -> l;
        else
            p = p -> r; 
    }
    return NULL;
}