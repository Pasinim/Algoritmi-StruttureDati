#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
typedef int BOOL;
struct node {
    int value;
    struct node *next;
};
typedef struct node *Node;

Node new_node(){
    Node new=malloc(sizeof(Node));
    if (new==NULL){
        printf("Errore allocazione\n");
        exit(EXIT_FAILURE);
    }
    return new;
}
Node insert(Node l, int n){
    Node new=new_node();
    printf("inserisco\n");
    new->value=n;
    new->next=l;
    printf("inserito\n");
    return new;
}
BOOL search(Node l, int n){
    while (l!=NULL){
        if (l->value==n) return TRUE;
        l=l->next;
    }
    return FALSE;
}
void destroy(Node l){
    Node tmp=new_node();
    while (l!=NULL){
        // tmp=l->next;
        // free(l);
        // l=tmp;
        tmp=l;
        l=l->next;
        free(tmp);
    }
    return;
}

Node delete(Node l, int n){
    Node cur=new_node();
    Node prev=new_node();
    cur=l;
    prev=NULL;
    while (cur->value!=n){
        if (cur==NULL){
            printf("VAlore non trovato\n");
            return l;
        }
        prev=cur;
        cur=cur->next;
    }
    prev->next=cur->next;
    free(cur);
    return l;
}

void stampa(Node n){
    while (1){
        if (n==NULL) break;
        printf("%d\t", n->value);
        n=n->next;
    }
    printf("\n");
}

int main (){
    char r;
    r=getchar();
    int n;
    Node numbs=new_node();
    while (r!='f'){
        switch(r){
            case '+':
                scanf("%d", &n);
                if (search(numbs, n)==FALSE){
                    numbs=insert(numbs, n);
                    printf(":%d\n", numbs->value);
                }else{
                    printf("Numero già presente\n");
                }
                break;
            case '-':
            scanf("%d", &n);
                if (search(numbs, n)==TRUE){
                    numbs=delete(numbs, n);
                }else{
                    printf("Numero non presente\n");
                }
                break;
            case 'p':
                stampa(numbs);
                break;  
            case 'd':
                destroy(numbs);
                break;
        }
        r=getchar();
    }
}