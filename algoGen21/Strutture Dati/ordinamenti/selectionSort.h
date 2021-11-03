#include <stdio.h>
#include <stdlib.h>

void stampa(int a[], int lung){
    for (int i=0; i<lung;i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void scambia (int a[], int i, int j){
    int tmp=a[i];
    a[i]=a[j];
    a[j]=tmp;
    return;
}

void selectionsort(int a[], int n ){
    if (n==0||n==1)
        return;
    int iMax=0, max=a[iMax];
    for (int i=1; i<n; i++){
        if (a[i]>=max){
            iMax=i;
            max=a[i];
        }
    }
    //metto il massimo in fondo all'array
    scambia(a, iMax, n-1);
    return selectionsort(a, n-1);
}