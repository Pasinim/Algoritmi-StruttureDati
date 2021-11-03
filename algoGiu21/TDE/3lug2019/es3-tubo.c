/**
 * Adotto un algoritmo greedy che ogni volta preleva il minimo
 * dall'array. Utilizzo il selection sort per ordinare l'array
 */
#include <stdio.h>
#include <stdlib.h>

void swap (int arr[], int i, int j){
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void sel_sort(int arr[], int size){
    //int *arr = calloc(size, sizeof(int));
    for (int j=0; j<size - 1; j++){
        int iMin = j;
        for (int i = j + 1; i < size; i++){
            if (arr[i] < arr[iMin])
                iMin = i;
        }
        swap(arr, iMin, j);
    }
}

void stampa (int a[], int size){
    for (int i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int getSegmenti(int a[], int size, int maxDim){
    int sum = 0;
    int counter = 0;
    for (int i = 0; i < size; i++){
        sum += a[i];
        if (sum > maxDim){
            sum -= a[i];
            break;
        }
        counter++;
    }
    return counter;
}

int main (){
    int a[] = {7, 4, 3, 5, 1, 2, 6};
    int size = 7 ;
    int m = 10;
    sel_sort(a, size);
    printf("%d\n", getSegmenti(a, size, m));
    //stampa(a, size);
}