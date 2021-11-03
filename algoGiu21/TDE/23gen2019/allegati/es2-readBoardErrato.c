#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int *createJumps( int, int );


int main() {
	int r, c; 
	scanf( "%d%d", &r, &c);
	
	int *jump = createJumps( r, c );

	int n = r*c ;
	printf( "%d\n", n );
	for ( int i = 1; i <= n; i++ )	
		printf( "%d ", jump[i] );
	printf( "\n" );
	
	return 0;
}

int *createJumps( int r, int c ){
	int n = r * c;
	//int *jump = malloc( n * sizeof(int)); //rimosso (*int) fato che sto creando lo spazio per le n caselle, non per n puntatori a int 
	int *jump = calloc(n+1, sizeof(int));

	int s, m, t; //posSerpente, mouth, tail
	scanf( "%d", &s );
	while ( s > 0) {	
		scanf( "%d%d", &m, &t );
		//jump[t] = m; 
		jump[m] = t; //se si capita sulla bocca  di un serpente ci si deve spostare fino alla coda, non il contrario
		s--; //altrimenti il ciclo è infinito
	}
	
	int l, start, len;
	scanf( "%d", &l ); //ladder
	for (int i = 0; i < l; i++ ) {	
		scanf( "%d%d", &start, &len );
		int row, col, end;
		row = r - 1 - (start-1)/c; //row = fine scala
		col = (start-1) % c; //col = inizio scala
		if ( ( row + r ) % 2 == 0 ) 
			col = c - 1 - col;

		row = row - len + 1;
		end = c * ( r - row );
		if ( ( row + r ) % 2 == 0  )
			end -= col;
		else 
			end += col - c + 1;
		
		jump[start] = end;
	}

	return jump;
}








2