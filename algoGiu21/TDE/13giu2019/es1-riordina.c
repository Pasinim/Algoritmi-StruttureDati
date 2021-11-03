#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap (int arr[], int i, int j){
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void bubbleSort(int arr[], int size){
    bool scambiato;
    do {
        scambiato = false;
        for (int j = 1; j <= size - 1; j++){
            if (arr[j] < arr[j-1]){
                swap(arr, j, j-1);
                scambiato = true;
            }
        }
    } while (scambiato == true);
}

void stampa (int arr[], int size){
    for (int i=0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main (void){
    int a[] = {1, 0, 0, 1, 0, 0, 1};
    int size = 7;
    bubbleSort(a, size);
    stampa(a, size);

}