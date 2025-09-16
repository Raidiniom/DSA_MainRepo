#ifndef ADT_H
#define ADT_H

// Description here!

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define max_size 10

typedef struct {
    char name[24];
    int stock;
} Product;

typedef struct node {
    Product prodList[max_size];
    int count;
} ADTList;

// Helper Functions
Product createProduct(char* name, int stock) {
    Product initialize;

    strcpy(initialize.name, name);
    initialize.stock = stock;

    return initialize;
}

void displayProduct(Product prod) {
    printf("%-16s    %d\n", prod.name, prod.stock);
}

// Operations
void initADTList(ADTList** list) {
    *list = (ADTList*) malloc(sizeof(struct node));
    (*list)->count = 0;
}

bool isEmpty(ADTList list) {
    return list.count == 0;
}

bool isFull(ADTList list) {
    return list.count >= max_size;
}

void insertFirst(ADTList** list, Product prod) {
    if (!isFull(**list))
    {
        (*list)->count++;

        for (int i = (*list)->count - 1; i >= 0; i--)
        {
            (*list)->prodList[i + 1] = (*list)->prodList[i];
        }
        
    }
    else
    {
        printf("List is full");
    }
    
}

#endif