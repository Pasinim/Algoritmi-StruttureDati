// Key is a type defined elsewhere
#include <stdio.h>
#include <stdlib.h>
#define Key int

typedef struct {
    Key *c;
    int lo;
    int hi;
    int len;
    int n;
} Ds;


Ds *ds_new() {
    Ds *new = malloc(sizeof(Ds));
    new -> len = 1;
    new -> n = new -> lo = new -> hi = 0;
    new -> c = malloc (new -> len *sizeof(Key));
return new;
}

void ds_rebuild(Ds *y) {
    Key *tmp = malloc(2 * y-> len * sizeof(Key));
    for (int i = 0; i < y -> n; i++)
        tmp[i] = y -> c[(i + y -> lo) % y -> len];
    free(y -> c);
    y -> c = tmp;
    y -> lo = 0;
    y -> hi = y -> n;
    y -> len *=2;
}

void ds_insert(Ds *y, Key in) {
    y -> c[y -> hi] = in;
    y -> hi += 1;
    if (y -> hi == y-> len)
        y -> hi = 0;
    y -> n += 1;
    if (y -> n == y -> len)
        ds_rebuild(y);
}

Key ds_remove (Ds *y) {
    // assumes y is not empty
    Key out = y -> c[y -> lo];
    y -> lo += 1;
    if (y -> lo == y -> len)
        y -> lo = 0;
    y -> n -= 1;
return out;
}

// Esercizio 3
void ds_print(Ds *y){
    for (int i = 0; i < y -> n; i++)
        printf("%d ", y -> c[(y -> lo + i)% y -> n]);
}

int main (void){
    Ds *coda = ds_new();
    ds_insert(coda, 111);
    ds_insert(coda, 11);
    ds_insert(coda, 22);
    ds_insert(coda, 3);

    ds_print(coda);



}