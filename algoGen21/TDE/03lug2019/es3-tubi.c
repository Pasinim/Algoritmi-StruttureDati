#include <stdio.h>
#include <stdlib.h>

void scambia (int a[], int i, int j){
    int tmp=a[i];
    a[i]=a[j];
    a[j]=tmp;
    return;
}

void selectionSort (int a[], int length){
    int iMax=0, max=a[iMax];
    if (length==0 || length==1)
        return;
    for (int i=1; i<length; i++ ){
        if (a[i]>=max){
            max=a[i];
            iMax=i;
        }
    }
    scambia(a, iMax, length-1);
    return selectionSort(a, length-1);
}
void stampa (int a[], int l){
    for (int i=0; i<l; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
int segmax(int a[], int lun, int seg){
    int sum=a[0], n_seg=0;
    for (int i=1; sum<=lun; i++){
        sum+=a[i];
        n_seg++;
    }
    return n_seg;
}

int main (){
    int l, n;
    scanf("%d %d",&l,&n );
    int a[] ={7,5,2,6,2,3};
    selectionSort(a, n);
    stampa(a, n);
    printf("Numero massimo di segmenti: %d\n", segmax(a, l, n));

}