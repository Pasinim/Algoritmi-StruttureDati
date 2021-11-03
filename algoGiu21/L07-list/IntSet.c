#include <stdio.h>
#include <stdlib.h>

struct node {
    int value; 
    struct node *next;
};
typedef struct node *Node;

// Return 1 if ins contains n, 0 otherwise
int contains (Node ins, int n){
    while (ins != NULL){
        if (ins -> value == n) return 1;
        ins = ins -> next; 
    }
    return 0;
}

Node add (Node ins, int n){
    Node new = malloc(sizeof(struct node));
    new -> value = n;
    new -> next = ins; 
    ins = new;
    return ins;
}

void print_inv(Node ins){
    if (ins == NULL) return;
    print_inv(ins -> next);
    printf("\t%d\n", ins -> value);
}

void print_intSet(Node ins){
    printf("{ ");
    while (ins -> next != NULL){
        printf("%d, ", ins -> value);
        ins = ins -> next;
    }
    printf ("%d } \n", ins -> value);
}

void remove_el(Node ins, int n){
    Node prev = NULL;
    Node curr = ins;
    if (contains(ins, n) == 0) return; //se non c'è l'elemento     
    while (curr != NULL && curr -> value != n){
        prev = curr;
        curr = curr -> next;
    }
    if (prev == NULL){
        *ins = *ins -> next; 
        //METTO IL PUNTATORE PERCHÈ È UNa variabile locale, quindi senza il puntatore non modifica l'inizio della lista
        return;
    }
    prev -> next = curr -> next ;
    free(curr);    
}


void delete_all(Node ins){
    while (ins != NULL){
        *ins = *ins -> next;
        //free(ins);
    }
    // Node tmp;
    // while (ins != NULL){
    //     tmp = ins;
    //     ins = ins -> next;
    //     free(tmp);
    // }
    return;
}


int main (void){
    char c;
    int n;
    Node intSet = malloc(sizeof(Node));

    while ((c = getchar()) != 't'){
        switch (c){
            case 'd': 
                delete_all(intSet);
                break;
            case 'o':
                print_inv(intSet);
                break;
            case '-':
                scanf("%d", &n);
                remove_el(intSet, n);
                break;  
            case '+':
                scanf("%d", &n);
                if (contains(intSet, n) == 0)  
                   intSet = add(intSet, n); 
                break;
            case '?':
                scanf("%d", &n);
                if (contains(intSet, n) == 1)
                    printf("%d appartiene all'insieme\n", n);
                else 
                    printf("%d NON appartiene all'insieme\n", n);
                break;
            case 'p':
                print_intSet(intSet);
                break;
        }
    }    
}