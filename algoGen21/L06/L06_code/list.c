struct node {   
  int info;   
  struct node *next;
};

struct node *list_insert( int n, struct node *l ){
  struct node *new = malloc( ... );
  new -> info = n;
  new -> next = l;
  return new; 
}

struct node *list_search( int n, struct node *l ){
  while ( l != NULL && l -> info != n )
    l = l -> next;
  return l;
}

