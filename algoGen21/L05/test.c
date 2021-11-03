#include <stdlib.h>
#include <stdio.h>
//provo ad eseguire la free
 int main (){
    int *a;
    a=malloc(10);
    *a=rand();
    printf("Prima della free: %d\t indirizzo: %p \n", *a, &a );
    free(a);
    printf("Dopo la free: %d\tindirizzo: %p \n", *a, &a );
    //*a=100;
    //printf("Dopo la free: %d\tindirizzo: %p \n", *a, &a );
 }