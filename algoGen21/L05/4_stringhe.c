#include <stdio.h>
#include <stdlib.h>
#define L 2
#define L0 3

char *read_line(char c){
    char *str = malloc(sizeof(char)*L0);
    int size=L0;
    char r;
    for (int i=0; ;i++){
        if (size<=i){
            size+=L;
            str=realloc(str, size*sizeof(char));
        }
        scanf("%c", &r);
        if (r==c) break;
        str[i]=r;
        size++;
    }
    return str;

}

int main (){
    char term = ':';
    char *s = malloc(sizeof(char));
    s=read_line(term);
    printf("%s\n", s);
}