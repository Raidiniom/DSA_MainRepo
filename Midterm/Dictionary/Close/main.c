#include "cldih.h"

void main() {
    Dictionary cld;
    initDictionary(&cld);

    insertElem(&cld, 1);
    insertElem(&cld, 2);
    insertElem(&cld, 3);
    insertElem(&cld, 3);
    insertElem(&cld, 4);
    insertElem(&cld, 5);
    insertElem(&cld, 6);

    display(cld, "Initial Dictionary");

    deleteElem(&cld, 3);

    display(cld, "Delete 3");
}
