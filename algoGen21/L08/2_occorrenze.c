#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define WORD 10
char *text[WORD];
int len=0;
struct occorrenza{
    char* word[WORD+1]; //è uguale a char *word;
    int n;
};
//typedef struct occorrenza *Item;
//typedef char String[WORD+1];
struct bit_node{
    struct occorrenza *item;
    struct bit_node *l, *r;
};
typedef struct bit_node *Bit_node;
Bit_node testo2tree();
Bit_node search(Bit_node b, char *s);
void bist_orderprint(Bit_node p);
void bist_invorderprint(Bit_node p);
void testo();
void print_testo();
Bit_node new_occ();
char *read_word();

int main(){
    testo();
    print_testo();
    Bit_node b=malloc(sizeof(struct bit_node));
    b=testo2tree(b);
}

Bit_node new_occ(char *w){
    Bit_node new=malloc(sizeof(struct occorrenza));
    //strcpy(new->item->word, w);
    *(new->item->word)=w;
    new->item->n=1; //se creo il nodo significa che è la prima volta che trovo la parola
    new->l=new->r=NULL;
    return new;
}

void testo (){
    while (1){
        char *s=malloc(sizeof(char)*(WORD+1));
        scanf("%s", s);
        //printf("s: %s\n", s);
        if (strcmp(s, "STOP" )==0){
            break;
        }
        *(text+len)=s;
        len++; 
    }
    return;
}

void print_testo(){
    for (int i=0; text[i]!=NULL; i++ ){
        printf("%s ", text[i]);
    }
    printf("\n");
}

Bit_node testo2tree(Bit_node p){
    //devo scorrere
    Bit_node trova=malloc(sizeof(struct bit_node ));
    for (int i=0; text[i]!=NULL; i++ ){
        trova=search(p, text[i]);
        if (trova!=NULL){ 
            printf("bravp\n");
        }else{ //se la parola non è ancora presente nell'albero lo aggiungo
            Bit_node new = malloc(sizeof(struct bit_node));
            new=new_occ(text[i]);
            
        }
    }
    return 
}

Bit_node search(Bit_node b, char *s){
    if (!b){
        printf("Non trovato\n");
        return NULL; //elemento non trovato
    }
    int res = strcmp(s, *(b->item->word));
    
    if (res==0){
        printf("La parola è già presente\n");
        return b->item; //elemento trovto
    }
    if (res<0)
        return search(b->l, s);
    return search(b->r, s);
}