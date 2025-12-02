#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} *Node;

void initTree(Node* tr) {
    *tr = NULL;
}

void insertData(Node* tr, int data) {
    Node* in = tr;

    while (*in != NULL)
    {
        in = (data < (*in)->data) ? &(*in)->left : &(*in)->right;
    }

    if (*in == NULL)
    {
        *in = malloc(sizeof(Node));

        (*in)->data = data;
        (*in)->left = NULL;
        (*in)->right = NULL;
    }
    
}

void deleteData(Node* tr, int data) {
    Node* de = tr;

    while (*de != NULL && data != (*de)->data)
    {
        de = (data < (*de)->data) ? &(*de)->left : &(*de)->right;
    }
    
    if (*de != NULL)
    {
        printf("\n[DEBUG] Node: %d, Left: %d, Right: %d", (*de)->data, ((*de)->left) ? (*de)->left->data : INT_MAX, ((*de)->right) ? (*de)->right->data : INT_MAX);

        Node delNode = *de;

        if ((*de)->left == NULL)
        {
            de = &(*de)->right;
        }
        else if ((*de)->right == NULL)
        {
            de = &(*de)->left;
        }
        else
        {
            /* code */
        }
        
    }
    
}

void inOrder(Node tr) {
    if (tr)
    {
        inOrder(tr->left);
        printf("%d ", tr->data);
        inOrder(tr->right);
    }
    
}

void preOrder(Node tr) {
    if (tr)
    {
        printf("%d ", tr->data);
        preOrder(tr->left);
        preOrder(tr->right);
    }
    
}

void postOrder(Node tr) {
    if (tr)
    {
        postOrder(tr->left);
        postOrder(tr->right);
        printf("%d ", tr->data);
    }
    
}

#endif