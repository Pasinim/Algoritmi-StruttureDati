#include <stdio.h>
#include <stdlib.h>

struct element {  // definizione di un elemento della lista
  char ch;
  struct element *next;    // prossimo elemento
};

typedef struct queue {
  struct element *head;
  struct element *tail;
  int count;
} *Queue;

//metto elemento dalla coda
void enqueue(char ch, Queue q){
    struct element *new=malloc(sizeof(struct element));
    new->ch=ch;
    new->next=NULL;
    q->count++;
    if (q==NULL){
        q->head=q->tail=new;
        return;
    }else{
        struct element *tmp=malloc(sizeof(struct element));
        tmp=q->tail;
        q->tail=new;
        new->next=tmp;
        return;
    }
}

int main( int argc, char **argv ){
    char arg=argv[1][0];
    //printf("arg %c\n", arg );
    Queue q=init();
    char c;
    while (1){
        c=getchar();
        if (c=="\n") break;

    }
}