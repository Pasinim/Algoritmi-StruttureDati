#include "mergesort.h"

int main (void){
    int a[]={10,1,3,5,9,7,8,2};
    merge_sort(a, 0, 8);
    stampa(a,8);
}