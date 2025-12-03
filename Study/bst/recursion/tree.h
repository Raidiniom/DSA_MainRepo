#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} *Node;

void initTree(Node* tr) {
    *tr = NULL;
}

void insertData(Node* tr, int data) {
    if (*tr == NULL)
    {
        *tr = malloc(sizeof(struct node));

        (*tr)->data = data;
        (*tr)->left = NULL;
        (*tr)->right = NULL;
    }
    else if (data < (*tr)->data)
    {
        insertData(&(*tr)->left, data);
    }
    else
    {
        insertData(&(*tr)->right, data);
    }
    
}

void deleteData(Node* tr, int data) {
    if (*tr != NULL && (*tr)->data == data)
    {
        Node delNode = *tr;

        if (delNode->left == NULL)
        {
            *tr = delNode->right;
            free(delNode);
        }
        else if (delNode->right == NULL)
        {
            *tr = delNode->left;
            free(delNode);
        }
        else
        {
            Node* successor = &delNode->right;
            for (; (*successor)->left != NULL; successor = &(*successor)->left){}
            
            (*tr)->data = (*successor)->data;

            Node hold = *successor;
            *successor = (*successor)->right;
            free(hold);
        }
        
    }
    else if (data < (*tr)->data)
    {
        deleteData(&(*tr)->left, data);
    }
    else
    {
        deleteData(&(*tr)->right, data);
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