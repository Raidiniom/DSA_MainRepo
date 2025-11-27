#include <stdio.h>

#include "PPN/ppnlinklist.h"

void main() {
    LinkList myList;

    initLinkList(&myList);

    insertFirst(&myList, createStudentType(createNameType("Ratilla", "Voltaire", 'L'), "07402931", "BSIT", 2));
    insertFirst(&myList, createStudentType(createNameType("Gerozaga", "John", 'C'), "1", "BSIT", 2));
    insertFirst(&myList, createStudentType(createNameType("Diangco", "Clarence", 'A'), "2", "BSIT", 2));

    insertLast(&myList, createStudentType(createNameType("Pazon", "Paul", 'S'), "3", "BSIS", 3));
    
    insertAt(&myList, createStudentType(createNameType("Ceballos", "Yousif", 'R'), "3", "BSIT", 3), 3);

    printf("Inserted List\n");
    displayList(myList);
    
    printf("\n\nDeleting List\n");

    // deleteFirst(&myList);
    // deleteLast(&myList);
    deleteAt(&myList, 3);

    displayList(myList);
}