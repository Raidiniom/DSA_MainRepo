#include "adt.h"

void main() {
    ADTlist list;
    initADTList(&list);

    insertData(&list, createPerson("Jane", "Doe", 22));
    insertData(&list, createPerson("John", "Doe", 23));

    displayADTList(list);
}