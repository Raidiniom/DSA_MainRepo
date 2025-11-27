#include "closedhash.h"

int main() {
    Dictionary dih;
    initDictionary(dih);

    printf("=== Test 1: Insert A, B, C, D, E, F, G, H ===\n");
    insert(dih, 'A');
    insert(dih, 'B');
    insert(dih, 'C');
    insert(dih, 'D');
    insert(dih, 'E');
    insert(dih, 'F');
    insert(dih, 'G');
    insert(dih, 'H');
    display(dih);

    printf("\n=== Test 2: Delete A, then insert I ===\n");
    delete(dih, 'A');
    insert(dih, 'I');
    display(dih);

    printf("\n=== Test 3: Insert colliding letters (K, U, E) ===\n");
    // 'K' and 'U' both hash to the same index as 'A' in a table of size 10
    insert(dih, 'K');
    insert(dih, 'U');
    insert(dih, 'E'); // E may already be present, test duplicate insert
    display(dih);

    printf("\n=== Test 4: Delete non-existent letter (Z) ===\n");
    delete(dih, 'Z');
    display(dih);

    printf("\n=== Test 5: Fill table and test wrap-around ===\n");
    insert(dih, 'J');
    insert(dih, 'L');
    insert(dih, 'M');
    insert(dih, 'N');
    insert(dih, 'O');
    insert(dih, 'P');
    display(dih);

    printf("\n=== Test 6: Insert into full table (should not insert) ===\n");
    insert(dih, 'Q');
    display(dih);

    printf("\n=== Test 7: Delete all and check status ===\n");
    for (char ch = 'A'; ch <= 'P'; ch++) {
        delete(dih, ch);
    }
    display(dih);

    return 0;
}