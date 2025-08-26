#include <stdio.h>

#include "linklist.h"
// #include "charlist.h"

void main() {
    linkList myList = NULL;

    insertFront(&myList, 'g');
    insertFront(&myList, 'f');
    insertFront(&myList, 'e');
    insertFront(&myList, 'd');
    insertFront(&myList, 'b');

    display(myList);

    insertSorted(&myList, 'x');
    insertSorted(&myList, 'c');
    // insertSorted(&myList, 'a');

    // debug_sort(&myList, 'c');

    printf("\n");
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