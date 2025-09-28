#include "opendih.h"

void main() {
    Dictionary dih;
    initDictionary(dih);

    insert(dih, 1);
    insert(dih, 11);
    insert(dih, 21);
    insert(dih, 31);

    insert(dih, 0);
    insert(dih, 10);
    insert(dih, 20);
    insert(dih, 30);

    delete(dih, 11);

    display(dih);
}