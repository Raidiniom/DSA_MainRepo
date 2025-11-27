#ifndef ADT_H
#define ADT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define max_size 2

typedef struct {
    char name[24];
    int stock;
} Product;

typedef struct {
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
void initADTList(ADTList* list) {
    list->prodList = malloc(sizeof(Product) * max_size);
    list->count = 0;
    list->capacity = max_size;
}

bool isEmpty(ADTList list) {
    return list.count == 0;
}

bool isFull(ADTList list) {
    return list.count >= list.capacity;
}

void insertFirst(ADTList* list, Product product) {
    if (!isFull(*list))
    {
        for (int i = list->count; i > 0; i--)
        {
            list->prodList[i] = list->prodList[i - 1];
        }
        
        
        list->prodList[0] = product;
        list->count++;
    }
    else
    {
        list->capacity *= 2;
        
        list->prodList = realloc(list->prodList, list->capacity * sizeof(Product));
        
        if (list->prodList != NULL)
        {
            for (int i = list->count; i > 0; i--)
            {
                list->prodList[i] = list->prodList[i - 1];
            }
            
            list->prodList[0] = product;
            list->count++;
        }
        
    }
    
}

void insertLast(ADTList* list, Product product) {
    if (!isFull(*list))
    {
        list->prodList[list->count++] = product;
    }
    else
    {
        list->capacity *= 2;

        list->prodList = realloc(list->prodList, list->capacity * sizeof(Product));

        if (list->prodList != NULL)
        {
            list->prodList[list->count++] = product;
        }

    }
    
}

void insertAt(ADTList* list, Product product, int position) {
    int index = position - 1;

    if (!isFull(*list))
    {
        for (int i = list->count; i > index; i--)
        {
            list->prodList[i] = list->prodList[i - 1];
        }
        
        list->prodList[index] = product;
        list->count++;
    }
    else
    {
        list->capacity *= 2;

        list->prodList = realloc(list->prodList, list->capacity * sizeof(Product));

        if (list->prodList != NULL)
        {
            for (int i = list->count; i > index; i--)
            {
                list->prodList[i] = list->prodList[i - 1];
            }
            
            list->prodList[index] = product;
            list->count++;
        }
        
    }
    
}

void insertMiddle(ADTList* list, Product product) {
    int midpos = list->count / 2;

    if (!isFull(*list))
    {
        for (int i = list->count; i > midpos; i--)
        {
            list->prodList[i] = list->prodList[i - 1];
        }
        
        list->prodList[midpos] = product;
        list->count++;
    }
    else
    {
        list->capacity *= 2;

        list->prodList = realloc(list->prodList, list->capacity * sizeof(Product));

        if (list->prodList != NULL)
        {
            for (int i = list->count; i > midpos; i--)
            {
                list->prodList[i] = list->prodList[i - 1];
            }
            
            list->prodList[midpos] = product;
            list->count++;
        }
        
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

void deleteFirstOccurence(ADTList* list, char* name) {
    if (!isEmpty(*list))
    {
        int index;

        for (index = 0; index < list->count && strcmp(list->prodList[index].name, name) != 0; index++){}
        
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

void deleteAllOccurence(ADTList* list, char* name) {
    if (!isEmpty(*list))
    {
        int i, j;

        for (i = j = 0; i < list->count; i++)
        {
            if (strcmp(list->prodList[i].name, name) != 0)
            {
                list->prodList[j] = list->prodList[i];
                j++;
            }
            
        }
        
        list->count = j;
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

void freeADTList(ADTList* list) {
    free(list->prodList);
    list->prodList = NULL;
    list->capacity = max_size;
    list->count = 0;
}

#endif