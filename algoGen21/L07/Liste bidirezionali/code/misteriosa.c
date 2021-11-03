#include <stdio.h>
#include <stdlib.h>

/*
#define N 3
int a[N] = {2,4,6}; 
*/

#define N 9
int a[N] = {2,4,6,1,3,4,12,5,14}; 

struct node {
  int item;
  struct node *next;
};

typedef struct {
  struct node *head;
} *List;


struct node *mystery( List l, int value ) {
  struct node *current = l -> head;
  struct node *temp = NULL;
  while ( current != NULL && current -> item != value ) {
    temp = current;
    current = current -> next;
  }
  return temp;
}

struct node *list_newNode(int value) {
  struct node *p = malloc(sizeof(struct node));
  p -> item = value;
  p -> next = NULL;
  return p;
}

// la lista deve esistere
void list_addAtEnd(List l, int value) {
  struct node *new = list_newNode(value);

  if (l -> head == NULL) {
    l -> head = new;
    return;
  }
  struct node *p = l -> head;
  while ( p -> next != NULL )
    p = p -> next;
  p -> next = new;
}


void list_print(List l){
  if (!l) {
    printf( "lista inesistente\n" );
    return;
  }
  if (l -> head == NULL) {
    printf( "lista vuota\n" );
    return;
  }

  struct node *p = l -> head;
  while (p) {
    printf("%d ", p -> item);
    p = p -> next;
  }
  printf("\n ");
}

int test_list() {
  List l = malloc(sizeof(List*));
  l -> head = NULL;
  list_print(l);
  getchar();

  for(int i=0; i<N; i++) {
    list_addAtEnd(l, a[i]);
  }
  list_print(l);

  int n = 4;
  struct node *p = mystery(l,n);
  if (!p)
    printf( "%d in testa", n );
  else if (p-> next == NULL)
    printf("%d non esiste (restituito %d)\n", n, p -> item);
  else 
    printf("l'el prima di %d e' %d (next item = %d)\n", n, p -> item, p -> next -> item);

  return 0;
}




struct dnode {
  int item;
  struct dnode *next;
  struct dnode *prev;
};

typedef struct {
  struct dnode *head;
  struct dnode *tail;
} *DList;

struct dnode *dlist_newNode(int value) {
  struct dnode *p = malloc(sizeof(struct dnode));
  p -> item = value;
  p -> next = NULL;
  p -> prev = NULL;
  return p;
}


void dlist_print(DList l){
  if (!l) {
    printf( "lista inesistente\n" );
    return;
  }
  if (l -> head == NULL) {
    printf( "lista vuota\n" );
    return;
  }

  struct dnode *p = l -> head;
  while (p) {
    printf("%d ", p -> item);
    p = p -> next;
  }
  printf("\n ");
}



void dlist_addAtEnd(DList l, int value){
  struct dnode *new= dlist_newNode(value);
  
  if (l -> tail == NULL) {
    l -> head = l -> tail = new;
    return;
  }
  
  l -> tail -> next = new;
  new -> prev = l -> tail;
  l -> tail = new;
  dlist_print(l);
}



int test_dlist() {
  DList l = malloc(sizeof(DList*));
  l -> head = NULL;
  l -> tail = NULL;
  dlist_print(l);
  getchar();

  for(int i=0; i<N; i++) {
    dlist_addAtEnd(l, a[i]);
    dlist_print(l);
  }
//  dlist_print(l);

  return 0;
}


int main() {
  test_list();
  test_dlist();

  return 0;

}
