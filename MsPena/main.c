#include <stdio.h>

#include "charlist.h"

void main() {
    charList myList;
    initList(&myList);

    myList.count = 10;
    myList.elem[0] = 'u';
    myList.elem[1] = 's';
    myList.elem[2] = 'c';
    myList.elem[3] = 't';
    myList.elem[4] = 'c';
    myList.elem[5] = 'a';
    myList.elem[6] = 'b';
    myList.elem[7] = 'e';
    myList.elem[8] = 'f';
    myList.elem[9] = 'u';
    displayCharList(myList);

    delete(&myList, 'c');

    displayCharList(myList);
}