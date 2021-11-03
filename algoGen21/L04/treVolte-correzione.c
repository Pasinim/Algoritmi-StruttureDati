#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define N 100
//per qualche motivo non stampa la parola centrale
void treVolte( char *a[], int n ) {
  char **p = malloc(100), *q=malloc(100);
  //p è un array frastagliato, *p è una parola
  int conta = 0;
  for ( p = a; p < a + n; p++ ) {
    int contae = 0;
    char *c=malloc(sizeof(char)+1);
    c = *p; //assegno a c l'indirizzo puntato da p
    //printf("**p: %c\n", **p);
    while (*c!='\0') { //fin quando la parola non termina
      if ( *c == 'e' )
	    contae++;
      if ( contae == 3 ) {
	    conta++;
      }
      c++;
    }
    printf("test\n");
    if ( conta == 3 ) {
        printf("____a[0]: %s\n", a[0]);
      printf("a[1]: %s\n", a[1]);
      printf("a[2]: %s\n", a[2]);
      strcpy( q, *p ); //devo mettere *p perchè p è un array frastagliato
      //printf("q: %s\n", q);
    printf("111 a[0]: %s\n", a[0]);
      printf("a[1]: %s\n", a[1]);
      printf("a[2]: %s\n", a[2]);
      strcpy( *p, a[0]);
      //printf("*p: %s\n", *p);
            printf("222a[0]: %s\n", a[0]);
      printf("a[1]: %s\n", a[1]);
      printf("a[2]: %s\n", a[2]);
      strcpy ( a[0], q);
      printf("333 a[0]: %s\n", a[0]);
      printf("a[1]: %s\n", a[1]);
      printf("a[2]: %s\n", a[2]);
    return;
    }
  }
}

int main( int argc, char **argv ) {
  treVolte( argv + 1, argc - 1 );
  
  for ( char** p = argv; p < argv + argc; p++  )  
    printf( "%s ", *p );
  printf( "\n" );
  return 0;
}
