#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "queue.c"

int bfs( int *jump, int size );
int move( int *jump, int size, int v, int dice);

int main() {
	int n, min;
	int *jump = NULL, *prec = NULL;	
	
	scanf( "%d", &n );
	jump = calloc( n+1, sizeof(int) ); 
	for ( int k = 1; k <= n; k++) 
		scanf( "%d", &jump[k] );
	prec = calloc ( n + 1, sizeof(int) );

	min = bfs( jump, n ); 
			
	if ( min >= 0 )
		printf( "%d\n", min );

	return 0;

}

// calcola la prossima casella, se si parte dalla casella di valore v e il lancio del dado è dice.
// restituisce 0 se il valore finale supera quello massimo delle caselle
// restituisce -1 se si entra in un loop 
int move( int *jump, int size, int v, int dice) {
	v = v + dice;
	if ( v > size )
		return 0;

	// versione semplice: assumo che non ci siano mai serpenti o scale nella casella di destinazione
	if ( jump[v] == 0 ) 
		return v;
	else 
		v = jump[v];

	/* 
	//versione completa: possono esserci serpenti o scale nelle caselle di destinazione,
	// anche a formare loop 
	int count = 0;
	while ( jump[v] > 0 ) {
		v = jump[v];
		count++;
		if ( count > size ) { // loop
			jump[v] = -1; 
			return -1;
		}
	}
	if ( jump[v] == -1 ) 
		return -1;
	*/
	
	return v;
}


// calcola il minimo numero di lanci necessari per arrivare alla casella n partendo dalla casella 1, tramite una visita in ampiezza del grafo delle mosse
// restituisce -1 se partendo da v0 non si può raggiungere v
int bfs( int *jump, int n ) {
	int *dist = malloc ( sizeof(int) * ( n + 1 ) );
	for (int i = 0; i <= n; i++)
		dist[i] = -1;

	int curr;
	struct queue *q = createqueue();
	dist[1] = 0;
	enqueue( q, 1 );

	while ( !emptyq( q ) ) {
		curr = dequeue( q );
		for ( int i = 1; i <= 6; i++ ) {
			int v = move( jump, n, curr, i );
			if ( dist[v] != -1 || v <= 0 )
				continue;
			dist[v] = dist[curr] + 1 ;
			if ( v == n ) {
				return dist[v];
			}

			else
				enqueue( q, v );
		}
	}


	return dist[n]; // se n non e' stata raggiunta restuisce -1
}

