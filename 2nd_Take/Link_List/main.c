#include <stdio.h>

#include "slinklist.h"

void main() {
    NodePtr mylist = create_list();

    insert_front(&mylist, create_item("Phone", 1599.59));
    insert_front(&mylist, create_item("Cup", 199.50));
    insert_front(&mylist, create_item("Hampter", 99.00));

    display_list(mylist);
}