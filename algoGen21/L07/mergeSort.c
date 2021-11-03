#include <stdio.h>
#include <stdlib.h>
#define N 6

void stampa(int a[], int lung);
void scambia(int a[], int i, int j);
void mergeSort(int a[], int sx, int dx);
void merge(int a[], int b[], int n);
int main (){
    int arr[N] = {4,5,34,2,1};
    //scambia(arr , 2, 3);
    mergeSort(arr, 0, N);
    stampa(arr, N);
}
//do in input anche la lunghezza dei sottoarray


void mergeSort(int a[], int sx, int dx){
    //1. divido in due sottoarray di dimensione uguale
    int lung=dx-sx;
    int lb=lung/2;
    int lc=lung-(lung/2);
    if (lung==0||lung==1) return;
    int b[lb];
    int c[lc];

    int tmp[lung];
    int i1=0, i2=0;
    int k=0; //contatore per inserire i valori nell'array tmp
    while (i1<lb && i2<lc){
        if (b[i1]<=c[i2]){
            tmp[k]=b[i1];
            i1++;
        }else{ 
            tmp[k]=c[i2];
            i2++;
        }
        k++;
    }
    if (i1<lc){
        for (int j=i1; j<lc; j++ ){
            tmp[k]=c[j];
            k++;
        }
    }else{
        for (int j=i2; j<lb; j++ ){
            tmp[k]=b[j];
            k++;
        }       
    }
    mergeSort(b, 0, lb);
    mergeSort(c, lb, lung); 
    merge(b, c, lung);
}

void merge (int b[], int c[], int n){
    int a[n];
    
}
void stampa(int a[], int lung){
    for (int i=0; i<lung; i++){
        printf("%d\t", a[i]);
    }
    printf("\n");
}

