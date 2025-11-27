#include <stdio.h>

#include "filesthing.h"

int main() {
    Product list[5];

    list[0] = create_product("Sujo", 50.25);
    list[1] = create_product("Red Horse", 100.20);
    list[2] = create_product("Lemondo", 25.75);
    list[3] = create_product("Ice Tea", 12.05);
    list[4] = create_product("Coppiku", 15.12);


    FILE *product_file;

    product_file = fopen("Product_Report.txt", "wb");

    if (product_file != NULL)
    {
        fwrite(list, sizeof(Product), 5, product_file);
    }

    fclose(product_file);
    

    return 0;
}