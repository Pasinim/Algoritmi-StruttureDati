#include <stdio.h>
#include <stdlib.h>
#define N 5
void stampa(int a[], int lung);
void scambia(int a[], int i, int j);
void selectionsort(int a[], int n);

int main (){
    int arr[N] = {4,5,34,2,1};
    //scambia(arr , 2, 3);
    selectionsort(arr, N);
    stampa(arr, N);
}

void selectionsort(int a[], int n){
    if (n==1 || n==0) 
        return;
    int max=a[0], posmax=0;
    for (int i=0; i<n; i++){
      if (a[i]>max){
            max=a[i];   
            posmax=i;   
            }
        }
    scambia(a, posmax, n-1);
    return selectionsort(a, n-1);
}

void scambia(int a[], int i, int j){
    int tmp = a[i];
    a[i]=a[j];
    a[j]=tmp;
}

void stampa(int a[], int lung){
    for (int i=0; i<lung; i++){
        printf("%d\t", a[i]);
    }
    printf("\n");
}