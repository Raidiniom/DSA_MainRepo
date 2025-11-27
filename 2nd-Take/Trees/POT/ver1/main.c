#include "pot.h"

void main() {
    List thisList;
    initList(&thisList);

    insertElem(&thisList, 5);
    insertElem(&thisList, 2);
    insertElem(&thisList, 1);
    insertElem(&thisList, 7);
    insertElem(&thisList, 9);

    printf("Initial List\n");
    displayList(thisList);

    deleteMin(&thisList, 2);

    printf("Delete '2' List\n");
    displayList(thisList);

    sortedList(&thisList);

    printf("Sorted List\n");
    displaySortedList(thisList);
}
