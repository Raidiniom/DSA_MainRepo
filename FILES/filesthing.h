#ifndef FILESTHING_H
#define FILESTHING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String[20];

typedef struct {
    String prod_name;
    float prod_price;
} Product;

Product create_product(String name, float price) {
    Product start_product;

    strcpy(start_product.prod_name, name);
    start_product.prod_price = price;

    return start_product;
}

void display_product(Product prod) {
    printf("%15s - PHP %.2f", prod.prod_name, prod.prod_price);
}

#endif