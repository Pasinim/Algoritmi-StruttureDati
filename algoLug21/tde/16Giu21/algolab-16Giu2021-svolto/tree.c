struct bit_node {
  int item;
  struct bit_node *l, *r;
};

typedef struct bit_node *Bit_node;


void printArray( int *a, int n ) {
	for ( int i = 0; i < n; i++ )
		printf( "%d ", a[i] );
	printf( "\n" );
}

void f_r( Bit_node root, int *path, int len ) {
	if (root == NULL )
		return;

	if ( root -> item % 2 ) {
		path[len] = root -> item;
		len++;
	}

	if ( root -> r == NULL && root -> l == NULL ) {
		printArray( path, len );
		return;
	}
	
	f_r( root -> l, path, len );
	f_r( root -> r, path, len ); 
}

void f( Bit_node root ) {
	int *path = malloc( 1000 * sizeof( int ) );
	f_r( root, path, 0 );
}

