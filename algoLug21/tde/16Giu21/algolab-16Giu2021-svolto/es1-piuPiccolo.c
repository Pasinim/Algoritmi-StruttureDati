#include <stdio.h>


/*
Scrivete una funzione C con prototipo

\lstinline| int h( int A[], int B[], int n, int m)|
\\
che, dato un vettore A di lunghezza \verb|n| e un vettore B di lunghezza \verb|m|, decide se ogni valore in A è strettamente più piccolo di ogni valore in B. 

Ad esempio se \verb|A| $= \{1,5,5\}$ e \verb|B| $= \{6,5\}$ allora \verb|h(A,B)| restituisce 0, ma per \verb|C| = \{7,6\} allora \verb|h(A,C)| restituisce 1.

Indicate il tempo di esecuzione; si richiede una soluzione efficiente!
*/


int h2( int A[], int B[], int n, int m) {
   // calcolo il massimo di A
   int maxA = A[0];
   for ( int i = 1; i < n; i++ )
      if ( A[i] > maxA )
	 maxA = A[i];
   
   // confronto maxA con ogni elemento di B (devono essere tutti strettamente maggiori)
   for ( int j = 0; j < m; j++ )
      if ( B[j] <= maxA )
	 return 0;

   return 1;
}




int h( int A[], int B[], int n, int m) {
   // calcolo il massimo di A
   int maxA = A[0];
   for ( int i = 1; i < n; i++ )
      if ( A[i] > maxA )
	 maxA = A[i];
   
   // calcolo il minimo di B
   int minB = B[0];
   for ( int j = 1; j < m; j++ )
      if ( B[j] < minB )
	 minB = B[j];

   return maxA < minB;
}




int main() {
   int n, m;
   scanf( "%d", &n );
   int A[n];
   for ( int i = 0; i < n; i++ ) {
      scanf( "%d", &A[i] );
   }


   scanf( "%d", &m );
   int B[m];
   for ( int i = 0; i < m; i++ ) {
      scanf( "%d", &B[i] );
   }

   printf( "%d\n", h( A, B, n, m ) );

}


