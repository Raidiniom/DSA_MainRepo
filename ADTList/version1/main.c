#include <stdio.h>

#include "adt.h"

void main() {
    ADTList myList;
    initADTLIST(&myList);

    insertFirst(&myList, createProduct("Camon 30", 50));
    insertFirst(&myList, createProduct("Iphone 16", 100));
    insertFirst(&myList, createProduct("Samsung Galaxy", 20));
    insertLast(&myList, createProduct("Honor X8C", 15));
    insertAt(&myList, createProduct("4Tech Mouse", 10), 2);

    insertLast(&myList, createProduct("Logitech K380", 25));
    insertFirst(&myList, createProduct("Macbook Air M3", 12));
    insertLast(&myList, createProduct("Dell XPS 13", 8));
    insertAt(&myList, createProduct("HP Envy x360", 18), 5);
    insertLast(&myList, createProduct("ASUS ROG Phone", 7));

    printf("Inserting Data:\n");
    displayList(myList);

    deleteFirst(&myList);
    deleteLast(&myList);
    deleteAt(&myList, 2);

    printf("\n\nDeleting Data:\n");
    displayList(myList);
}