#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define L 100
int main (int argc, char **argv){
    char *str, *start, *end;
    str=argv[1]; //assegno alla stringa il valore inserito da tastiera
    start=&str[0]; 
    end=&str[strlen(str)-1];
    //printf("inizio: %c\t fine: %c\n", *start, *end);

   for (int i=0; i<=(strlen(str)/2); i++){
        if (*start!=*end){
            printf("Parola non palindroma\n");
            break;
        }
        if (i== strlen(str)/2){
            printf("Parola palindroma\n");
            break;
        }
        start++;
        end--;
        
    }
}