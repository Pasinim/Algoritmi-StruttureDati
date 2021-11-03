#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
char *maiuscolo(char stringa[]){
    char *tmp=stringa;
    for (tmp=stringa;*tmp!='\0'; tmp++){
        *tmp=toupper(*tmp);
    }
    return stringa;
    // ritorno l'indirizzo puntato da stringa, cioè la stringa messa tutta in maiuscolo
}

int main (){
    char s[]="pippo"; 
    /*NON posso dichiarare *s="pippo", dato che non sarebbe modificabile in quanto punterebbe
    a una porzione di memoria read only. */
    printf("sono nel main: %s \n", maiuscolo(s)); //è sufficiente chiamare la funzione senza assegnarla a nessuna nuova variabile, infatti modifico direttamente la variabile.
    char *tmp;
    for (tmp=s; *tmp!='\0'; tmp++){
        printf("%c\t", *tmp );
    }
    printf("\n");
}
