#include <stdio.h>
#include <stdlib.h>

#define LENGHT 10 //creo una var globale;
int main(void){
    int i;//definisco i
    int *arr=malloc(LENGHT*sizeof(int));//definisco un array e gli alloco la memoria

    for(i=0;i<LENGHT;i++){//riempo l'array di num casuali
        arr[i]=rand()%100+1;
    }
    printf("%d \n",arr[1]);//stampa l elem in pos 1
    free(arr);//dealloco l'array dallo heap
    printf("%d \n",arr[1]);//non stampa l'elemento in quanto ho liberato lo spazio sullo heap
}

