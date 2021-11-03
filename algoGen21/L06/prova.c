//come assegno dei valori ad un array dinamicamente?
#include <stdio.h>
#include <stdlib.h>
#define SIZE 3 

void inserisci(int *arr){
    int x;
    int *p;
    for (p=arr; ;p++){
        scanf("%d", &x);
        if (x==0) break;
        *p=x;
    }
}
int main (){
    int *arr=malloc(10);
    inserisci(arr);
    printf("Array   :%d\t%d\t%d\n", arr[0], arr[1], arr[2]);
    

}