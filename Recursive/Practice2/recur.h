#ifndef RECUR_H
#define RECUR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char prodName[32];
    int stockAmnt;
    float price;
} ProductType;

typedef struct node {
    ProductType product;
    struct node* next;
} *Node, NodeSize;

// Helper
ProductType createProduct(char* prodName, int stockAmnt, float price) {
    ProductType initProd;

    strcpy(initProd.prodName, prodName);
    initProd.stockAmnt = stockAmnt;
    initProd.price = price;

    return initProd;
}

void displayProduct(ProductType product) {
    printf("%-34s | %d | %.2f\n", product.prodName, product.stockAmnt, product.price);
}

// Operations
void insertProd(Node* head, ProductType product) {
    Node newNode = (Node) malloc(sizeof(NodeSize));

    newNode->product = product;
    newNode->next = *head;
    *head = newNode;
}

void recursiveDisplay(Node head) {
    if (head != NULL)
    {
        displayProduct(head->product);
        recursiveDisplay(head->next);
    }
    
}

ProductType recursiveSearch(Node head, int stockAmnt) {
    if (head == NULL) return createProduct("Not Found", 404, 404);
    if (head->product.stockAmnt == stockAmnt) return head->product;
    return recursiveSearch(head->next, stockAmnt);
}

#endif 