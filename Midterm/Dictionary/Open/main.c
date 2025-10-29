#include "opdih.h"

void main() {
    Dictionary myDih;
    initDictionary(myDih);

    insertElem(myDih, 1);
    insertElem(myDih, 3);
    insertElem(myDih, 5);
    insertElem(myDih, 42);
    insertElem(myDih, 16);
    insertElem(myDih, 7);
    insertElem(myDih, 90);
    insertElem(myDih, 22);
    insertElem(myDih, 11);

    display(myDih, "Initial Dictionary");

    deleteElem(myDih, 5);

    display(myDih, "Delete 5");
}