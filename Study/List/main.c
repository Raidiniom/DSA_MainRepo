#include "adt.h"

void main() {
    ADTlist list;
    initADTList(&list);

    insertData(&list, createPerson("Jane", "Doe", 22));
    insertData(&list, createPerson("John", "Doe", 23));
    insertData(&list, createPerson("Janell", "Doe", 24));
    insertData(&list, createPerson("Joe", "Doe", 25));
    insertData(&list, createPerson("Raine", "Doe", 26));
    insertData(&list, createPerson("Voltaire", "Doe", 27));
    insertData(&list, createPerson("Jack", "Doe", 28));
    insertData(&list, createPerson("Jake", "Doe", 29));
    insertData(&list, createPerson("Joan", "Doe", 30));

    displayADTList(list, "Initial List");

    deleteData(&list, "Voltaire", "Doe");

    displayADTList(list, "Delete One");
}