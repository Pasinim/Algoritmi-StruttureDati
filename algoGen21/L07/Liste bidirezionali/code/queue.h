// Interface for Queue
struct node{
    int info;
    struct node *next;
};
typedef struct node *Node;

//se lo implemento con un array circolare non  serve la definizione dei nodi

struct queue{
    int *circular; //array da riempire
    int *rear; //prossimo elemento da inserire
    int *front; //prossimo elemento da togliere
    int arrSize; //dimensione corrente dell'array
};
typedef struct queue *Queue;
typedef int Item;
  // Put element on rear
  void enqueue( Queue q, Item item );

  // Remove and return element from front
  Item dequeue( Queue q );

  // Return front element
  Item frontValue( Queue q );

  // Check if queue is empty
  int is_empty_queue( Queue q);

  // Print queue content
  void print_queue( Queue q );
