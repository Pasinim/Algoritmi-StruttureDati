#include "tree.h"


int main (void){
    Bit_node root=NULL;
    root=insert_inorder(root,5);
    root=insert_inorder(root,8);
    root=insert_inorder(root,9);
    root=insert_inorder(root,7);
    bit_inorder(root);
    printf("\n");
    print_asummary(root, 0);
}