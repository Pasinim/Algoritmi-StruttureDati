#include <stdio.h>
#include <stdlib.h>

void swap (int arr[], int i, int j){
    int tmp=arr[i];
    arr[i]=arr[j];
    arr[j]=tmp;
    return;
}

void sel_sort(int a[], int size){
    for (int j=0; j<size-1;j++){
        int iMin=j; //il minimo è in m
        for (int i=j+1; i<size; i++){
        //con questo for trovo l'indice dell'elemento minore
            if (a[i]<a[iMin])
                iMin=i;  
            }
        swap(a, j, iMin);
    }
}

void ins_sort(int a[], int size){
    for (int k=1; k<size; k++){
        int x=a[k];
        int j=k-1;
        while (j>=0 && a[j]>x){
            a[j+1]=a[j]; //sposto avanti l'elemento maggiore di x
            j--;
        }
        a[j+1]=x; //inserisco x nel posto che ho liberato nel whie=le
    }
}

void bubble_sort(int a[], int l){
    int scambiato=0;
    do{
        scambiato=0;
        for (int j=0; j<l; j++ ){
            if (a[j]<a[j-1]){
                swap(a, j-1, j);
                scambiato=1;
            }
        }
    }while(scambiato==1);
}

int main (void){
    int a[]={2,123,42,1 ,414 ,124};
    int l=6;
    bubble_sort(a, l);
    for (int i=0; i<l; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}