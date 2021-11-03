#include <stdio.h>
#include <stdlib.h>
int *rete; //la inizializzo come variabile globale, così se esiste già posso sovrascriverla
void new(int n);
void stampa(int l);
void set(int n);
void press( int l);

int main (void){
    char c;
    int n, m;
    c=getchar();
    while (c!='f'){
        switch (c){
            case '+':
                scanf("%d", &n);
                new(n);
                break;
            case 'p':
                stampa(n);
                break;
            case 'o':
                set(n);
                break;
            case 's': //il pulsante 1 schiaccia l'elemento 1 nell'array, NON lo 0.
                press(n);
                break;
            case 'S':
                scanf("%d", &m);
                for (int i=0;i<m; i++){
                    press(n);
                }
                break;
        }
        c=getchar();
    }
}
void new(int n){
    rete=calloc(n, sizeof(int));
    for (int i=0;i<n;i++){
        rete[i]=0; //inizialmente le luci sono tutte spente
    }
};

void stampa(int l){
    for (int i=0; i<l; i++){
        printf("%d ", rete[i]);
    }
    printf("\n");
};

void set(int n){
    int x;
    printf("inserisci array di luci: ");
    for (int i=0; i<n; i++){
        scanf("%d", &x );
        rete[i]=x;
    }
};

void press(int l){
    printf("Premo il pulsante: ");
    int i;
    scanf("%d", &i);
    if (i==0){
        rete[1]=1-rete[2];
        rete[l-1]=1-rete[l-1];
        return;
    }
    if (i==l-1){
        rete[l-2]=1-rete[l-2];
        rete[0]=1-rete[0];
        return;
    }else{
        rete[i-1]=1-rete[i-1];
        rete[i+1]=1-rete[i+1];
        return;
    }
    return;
};