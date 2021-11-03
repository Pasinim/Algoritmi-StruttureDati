#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// int inscerisci_int_array_mainx (int argc, char **argv){
//     int *p;
//     p=malloc(argc);
//     //da terminale inserico `./prova 1 2 3 4 5 6...`
//     for (int c=1; c<argc; c++){
//         *p=atoi(argv[c]);
//         printf("*p: %d\n", *p);
//         p++;
//     }
// }
 //in questo main voglio inserire una parola da linea di comando
//  int prima_e_ultima_lettera (int argc, char **argv){
//      char *s;
//      s= &argv[1][0]; //prima lettera
//      printf("%c\n",*s);
//      //printf(" lunghezza praola inserita da linea di comando: %lu\n", strlen(argv[1]));
//      s=&argv[1][strlen(argv[1])-1]; //ultima lettera
//      printf("%c\n", *s);
//  }

    //char *s = "anna";
    //printf("%s\n", s);

    //funzione che cicla le lettere di una stringa utilizznod i puntatori   
    void stampa (char *stringa){
        char *tmp=malloc(sizeof(char)*10);
        //stringa=malloc(sizeof(char)*10);
        for (tmp=stringa; *tmp!='\0';tmp++){
            //printf("%c\t", *tmp);
            tmp=stringa;
            //printf("%c\t", *tmp);
        }
        //return tmp;
    }

    int main(){
        char *stringa=malloc(sizeof(char)*10);
        stringa="ciao"; //perchè non devo mettere l'asterisco? Perchè l'asterisco lo dovrei mettere per accedere ad una singola lettera
        //char *prova=stampa(stringa);
        stampa(stringa);
        //printf("%s\n", prova);
    }