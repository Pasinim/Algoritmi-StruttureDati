#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
char *maiuscolo(char *stringa){
    char *tmp=stringa;
    for (tmp=stringa;*tmp!='\0'; tmp++){
        *tmp=toupper(*tmp);
    }
    return stringa;
    // ritorno l'indirizzo puntato da stringa, cioè la stringa messa tutta in maiuscolo
}

int main(){
    char *str = malloc(sizeof(char)*100);
    int c=0;
    while (1){
        scanf("%c", &str[c]);
        if (str[c]=='\n') break;
        c++;
    }
    //str[4]='p'; //questo posso farlo
    //str="pippo" //questo no, ottendo un bus error
    maiuscolo(str);
    char *tmp = malloc(sizeof(char)*10);
    for (tmp=str; *tmp!='\0'; tmp++){
        printf("%c", *tmp);
    }
    printf("\n");
}