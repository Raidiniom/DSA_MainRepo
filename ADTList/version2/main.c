#include <stdio.h>

#include "adt.h"

void main() {
    ADTList list;
    initADTList(&list);

    insertFirst(&list, createProduct("Iphone 16", 100));
    insertFirst(&list, createProduct("Samsung Galaxy", 20));
    insertLast(&list, createProduct("Honor X8C", 15));
    insertLast(&list, createProduct("Logitech K380", 25));
    insertLast(&list, createProduct("ASUS ROG Phone", 7));
    insertAt(&list, createProduct("4Tech Mouse", 10), 2);
    insertAt(&list, createProduct("Camon 30", 40), 5);
    insertAt(&list, createProduct("Camon 30", 40), 6);
    insertAt(&list, createProduct("Camon 30", 40), 8);

    insertMiddle(&list, createProduct("Ramen", 333));

    printf("Inserting Data:\n");
    displayList(list);

    deleteAllOccurance(&list, "Camon 30");

    printf("\n\nDeleting Data:\n");
    displayList(list);
}