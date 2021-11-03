char **creaMatrice( int n ){
  char **m;
  int r, c;

  m = malloc( n * sizeof( char * ) );
  for ( r = 0; r < n; r++ ) {
    *(m+r) = malloc( n * sizeof( char ) );
  }

  for ( r = 0; r < n; r++ )
    for ( c = 0; c < n; c++ )
      m[r][c] = '.';
  return m;
}
