#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} *Node;

void initTree(Node* node) {
    *node = NULL;
}

bool duplicateData(Node node, int data) {
    if (node == NULL) return false;
    
    return (data == node->data) || (duplicateData(node->left, data)) || (duplicateData(node->right, data));
}

Node* searchNode(Node* node, int data) {
    if (*node == NULL) return NULL;
    if ((*node)->data == data) return node;

    Node* leftSearch = searchNode(&(*node)->left, data);
    if (leftSearch != NULL) return leftSearch;

    return searchNode(&(*node)->right, data);
}

void insertNode(Node* node, int data) {
    if (duplicateData(*node, data))
    {
        printf("%d is a duplicate!\n", data);
        return;
    }
    

    if (*node == NULL)
    {
        Node newNode = (Node) malloc(sizeof(struct node));

        if (newNode != NULL)
        {
            newNode->data = data;
            newNode->left = NULL;
            newNode->right = NULL;

            *node = newNode;
        }
        
    }
    else
    {
        if (data < (*node)->data)
        {
            insertNode(&(*node)->left, data);
        }
        else
        {
            insertNode(&(*node)->right, data);
        }
        
    }
    
}

// Helped by Chatgpt
void deleteNode(Node* node, int data) {
    Node* locatedNode = searchNode(node, data);

    if (locatedNode == NULL || *locatedNode == NULL) return;
    

    Node target = *locatedNode;

    if (target->left == NULL && target->right == NULL)
    {
        free(target);
        *locatedNode = NULL;
        return;
    }
    
    if (target->left == NULL || target->right == NULL)
    {
        Node child = (target->left != NULL) ? target->left : target->right;
        free(target);
        *locatedNode = child;
        return;
    }
    
    Node succParent = target;
    Node successor = target->right;
    while (successor->left != NULL)
    {
        succParent = successor;
        successor = successor->left;
    }
    
    target->data = successor->data;
    
    if (succParent->left == successor)
    {
        succParent->left = successor->right;
    }
    else
    {
        succParent->right = successor->right;
    }
    

    free(successor);
}


// Displaying the Tree
void postOrder(Node node) {
    if (node != NULL)
    {
        postOrder(node->left);
        postOrder(node->right);
        
        printf("%d ", node->data);
    }
    
}

void preOrder(Node node) {
    if (node != NULL)
    {
        printf("%d ", node->data);

        preOrder(node->left);
        preOrder(node->right);
    }
    
}

void inOrder(Node node) {
    if (node != NULL)
    {
        inOrder(node->left);
        printf("%d ", node->data);
        inOrder(node->right);
    }
    
}

// From ChatGPT - ASCII Tree Printer
void printTree(Node node, int space) {
    if (node == NULL)
        return;

    // Increase distance between levels
    space += 5;

    // Print right child first
    printTree(node->right, space);

    // Print current node after spaces
    printf("\n");
    for (int i = 5; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", node->data);

    // Print left child
    printTree(node->left, space);
}


#endif