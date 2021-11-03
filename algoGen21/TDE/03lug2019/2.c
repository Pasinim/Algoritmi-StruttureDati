#include "2.h" 
int main (void){
    Bit_node root=NULL;
    insert(root, 1);
    printf("root %d;\n", root->value);
    insert(root, 10);
    print_tree(root, 0);
}