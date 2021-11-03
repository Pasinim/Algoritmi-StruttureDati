#include <stdlib.h>
#include <stdio.h>

#define L 2
#define L0 3

int *read_lin( int *num ) {
  int *a, size = L0, i = 0, n;
  
  a = malloc( size * sizeof(int) );
  while ( 1 ) {
    scanf( "%d", &n );
    
    if ( n == 0 )
      break;

    if ( i >= size  ) {
      size += L;
      a = realloc( a, size * sizeof(int) );
    }
    
    a[i++] = n;
  }
  *num = i;
  return a;
}

int main( ) {
  int i;
  int *a = read_lin( &i );

  while ( i-- > 0 )
    printf( "a[%d] = %d\n", i, a[i] ); 
}
