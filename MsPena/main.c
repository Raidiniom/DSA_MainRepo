#include <stdio.h>

#include "linklist.h"
// #include "charlist.h"

void main() {
    linkList myList = NULL;

    // insert(&myList, 'u');
    // insert(&myList, 's');
    // insert(&myList, 'c');
    insert(&myList, 'a');
    insert(&myList, 'h');
    insert(&myList, 'b');
    insert(&myList, 'z');
    insert(&myList, 'x');

    display(myList);

    deleteV2(&myList, 'b');

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