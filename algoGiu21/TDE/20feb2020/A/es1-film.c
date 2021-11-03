#include <stdlib.h>
#include <stdio.h>

int sottovettore (int a[], int size){
    int c = 1, cMax = 0;
    for (int i = 1; i < size; i++){
        if (a[i] < a[i-1]) {
            c = 1;
            continue;
        }
        c++;
        if (c > cMax) cMax = c;
    }
    return cMax;
}

int main (void){
    int size = 7;
    int a[] = {1, 3, 2, 5, 1, 4, 7};
    printf("%d\n", sottovettore(a, size));
}