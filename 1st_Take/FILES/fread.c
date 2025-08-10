#include <stdio.h>

#include "filesthing.h"

int main() {

    FILE *read_file;

    Product prod;

    read_file = fopen("Product_Report.txt", "rb");

    if (read_file != NULL)
    {
        while (fread(&prod, sizeof(Product), 1, read_file))
        {
            display_product(prod);
            printf("\n");
        }
        
    }
    
    fclose(read_file);

    return 0;
}