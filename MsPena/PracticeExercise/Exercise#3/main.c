#include <stdio.h>

#include "function.h"

void main() {
    // ArrayList myAList;
    // initArrayList(&myAList);

    // insertLast(&myAList, createStudentType(createNameType("Voltaire", 'L', "Ratilla"), "07402931", "BSIT", 2));
    // insertLast(&myAList, createStudentType(createNameType("Voltaire", 'L', "Ratilla"), "07402931", "BSIT", 2));
    // insertLast(&myAList, createStudentType(createNameType("Voltaire", 'L', "Ratilla"), "07402931", "BSIT", 2));

    // displayArrayList(myAList);

    // printf("\n\n");
    // insertFront(&myAList, createStudentType(createNameType("Charles", 'C', "Bocque"), "223322", "BSIS", 2));
    // insertFront(&myAList, createStudentType(createNameType("John", 'M', "Gerozaga"), "114499", "BSIS", 2));
    // insertLastUnique(&myAList, createStudentType(createNameType("Ivan", 'Z', "Kyer"), "0922831", "BSIS", 2));
    // displayArrayList(myAList);

    // printf("\n\n");
    // insertAtPosition(&myAList, createStudentType(createNameType("Clarence", 'A', "Diango"), "2889123", "BSIS", 2), 4);
    // displayArrayList(myAList);

    // ArrayList bsisList = separateCourse(&myAList, "BSIS");

    // printf("\nInitial List\n");
    // displayArrayList(myAList);

    // printf("\nBSIS List\n");
    // displayArrayList(bsisList);

    LinkList myLList;
    initLinkList(&myLList);

    insertFrontL(&myLList, createStudentType(createNameType("Clarence", 'A', "Diango"), "2889123", "BSIS", 2));
    insertFrontL(&myLList, createStudentType(createNameType("Voltaire", 'L', "Ratilla"), "07402931", "BSIT", 2));
    insertFrontL(&myLList, createStudentType(createNameType("Charles", 'C', "Bocque"), "223322", "BSIS", 2));
    insertFrontL(&myLList, createStudentType(createNameType("John", 'M', "Gerozaga"), "114499", "BSIS", 2));

    insertLastL(&myLList, createStudentType(createNameType("Ivan", 'Z', "Kyer"), "0922831", "BSIS", 2));
    insertLastUniqueL(&myLList, createStudentType(createNameType("Yousif", 'K', "Cabalos"), "35232312", "BSIT", 2));
    insertLastUniqueL(&myLList, createStudentType(createNameType("Voltaire", 'L', "Ratilla"), "07402931", "BSIT", 2));

    displayLinkList(myLList);
}