#include "opendih.h"

void main() {
    Dictionary dih;
    initDictionary(dih);

    insert(dih, 0);
    insert(dih, 1);
    insert(dih, 2);
    insert(dih, 3);
    insert(dih, 4);
    insert(dih, 5);
    insert(dih, 6);
    insert(dih, 7);
    insert(dih, 8);
    insert(dih, 9);

    insert(dih, 10);
    insert(dih, 11);
    insert(dih, 12);
    insert(dih, 13);
    insert(dih, 14);
    insert(dih, 15);
    insert(dih, 16);
    insert(dih, 17);
    insert(dih, 18);
    insert(dih, 19);

    insert(dih, 20);
    insert(dih, 21);
    insert(dih, 22);
    insert(dih, 23);
    insert(dih, 24);
    insert(dih, 25);
    insert(dih, 26);
    insert(dih, 27);
    insert(dih, 28);
    insert(dih, 29);

    insert(dih, 30);
    insert(dih, 31);
    insert(dih, 32);
    insert(dih, 33);
    insert(dih, 34);
    insert(dih, 35);
    insert(dih, 36);
    insert(dih, 37);
    insert(dih, 38);
    insert(dih, 39);

    delete(dih, 11);
    delete(dih, 20);

    display(dih);

    makeNull(dih);

    printf("\nMake Null part\n");
    display(dih);
}
