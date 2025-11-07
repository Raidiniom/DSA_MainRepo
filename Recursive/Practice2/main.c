#include "recur.h"

void main() {
    Node my = NULL;

    insertProd(&my, createProduct("Pad Paper", 50, 45));
    insertProd(&my, createProduct("Yellow Paper", 60, 25.5));
    insertProd(&my, createProduct("Panda Ballpen", 150, 20));
    insertProd(&my, createProduct("Pencil", 100, 15.20));

    recursiveDisplay(my);

    displayProduct(recursiveSearch(my, 150));
}