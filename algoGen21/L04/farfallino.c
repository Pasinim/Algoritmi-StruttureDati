#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char **argv){
    char *tmp=malloc(100);
    for (tmp=argv[1]; *tmp!='\0'; tmp++){
        if (*tmp=='a' || *tmp=='e' || *tmp=='i' || *tmp=='o' || *tmp=='u'){
            printf("%cf%c", *tmp, *tmp);
        }else{
            printf("%c", *tmp);
        }
    }
    printf("\n");
}
