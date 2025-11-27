#ifndef TREEV1_H
#define TREEV1_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} NodeType, *NodePtr;

void init_tree(NodePtr *tree) {
    *tree = NULL;
}

void insert_leaf(NodePtr *tree, int data) {
    NodePtr new_node =(NodePtr) malloc(sizeof(NodeType));

    if (new_node == NULL)
    {
        printf("Memory Allocation Failed!\n");

        return;
    }

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    
    // Use as to traverse throughout the tree!
    NodePtr *trav = tree;
    
    while (*trav != NULL)
    {
        if (data > (*trav)->data)
        {
            trav = &(*trav)->right;
        }
        else
        {
            trav = &(*trav)->left;
        }
        
    }

    *trav = new_node;
    
    printf("Insertion is successful!\n");
}

// Get the depth or height of the tree
int tree_height(NodePtr tree) {
    // 
}

// Get the width of the tree
int tree_width(NodePtr tree) {
    // 
}

// Search Function
bool search_leaf(NodePtr tree, int to_find) {
    /* Traverse through the tree maybe going at the left side first? */

    return false;
}

// Remove / Delete function
int remove_leaf(NodePtr *tree, int to_delete) {
    // 
}

void in_order(NodePtr tree) {
    if(tree != NULL) {
        // visit the left side of the tree
        in_order(tree->left);
        printf("%d ", tree->data);

        // then visit the right side of the tree
        in_order(tree->right);
    }
}

void pre_order(NodePtr tree) {
    if (tree != NULL)
    {
        printf("%d ", tree->data);

        // visit the left side of the tree
        pre_order(tree->left);
        // then visit the right side of the tree
        pre_order(tree->right);
    }
    
}

void post_order(NodePtr tree) {
    if (tree != NULL)
    {
        // visit the left side of the tree
        post_order(tree->left);
        // then visit the right side of the tree
        post_order(tree->right);

        printf("%d ", tree->data);
    }
    
}


#endif