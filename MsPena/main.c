#include <stdio.h>

#include "linklist.h"

void main() {
    linkList myList = NULL;

    insert(&myList, 'u');
    insert(&myList, 's');
    insert(&myList, 'c');
    insert(&myList, 'a');
    insert(&myList, 'b');
    insert(&myList, 'z');
    insert(&myList, 'x');

    display(myList);

    delete(&myList, 'b');

    display(myList);
}