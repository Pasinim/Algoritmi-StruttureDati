char *fstring( char *w, Node l ){
	if ( l -> next == NULL )
		return strcat( w, l -> w );

	return strcat( fstring( w, l -> next ), l -> w );
}

Node flist( Node l ) {
	if ( l -> w[0] != '\0' && l -> w[1] == '\0' )
		return l; //se i primi due caratteri della testa della lista sono a capo ritorna
	Node n = malloc( sizeof(struct node) );
	n -> w = ( l -> w ) + 1; //prende la parola di l togliendo il primo carattere
	n -> next = l; //collega la nuova lista a quella precedente, concatenando così le due stringhe
	return flist( n );		//flist viene eseguita fin quando i caratteri della parola sono finit

	//cane ->  anecane-> neanecane -> eneanecane
	}

Node build( char *w ) {
	Node lista = malloc (sizeof(struct node) );
	lista -> w = w;
	lista -> next = NULL;
	return flist( lista );
}

