#include <stdio.h>
#include <stdlib.h>

void scambia (int a[], int i, int j){
    int tmp=a[i];
    a[i]=a[j];
    a[j]=tmp;
    return;
}
void insSort(int a[], int l){
    int i=1;
    while (i<l){
        int j=i;
        while (j>0 && a[j-1]>a[j]){ //sposto tutti gli elementi che sono maggiori di a[i]
            scambia(a, j, j-1);
            j--;
        }
        i++;
    }
}