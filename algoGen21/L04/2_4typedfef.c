#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define lun 7
typedef char String[lun+2]; //perchè devo mettere +2??
int smallest_word_index(String s[], int n){
    char tmp[]="zzzzz";
    //char *tmp= malloc(100);
    int pos=0;
    // ciclo le parole
    for (int i=0; i < n-1; i++){
        if (strcmp(s[i], tmp) < 0){
            *tmp=*s[i];
            pos=i;
        }
    }
    return pos;
}

void stampa (String s[], int n){
    for (int i=0; i<n; i++){
        printf("%d.: %s\n",i, s[i]);
    }
    printf("\n");
}
int main (){ 
    String dict[lun] = { "ciao", "mondo", "come", "funziona", "bene", "il", "programma" };
    printf("La parola più corta è in posizione %d\t", smallest_word_index(dict, lun));
    stampa(dict, lun);
}