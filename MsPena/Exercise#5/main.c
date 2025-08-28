#include <stdio.h>

#include "adtlistv2.h"

void main() {
    LIST *myList = malloc(sizeof(LIST));

    initialize(myList);

    insertLast(myList, create_student(create_name("Ratilla", "Voltaire", 'L'), "07402931", "BSIT-2"));
    insertLast(myList, create_student(create_name("Santos", "Angela", 'D'), "59012348", "BSIT-2"));
    insertLast(myList, create_student(create_name("Gerozaga", "John", 'S'), "98123477", "BSIT-2"));
    insertLast(myList, create_student(create_name("Dianco", "Clarence", 'N'), "74829103", "BSIT-2"));
    insertLast(myList, create_student(create_name("Kabanlit", "Ivan", 'R'), "10394857", "BSIT-2"));
    insertLast(myList, create_student(create_name("Magdalen", "Mary", 'P'), "82736491", "BSIT-2"));

    printList((*myList));

    printf("Located at %d", locate((*myList), "98123477"));

    delete(myList, "98123477");

    printList((*myList));
    
}