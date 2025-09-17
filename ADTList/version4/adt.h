#ifndef ADT_H
#define ADT_H

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
    Product *prodList;
    int count;
    int capacity;
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
    (*list) = malloc(sizeof(struct node));
    (*list)->prodList = malloc(sizeof(Product) * 2);
    (*list)->count = 0;
    (*list)->capacity = 2;
}

bool isEmpty(ADTList list) {
    return list.count == 0;
}

bool isFull(ADTList list) {
    return list.count >= list.capacity;
}

void insertFirst(ADTList** list, Product product) {
    if (!isFull(**list))
    {
        for (int i = (*list)->count; i > 0; i--)
        {
            (*list)->prodList[i] = (*list)->prodList[i - 1];
        }
        
        (*list)->count++;
        (*list)->prodList[0] = product;
    }
    else
    {
        (*list)->capacity *= 2;

        (*list)->prodList = realloc((*list)->prodList, sizeof(Product) * (*list)->capacity);

        if ((*list)->prodList != NULL)
        {
            for (int i = (*list)->count; i > 0; i--)
            {
                (*list)->prodList[i] = (*list)->prodList[i - 1];
            }
            
            (*list)->count++;
            (*list)->prodList[0] = product;
        }
    }
}

void insertLast(ADTList** list, Product product) {
    if (!isFull(**list))
    {
        (*list)->prodList[(*list)->count++] = product;
    }
    else
    {
        (*list)->capacity *= 2;

        (*list)->prodList = realloc((*list)->prodList, (*list)->capacity * sizeof(Product));

        if ((*list)->prodList != NULL)
        {
            (*list)->prodList[(*list)->count++] = product;
        }
        
    }
    
}

void insertAt(ADTList** list, Product product, int position) {
    int index = position - 1;
    if (!isFull(**list))
    {
        for (int i = (*list)->count; i > index; i--)
        {
            (*list)->prodList[i] = (*list)->prodList[i - 1];
        }

        (*list)->prodList[index] = product;

        (*list)->count++;
    }
    else
    {
        (*list)->capacity *= 2;

        (*list)->prodList = realloc((*list)->prodList, sizeof(Product) * (*list)->capacity);

        if ((*list)->prodList != NULL)
        {
            for (int i = (*list)->count; i > index; i--)
            {
                (*list)->prodList[i] = (*list)->prodList[i - 1];
            }
            
            (*list)->prodList[index] = product;
            
            (*list)->count++;
        }
        
    }
    
}

void displayList(ADTList list) {
    for (int i = 0; i < list.count; i++)
    {
        displayProduct(list.prodList[i]);
    }
    
}

#endif