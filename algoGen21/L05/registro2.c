#include <stdlib.h>
#include <stdio.h>
#define L0 10 //dimensione iniziale di 10
#define L 5 //incrementi successivi di 5
char *newBook(int n, char **reg){
    if (*reg!=NULL){
        printf("Il registro non era vuoto, lo cancello...\n");
        free(reg);
    }
    printf("%s\n", *reg);
    reg=malloc(sizeof(char)*n);
    return *reg;
}
int main (){
    char **r=malloc(1);
    int size=5;
    *r="ciao";
    *r=newBook(size, r);
}