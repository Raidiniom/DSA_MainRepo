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

void rootCheck(Node tr) {
    printf("\nroot is %d\n", tr->data);
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

    while (*de != NULL && (*de)->data != data)
    {
        de = (data < (*de)->data) ? &(*de)->left : &(*de)->right;
    }
    
    if (*de != NULL)
    {
        Node delNode = *de;

        if (delNode->left == NULL)
        {
            *de = delNode->right;
            free(delNode);
        }
        else if (delNode->right == NULL)
        {
            *de = delNode->left;
            free(delNode);
        }
        else
        {
            Node* successor = &delNode->right;

            for (; (*successor)->left != NULL; successor = &(*successor)->left){}

            delNode->data = (*successor)->data;

            Node hold = *successor;
            *successor = (*successor)->right;
            free(hold);
            
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