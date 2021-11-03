// qual è la differenza tra char* word e char *word
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define WORD 10
char *text[WORD];
char *word();
void testo();
int main() {
    char *s=NULL;
    s=word();
    printf ("%s\n", s);
    testo();
}

//faccio prima una funzione che legge una parola per volta
char *word (){
    char c;
    char *s=malloc(sizeof(char)*10);
    int i=0;
    do{
        c=getchar();
        s[i++]=c;
    }while (isspace(c)==0);
    return s;
}
//ora creo un array frastagliato per salvare tutto il testo
void testo (){
    while (1){
        char *s=malloc(sizeof(char)*(WORD+1));
        int c=0;
        scanf("%s", s);
        printf("s: %s\n", s);
        if (strcmp(s, "STOP" )==0){
            break;
        }
        *(text+c)=s;
        c++;
    }
    return;
}


