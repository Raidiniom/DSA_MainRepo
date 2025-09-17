#ifndef ADT_h
#define ADT_h

// Description here!

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define max_size 10

typedef struct {
    char name[24];
    int stock;
} Product;

typedef struct {
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
void initADTLIST(ADTList* list) {
    list->count = 0;
}

bool isEmpty(ADTList list) {
    return list.count == 0;
}

bool isFull(ADTList list) {
    return list.count >= max_size;
}

void insertFirst(ADTList* list, Product prod) {
    if (!isFull(*list))
    {
        list->count++;

        for (int i = list->count - 1; i >= 0; i--)
        {
            list->prodList[i + 1] = list->prodList[i];
        }
        
        list->prodList[0] = prod;
    }
    else
    {
        printf("List is full\n");
    }
    
}

void insertLast(ADTList* list, Product prod) {
    if (!isFull(*list))
    {
        list->prodList[list->count++] = prod;
    }
    else
    {
        printf("List is full\n");
    }
    
}

void insertAt(ADTList* list, Product prod, int position) {
    if (!isFull(*list))
    {
        list->count++;
        int index = position - 1;
        for (int i = list->count - 1; i > index; i--)
        {
            list->prodList[i] = list->prodList[i - 1];
        }
        
        list->prodList[index] = prod;
    }
    else
    {
        printf("List is full\n");
    }
    
}

void deleteFirst(ADTList* list) {
    if (!isEmpty(*list))
    {
        for (int i = 0; i < list->count; i++)
        {
            list->prodList[i] = list->prodList[i + 1];
        }
        list->count--;
    }
    else
    {
        printf("List is Empty\n");
    }
    
}

void deleteLast(ADTList* list) {
    if (!isEmpty(*list))
    {
        list->count--;
    }
    else
    {
        printf("List is Empty\n");
    }
    
}

void deleteAt(ADTList* list, int position) {
    if (!isEmpty(*list))
    {
        int index = position - 1;

        for (int i = index; i < list->count; i++)
        {
            list->prodList[i] = list->prodList[i + 1];
        }
        
        list->count--;
    }
    else
    {
        printf("List is Empty\n");
    }
    
}

void displayList(ADTList list) {
    for (int i = 0; i < list.count; i++)
    {
        displayProduct(list.prodList[i]);
    }
    
}

#endif