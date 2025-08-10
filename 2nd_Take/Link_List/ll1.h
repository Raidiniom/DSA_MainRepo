#ifndef LL1_H
#define LL1_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String[20];

typedef struct {
    String name;
    float price;
    int amount;
} Product;

typedef struct node {
    Product product;
    struct node* next;
} Node, *NodePtr;

Product create_product(String name, float price, int amount) {
    Product start_product;

    strcpy(start_product.name, name);
    start_product.price = price;
    start_product.amount = amount;

    return start_product;
}

void display_linklist(NodePtr list) {
    NodePtr trav = list;

    while (trav != NULL)
    {
        printf("%s - %.2f - %d\n", trav->product.name, trav->product.price, trav->product.amount);
        trav = trav->next;
    }
    
}

#endif