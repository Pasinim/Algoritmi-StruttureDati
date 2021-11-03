#include <stdlib.h>
#include <stdio.h>
#define L 20 //le stringhe hanno al massimo 20 lettere
//rappresento il registro come un array frastagliato
typedef char Stringa[L+1];

Stringa *newBook(int n, Stringa *reg){
    if (reg!=NULL) {
        printf("Il registro non era vuoto, lo cancello...\n");
        free(reg);
    }
    reg=malloc(sizeof(Stringa)*n);
    return reg;
}

int main (){
    int posti=2;
    Stringa *r = NULL;
    r[0]="pipipi";
    *r=newBook(posti, r);
}

