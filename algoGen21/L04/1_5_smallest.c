#include <stdio.h>
#include <stdlib.h>

int *smallest(int a[], int n){
    int *min; //se non avessi l'assegmento a riga 8 dovrei fare una malloc
    int *p;
    p=a; //li assegno fuori altrimenti min non viene allocato a nulla
    min=p;
    for (p=a; p<a+n; p++){
        printf("%d\t", *p);
        if (*p<*min){
            min=p;
        }
    }
    return min;
}
int main (){
    int arr[]={12, 3213, 43, 34,343,3,1};
    int n=7;
    printf( "Smallest: %d\n", *smallest( arr, n ) );

}