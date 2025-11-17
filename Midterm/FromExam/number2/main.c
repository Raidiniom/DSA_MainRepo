#include <stdio.h>
#include "header.h"

static void printResults(char** results) {
    if (!results) {
        printf("  (no cached results)\n");
        return;
    }
    for (int i = 0; i < RESULT; i++) {
        printf("  %s\n", results[i]);
    }
}

int main(void) {
    HASHTABLE table;
    initialize(&table);

    // Insert some queries (simulated search)
    insert(&table, "openai");
    insert(&table, "voltaire");
    insert(&table, "c programming");

    // Lookup and display cached results
    printf("Lookup: openai\n");
    printResults(lookup(&table, "openai"));

    printf("\nLookup: c programming\n");
    printResults(lookup(&table, "c programming"));

    // Update an existing key (insert will refresh results)
    printf("\nUpdating 'openai' (refresh results)...\n");
    insert(&table, "openai");
    printResults(lookup(&table, "openai"));

    // Remove a key and show effect
    printf("\nRemoving 'voltaire'...\n");
    removeKey(&table, "voltaire");
    printf("Lookup: voltaire\n");
    printResults(lookup(&table, "voltaire"));

    // Debug display of buckets
    printf("\nDebug display of non-empty buckets:\n");
    debugDisplay(&table);

    // Cleanup
    freeTable(&table);
    return 0;
}