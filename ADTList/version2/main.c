#include <stdio.h>

#include "adt.h"

void main() {
    ADTList list;
    initADTList(&list);

    insertFirst(&list, createProduct("Camon 30", 50));
    insertFirst(&list, createProduct("Iphone 16", 100));
    insertFirst(&list, createProduct("Samsung Galaxy", 20));
    insertLast(&list, createProduct("Honor X8C", 15));
    insertAt(&list, createProduct("4Tech Mouse", 10), 2);

    insertLast(&list, createProduct("Logitech K380", 25));
    insertFirst(&list, createProduct("Macbook Air M3", 12));
    insertLast(&list, createProduct("Dell XPS 13", 8));
    insertAt(&list, createProduct("HP Envy x360", 18), 5);
    insertLast(&list, createProduct("ASUS ROG Phone", 7));

    printf("Inserting Data:\n");
    displayList(list);

    deleteFirst(&list);
    deleteLast(&list);
    deleteAt(&list, 2);

    printf("\n\nDeleting Data:\n");
    displayList(list);
}