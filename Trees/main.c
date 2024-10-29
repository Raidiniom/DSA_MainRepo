#include <stdio.h>

#include "tree_headers/treev1.h"

int main() {
    
    NodePtr my_tree;

    init_tree(&my_tree);

    insert_leaf(&my_tree, 1); // Root
    insert_leaf(&my_tree, -22); // Left
    insert_leaf(&my_tree, 31); // Right
    insert_leaf(&my_tree, -6); // Left
    insert_leaf(&my_tree, 11); // Right
    insert_leaf(&my_tree, 8); // Right
    insert_leaf(&my_tree, 5); // Right
    insert_leaf(&my_tree, -27); // Left

    printf("\nIn Order:");
    in_order(my_tree);

    printf("\nPre Order:");
    pre_order(my_tree);

    printf("\nPost Order:");
    post_order(my_tree);
    
    return 0;
}