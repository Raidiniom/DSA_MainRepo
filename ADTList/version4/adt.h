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
    Product *prodList; // dynamically allocated
    int count;
} ADTList;



#endif