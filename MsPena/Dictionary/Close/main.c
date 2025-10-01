#include "closedih.h"

void main() {
    Dictionary dih;
    initDictionary(dih);

    // Basic insertions
    Person p1 = createPerson("John", "Doe", 'A');
    Person p2 = createPerson("Jane", "Smith", 'B');
    Person p3 = createPerson("Alice", "Brown", 'C');
    insert(dih, p1);
    insert(dih, p2);
    insert(dih, p3);
    display(dih, "Initial Dictionary");

    // Edge Case 1: Insert until full
    for (int i = 4; i <= MAXSIZE; i++) {
        char fname[24];
        sprintf(fname, "User%d", i);
        char lname[16];
        sprintf(lname, "Last%d", i);
        Person p = createPerson(fname, lname, 'X');
        bool success = insert(dih, p);
        if (!success) {
            printf("Insert failed at %d (Dictionary full)\n", i);
        }
    }
    display(dih, "After Filling Dictionary");

    // Edge Case 2: Insert when full
    Person extra = createPerson("Extra", "Person", 'Z');
    bool success = insert(dih, extra);
    printf("Insert when full: %s\n", success ? "Success" : "Failed");

    // Edge Case 3: Insert duplicate (same hash, same data)
    Person dup = createPerson("John", "Doe", 'A');
    success = insert(dih, dup);
    printf("Insert duplicate: %s\n", success ? "Success" : "Failed");

    // Edge Case 4: Insert with collision (different data, same hash)
    // Find a collision manually or by brute force
    Person collision;
    int target_hash = nameHash("John", "Doe", 'A');
    for (char c = 'A'; c <= 'Z'; c++) {
        collision = createPerson("John", "Doe", c);
        if (nameHash(collision.FName, collision.LName, collision.MI) == target_hash && c != 'A') {
            break;
        }
    }
    success = insert(dih, collision);
    printf("Insert collision: %s\n", success ? "Success" : "Failed");

    display(dih, "After Edge Cases");
}