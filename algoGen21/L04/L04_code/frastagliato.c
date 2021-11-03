#include <stdio.h>
#include <string.h>

void f( char *a[], int n, int i ) {
  if ( i < 0 || i > n-1 )
    return;

  char *p = a[i]; //p è una stringa
  a[i] = a[n-1];
  a[n-1] = p;
  return;
}

int main( int argc, char **argv ) {
  char **q;
  int i;

  scanf( "%d", &i ); 
  f( argv + 1, argc - 1, i );

  for ( q = argv + 1; q < argv + argc; q++  )  
    printf( "%s ", *q );
  printf( "\n" );
  return 0;
}
