#include <stdio.h>

#include "slinklist.h"

void main() {
    NodePtr mylist = create_list();

    insert_front(&mylist, create_item("Phone", 1599.59));
    insert_front(&mylist, create_item("Cup", 199.50));
    insert_front(&mylist, create_item("Ballpen", 1299.00));
    insert_front(&mylist, create_item("Keyboard", 259.00));
    insert_front(&mylist, create_item("Monitor", 59199.00));
    // insert_at(&mylist, create_item("Pad Paper", 45.00), 4);
    insert_rear(&mylist, create_item("Correction Tape", 25.59));
    insert_front(&mylist, create_item("Keyboard", 259.00));
    // insert_at(&mylist, create_item("Keyboard", 259.00), 5);
    // insert_at(&mylist, create_item("Keyboard", 259.00), 10);
    
    display_list(mylist);
    
    insert_at(&mylist, create_item("Charles", 500.00), 11);
    // printf("\nStart deleting\n");
    // printf("Delete Front\n");
    // delete_front(&mylist);
    // printf("Delete At\n");
    // delete_at(&mylist, 1);
    // printf("Delete Item\n");
    // delete_item(&mylist, "Monitor");
    // printf("Delete Rear\n");
    // delete_rear(&mylist);
    // printf("Delete All\n");
    // delete_all(&mylist, "Keyboard");
    // display_list(mylist);
}