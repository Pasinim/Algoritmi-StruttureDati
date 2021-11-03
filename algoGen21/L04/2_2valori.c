#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void max_secondmax (int a[], int n, int *max, int *second_max){
    int *p=malloc(sizeof(int));
    for (p=a; p<a+n; p++){
        if (*p>=*max){
            *second_max=*max;
            *max=*p;
            continue;
        }
        if (*p>*second_max){
            *second_max=*p;
        }
    }
}
int main (){
    int l=7;
    int arr[] = {1, 43, 766, 4, 23, 767, 5424};
    int *max = malloc(sizeof(int)), *max2=malloc(sizeof(int));
    //ho allocato lo spazio per i puntatori, ma puntato a una cella conentente
    //qualche valore, quindi li devo inizializzare a 0;
    *max=0, *max2=0;
    max_secondmax(arr, l, max, max2);
    printf("%d\t%d\n", *max, *max2);


}