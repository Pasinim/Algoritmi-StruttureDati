void addAtEnd1( List_with_tail l, int e ){
  if ( l -> tail == NULL ) {
    l -> head = l -> tail = malloc( sizeof( struct node ) );
    l -> head -> info = e;
  }
  else {
    l -> tail -> next = e;
    l -> tail = e;
  }
}
void addAtEnd2( List_with_tail l, int e ){
  if ( l -> tail == NULL ) {
    l -> head = l -> tail = malloc( sizeof( struct node ) );
    l -> head -> info = e;
  }
  else {
    Node temp = new_node(e);
    l -> tail -> next = temp;
  }
}
void addAtEnd3( List_with_tail l, int e ){
  if ( l -> tail == NULL ) {
    l -> head = l -> tail = malloc( sizeof( struct node ) );
    l -> head -> info = e;
  }
  else {
    Node temp = new_node(e);
    l -> tail = temp;
  }
}
void addAtEnd4( List_with_tail l, int e ){
  if ( l -> tail == NULL ) {
    l -> head = l -> tail = malloc( sizeof( struct node ) );
    l -> head -> info = e;
  }
  else {
    l -> tail -> next = new_node(e);
    l -> tail = l -> tail -> next;
  }
}
void addAtEnd5( List_with_tail l, int e ){
  if ( l -> tail == NULL ) {
    l -> head = l -> tail = malloc( sizeof( struct node ) );
    l -> head -> info = e;
  }
  else {
    Node temp = l -> head;
    while ( temp -> next != NULL ) {
      temp = temp -> next;
    }
    temp -> next = new_node(e);
  }
}

