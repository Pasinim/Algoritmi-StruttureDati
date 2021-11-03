#include "tree.h"
#define L 7

int costoMax (Bit_node b, int cost){
    if (!b){
        return cost;
    }
    return costoMax(b->r, b->value+cost);
}

int main (){
    //root=malloc(sizeof(struct bit_node));
    Bit_node root=NULL;
    //int n=L, x;
    // for (int i=0; i<n; i++){
    //     scanf("%d", &x);
    //     root=insert_inorder(root, x);

    // }
    root=insert_inorder(root, 4 );
    root=insert_inorder(root, 7);
    root=insert_inorder(root, 2 );
    root=insert_inorder(root, 3 );
    root=insert_inorder(root, 6 );
    Bit_node new =NULL;
    int a[] = {10, 4, 7, 2, 0, 3, 6, 8, 9, 0, 0, 1, 2, 4, 5};
    new=arr2tree(a, 15,0);
    print_asummary(new,0);
    
    printf("\n");bit_inorder(root);
    printf("costo max %d\n", costoMax(root, 0));
    root = root->r;
    printf("root->r->value: %d\n", root->value );
}