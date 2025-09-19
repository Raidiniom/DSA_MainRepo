#include "linkstack.h"

void main() {
    Node numlist = initList();

    pushSorted(&numlist, 1);
    pushSorted(&numlist, 7);
    pushSorted(&numlist, 4);
    pushSorted(&numlist, 2);

    displayStack(&numlist);
}