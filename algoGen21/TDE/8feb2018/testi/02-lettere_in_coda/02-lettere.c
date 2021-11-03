#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


struct element {  // definizione di un elemento della lista
  char ch;
  struct element *next;    // prossimo elemento
};

typedef struct queue {
  struct element *head;
  struct element *tail;
  int count;
} *Queue;


Queue init();
void enqueue(char ch, Queue q);
char dequeue(Queue q); // assume che la coda non sia vuota
void stampa_coda (Queue q);
// inserite qui la funzione extract e eventuali altre funzioni aggiuntive
void extract2 (Queue q){
    struct element *tmp = malloc(sizeof(struct element));
    //struct element *next = malloc(sizeof(struct element));
    for (tmp=q->head; tmp!=NULL; tmp=tmp->next){
        printf("%c -> ", tmp->ch);
        next=tmp->next; //meglio non fare così, guarda come è implementato dequeue sotto
        free(tmp);
        tmp=next;
    }
    printf("\nHo estratto tutto dalla coda\n");
    return;
};

void extract(Queue q){
    char ch;
    while (q->count>0){
        ch = dequeue(q);
        printf("%c", ch);
    }
    printf("\n");
}


int main( int argc, char **argv ){
    char arg=argv[1][0]; //prendo il primo carattere della seconda stringa
    
    Queue q, v, c, s;
    q=init(); v=init(); c=init(); s=init(); 
    char ch;
    // lettura delle lettere e inserimento nella coda q
    while (1){
        ch=getchar();
        if (ch=='\n') break;
        enqueue(ch, q);
    }

    // estrazione dalla coda e distribuzione delle lettere nelle code v,c,s
    struct element *tmp=malloc(sizeof(struct element));
    for (tmp=q->head; tmp!=NULL; tmp=tmp->next){
        //printf("Sto riempiendo le altre code...\n\n");

        if (tmp->ch == 'a' || tmp->ch == 'e' ||  tmp->ch == 'i' ||  tmp->ch == 'o' ||  tmp->ch == 'u' ||
        tmp->ch == 'A' || tmp->ch == 'E' ||  tmp->ch == 'I' ||  tmp->ch == 'O' ||  tmp->ch == 'U' ){
            enqueue(tmp->ch, v);
            continue;
        }else if( tmp->ch == 'j' || tmp->ch == 'k' ||  tmp->ch == 'w' ||  tmp->ch == 'x' ||  tmp->ch == 'z' || tmp->ch=='y'){
            enqueue(tmp->ch, s);
            continue;
        }else{
            enqueue(tmp->ch, c);
        }
    }

    // stampa della coda opportuna
    switch( arg ) {
        case 'p': stampa_coda(q);
        break;
        case 'V': extract(v);
        break;  
        case 'C': extract(c);
        break;
        case 'S': extract(s);
    }

        //...

    return 0;
}



Queue init(){
  Queue q = malloc(sizeof(struct queue));
  q->head = NULL;
  q->count = 0;
  return q;
}

void enqueue(char ch, Queue q){
  struct element *new = malloc(sizeof(struct element));
  new->ch = ch;
  new->next = NULL;
  if (q->head == NULL)
    q->head = new; // la coda era vuota
  else {
    q->tail->next = new; // attacco in coda
  }
  q->tail = new;
  q->count++;
}

// assumo che la coda non sia vuota
char dequeue(Queue q){
  char ch;
  struct element *testa = q->head;
  ch = testa->ch;
  q->head = q->head->next;
  free(testa);
  q->count--;
  return ch;
}

void stampa_coda(Queue q){
    struct element *tmp=malloc(sizeof(struct element));
    for (tmp=q->head;tmp!=NULL;tmp=tmp->next){
        printf("%c", tmp->ch);
    }
    printf("\n");
}
