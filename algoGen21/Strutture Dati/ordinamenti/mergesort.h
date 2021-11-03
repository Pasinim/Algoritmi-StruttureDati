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

void merge2(int a[], int sx, int m, int dx) {
    int i1 = sx;
    int i2 = m;
    int k = 0;
    int x[100];

    while (i1 < m && i2 < dx) {
        if (a[i1] < a[i2]) {
            x[k] = a[i1];
            i1++;
        } else {
            x[k] = a[i2];
            i2++;
        }
        k++;
    }

    while (i1 < m) {
        x[k++] = a[i1++];
    }

    while (i2 < dx) {
        x[k++] = a[i2++];
    }

    for (int i = 0; i < k; i++) {
        a[sx + i] = x[i];
    }
    return;
}

void merge_sort(int a[], int sx, int dx){
    int l=dx+sx;
    if ((dx-sx)<=1)
        return;
    int m=l/2;
    merge_sort(a, sx, m);
    merge_sort(a, m, dx);
    merge2(a, sx, m, dx );
}