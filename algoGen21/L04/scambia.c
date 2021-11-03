#include <stdio.h>

void scambia (int *p, int *q){
    int tmp=0;
    tmp = *p;
    *p=*q;
    *q=tmp;
}

int main (){
    int x,y;
    scanf("%d%d", &x, &y);
    scambia(&x, &y);
    printf("x: %d \t y: %d\n", x, y);
}