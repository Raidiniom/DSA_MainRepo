#include "closedih.h"

void main() {
    Dictionary dih;
    initDictionary(dih);

    // Test 1: Insert 8 entries for 80% packing density
    for (int i = 0; i < 8; i++) {
        char fname[24];
        sprintf(fname, "User%d", i);
        char lname[16];
        sprintf(lname, "Last%d", i);
        Person p = createPerson(fname, lname, 'A' + i);
        insert(dih, p);
    }
    display(dih, "Test 1: 80%% Packing Density");

    // Test 2: Search for an existing entry
    int idx = search(dih, "User4", "Last4");
    printf("Test 2: Search User4 Last4: Index %d\n", idx);

    // Test 3: Search for a non-existing entry
    idx = search(dih, "User99", "Last99");
    printf("Test 3: Search User99 Last99: Index %d\n", idx);

    // Test 4: Delete an existing entry
    bool deleted = delete(dih, "User4", "Last4");
    printf("Test 4: Delete User4 Last4: %s\n", deleted ? "Success" : "Fail");
    display(dih, "After Deleting User4 Last4");

    // Test 5: Delete a non-existing entry
    deleted = delete(dih, "User99", "Last99");
    printf("Test 5: Delete User99 Last99: %s\n", deleted ? "Success" : "Fail");

    // Test 6: Insert into a deleted slot
    Person p = createPerson("NewGuy", "NewLast", 'Z');
    bool inserted = insert(dih, p);
    printf("Test 6: Insert NewGuy NewLast: %s\n", inserted ? "Success" : "Fail");
    display(dih, "After Inserting NewGuy");

    // Test 7: Fill dictionary to capacity
    for (int i = 8; i < MAXSIZE; i++) {
        char fname[24];
        sprintf(fname, "User%d", i);
        char lname[16];
        sprintf(lname, "Last%d", i);
        Person p = createPerson(fname, lname, 'A' + i);
        insert(dih, p);
    }
    display(dih, "Test 7: Dictionary Full");

    // Test 8: Insert when full
    Person extra = createPerson("Extra", "Person", 'X');
    inserted = insert(dih, extra);
    printf("Test 8: Insert when full: %s\n", inserted ? "Success" : "Fail");
}