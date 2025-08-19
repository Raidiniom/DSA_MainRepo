#include <stdio.h>

#include "linklist.h"
// #include "charlist.h"

void main() {
    linkList myList = NULL;

    insert(&myList, 'g');
    insert(&myList, 'f');
    insert(&myList, 'e');
    insert(&myList, 'd');
    insert(&myList, 'a');

    display(myList);

    printf("\n");
    insertSorted(&myList, 'b');

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