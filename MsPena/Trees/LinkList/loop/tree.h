#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} *Node, NodeSize;

void initTree(Node* tree) {
    *tree = NULL;
}

void insertElem(Node* tree, int data) {
    if (*tree == NULL)
    {
        *tree = (Node) malloc(sizeof(NodeSize));

        (*tree)->data = data;
        (*tree)->left = NULL;
        (*tree)->right = NULL;

    }
    else
    {
        Node* insertNode = tree;

        while (*insertNode != NULL && (*insertNode)->data != data)
        {
            insertNode = (data < (*insertNode)->data) ? &(*insertNode)->left : &(*insertNode)->right;
        }
        
        *insertNode = (Node) malloc(sizeof(NodeSize));

        (*insertNode)->data = data;
        (*insertNode)->left = NULL;
        (*insertNode)->right = NULL;

    }

}

void deleteElem(Node* tree, int data) {
    Node* deleteNode = tree;

    while (*deleteNode != NULL && (*deleteNode)->data != data)
    {
        deleteNode = (data < (*deleteNode)->data) ? &(*deleteNode)->left : &(*deleteNode)->right;
    }

    if (*deleteNode == NULL)
    {
        printf("Elem not found!\n");
        return;
    }
    

    Node temp = *deleteNode;
    
    if (temp->left == NULL)
    {
        *deleteNode = temp->right;
        free(temp);
    }
    else if (temp->right == NULL)
    {
        *deleteNode = temp->left;
        free(temp);
    }
    else
    {
        // Successor
        Node* successor = &temp->right;

        while ((*successor)->left != NULL)
        {
            successor = &(*successor)->left;
        }
        
        temp->data = (*successor)->data;

        Node hold = *successor;
        *successor = (*successor)->right;
        free(hold);

        // Predessor
        // Node* predessor = &temp->left;

        // while ((*predessor)->right != NULL)
        // {
        //     predessor = &(*predessor)->right;
        // }
        
        // temp->data = (*predessor)->data;

        // Node hold = *predessor;
        // *predessor = (*predessor)->left;
        // free(hold);
    }
    

}

void inOrder(Node tree) {
    if (tree)
    {
        inOrder(tree->left);
        printf("%d ", tree->data);
        inOrder(tree->right);
    }
    
}

void preOrder(Node tree) {
    if (tree)
    {
        printf("%d ", tree->data);
        preOrder(tree->left);
        preOrder(tree->right);
    }
    
}

void postOrder(Node tree) {
    if (tree)
    {
        postOrder(tree->left);
        postOrder(tree->right);
        printf("%d ", tree->data);
    }
    
}

#endif