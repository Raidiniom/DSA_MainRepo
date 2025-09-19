#include "linklist.h"

void main() {
    Node list = initList();

    insertFirst(&list, createBox("Pencils", 5.98));
    insertFirst(&list, createBox("Erasers", 5.01));
    insertFirst(&list, createBox("Bond Paper", 13.9));

    insertLast(&list, createBox("Pad Paper", 11));
    insertLast(&list, createBox("Pad Paper", 12));
    insertLast(&list, createBox("Pad Paper", 13));
    
    insertAt(&list, createBox("Medals", 50.02), 5);
    
    insertMiddle(&list, createBox("Grenades", 65.96));
    
    printf("Initial List\n");
    displayLinkList(list);

    deleteFirst(&list);
    deleteLast(&list);
    deleteAt(&list, 4);
    
    printf("\nDeleting List\n");
    displayLinkList(list);
}