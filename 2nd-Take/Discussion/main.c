#include <stdio.h>

#include "linklist.h"
// #include "charlist.h"

void main() {
    linkList myList = NULL;

    insertFront(&myList, 'g');
    insertFront(&myList, 'f');
    insertFront(&myList, 'e');
    insertFront(&myList, 'c');
    insertFront(&myList, 'b');

    insertLast(&myList, 'n');
    insertAt(&myList, 'Y', 4); // Disregard this!
    display(myList);

    insertSorted(&myList, 'a');
    insertSorted(&myList, 'd');
    insertSorted(&myList, 'x');
    display(myList);

    // Array 
    // charList myList;
    // initList(&myList);

    // insert(&myList, 'u');
    // insert(&myList, 's');
    // insert(&myList, 'c');
    // insert(&myList, 'u');
    // insert(&myList, 's');
    // insert(&myList, 'c');
    // insert(&myList, 'u');
    // insert(&myList, 's');
    // insert(&myList, 'c');

    // displayCharList(myList);

    // deleteAll(&myList, 'u');

    // displayCharList(myList);
}