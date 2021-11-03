/**
 * 1. Individuate di che struttura dati si tratta e descrivete come è implementata.
 * Si tratta di una coda FIFO che ha un puntatore alla testa (str -> a) e un puntatore
 * alla coda (str -> b). Quando la struttura dati è vuota viene
 * inizializzato un nuovo nodo che viene puntato da str -> a. Man mano che verranno
 * aggiunti elementi il puntatore alla testa rimarrà invariato, mentre il puntatore alla coda
 * verrà aggiornato ad ogni chiamata di f1.
 * f1 permette di aggiungere elementi in coda
 * f2 permette di rimuovere elementi dalla testa. Nel caso in cui la lista sia vuota la coda viene impostata a NULL
 * 
 * 2. Dare dei nomi più significativi
 * str -> a = testa
 * str -> b = coda
 * f1 = add
 * f2 = remove
 * 
 */ 


#include <stdio.h>
#include <stdlib.h>

struct listnode {
  struct listnode *next;
  int v;
};


struct struttura{
	struct listnode *a;
	struct listnode *b;
};


struct struttura *createStruttura(){
	struct struttura *str = malloc( sizeof (struct struttura));
	str -> a = NULL;
	str -> b = NULL;

	return str;
}

// void stampa(struct struttura *s){
// 	printf("\n");
// 	printf("str -> a:\n");
// 	struct listnode *tmp = s -> a;
// 	while (tmp != NULL){
// 		printf("\t%d, ", tmp -> v);
// 		tmp = tmp -> next;
// 	}
// 	printf("\n");

// 	printf("str -> b:\n");
// 	tmp = s -> b;
// 	while (tmp != NULL){
// 		printf("\t%d, ", tmp -> v);
// 		tmp = tmp -> next;
// 	}
// 	printf("\n");
// }

void f1( struct struttura *str, int i ){
	struct listnode *new = malloc( sizeof( struct listnode ));
	new -> v = i;
	new -> next = NULL;

	if ( str -> a == NULL ) {
		str -> a = new;
	}
	else {
		str -> b -> next = new;
	}

	str -> b = new;
}

int f2( struct struttura *str ){
	struct listnode *h = str -> a;
	int v = h -> v; //prende il valore puntato da str -> a
	if ( str -> b == h ) {
		str -> b = NULL;
	}
	str -> a = h -> next;
	free( h );
	return v;
}

int isEmpty( struct struttura *str ) {
	if ( str== NULL || str -> a == NULL)
		return 1;
	else
		return 0;
}

int main (){
	struct struttura *s = createStruttura();
	//s -> a -> v = 1;
	//s -> b -> v = 2;
	f1(s, 2);
	stampa(s);
	f1(s, 3);
	stampa(s);
	f1(s, 4);
	stampa(s);
	f2(s);
	f2(s);
	f2(s);

	stampa(s);
}

