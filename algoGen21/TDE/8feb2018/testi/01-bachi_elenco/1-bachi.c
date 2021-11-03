#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20

typedef char *String;
typedef struct{
  int size;
  int count;
  String *content;
} *Elenco;


int main( void ) {
  Elenco b;
  int size = 4, i = 0;

  b = malloc( sizeof(Elenco) );
  b -> size = 4;
  b -> count = 0;
  b -> content = malloc( sizeof(char *) );

  while(1){// strcmp( name, "FINE" ) != 0 ) {
    char *name=malloc(sizeof(char)*N+1);
    scanf( "%s", name );

    if (strcmp( name, "FINE")==0 ) break;
    if ( b -> count == b -> size ) {
      b -> size *= 2;
      b-> content = realloc (b-> content, size * sizeof(char *));
    }
    b -> content[b->count] = name;
    printf("nel while: %s\n", b->content[b->count]);
    i++;
    b->count=b->count+1; //devo incrementare il numero di nomi nell'elenco
  }

  for ( int k = 0; k < b -> size; k++ )
      printf( "%s\n", b -> content[k] );

    //printf("b->content[1]: %s\n", b->content[1]);
  return 0;


}