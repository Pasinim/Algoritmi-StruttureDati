//utilizzo l'insertionSort
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

void bubbleSort(int a[], int l){
    //int i=0;
    for (int i=0; i<l-1; i++){
        for (int j=i; j<l;j++){
            if (a[j]>a[j-1])
                scambia(a, j, j-1);
        }
    }
}

void bubblePig(int a[], int l){
    int swapped=0;
    while (swapped==1){
        swapped=0;
        for (int j=1; j<l; j++){
            if (a[j-1]>a[j]){
                scambia(a, j, j-1);
                swapped=1;
            }
        }
    }
}

int main (void){
    
    //scanf("%d", &l);
    int a[]={0,18,17,12,1,2,1};
    int l=sizeof(a)/sizeof(a[0]);
    bubblePig(a, l);

    for (int i=0; i<l; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}