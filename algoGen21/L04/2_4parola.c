#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int smallest_word_index(char *s[], int n){
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
int main (){
    char *dict[] = { "ciao", "mondo", "come", "funziona", "bene", "il", "programma" };
    int lun=7; 
    printf("La parola più corta è in posizione %d\t", smallest_word_index(dict, lun));
}