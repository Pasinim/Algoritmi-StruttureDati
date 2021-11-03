int *read_n( int *num ) {
  int *a, i;
  scanf( "%d", num );
  
  a = my_malloc( *num * sizeof(int) );
  for ( i = 0; i < *num; i++ ) {
    scanf( "%d", &a[i] );
  }

  return a;
}
