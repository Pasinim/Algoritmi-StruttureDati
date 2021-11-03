#include <stdio.h>
#include <stdlib.h>

int main (){
    int a[] = {1, 3, 2, 5, 1, 4, 7};
    int l =7, sum=1, sumMax=0;
    for (int i=1; i<l; i++){
        if (a[i]>a[i-1]){
            sum++;
            if (sum>sumMax) sumMax=sum;
        }else{
            sum=1;
        }
    }
    printf("%d", sumMax);
}