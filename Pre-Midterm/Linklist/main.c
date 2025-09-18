#include "linklist.h"

void main() {
    Node list = initList();

    insertFirst(&list, createBox("Pencils", 5.98));
    insertFirst(&list, createBox("Erasers", 5.01));
    insertFirst(&list, createBox("Bond Paper", 13.9));

    insertLast(&list, createBox("Pad Paper", 11.50));
    insertLast(&list, createBox("Pad Paper", 11.50));
    insertLast(&list, createBox("Pad Paper", 11.50));

    displayLinkList(list);
}