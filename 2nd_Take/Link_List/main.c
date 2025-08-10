#include <stdio.h>

#include "slinklist.h"

void main() {
    NodePtr mylist = create_list();

    NodePtr item1 = malloc(sizeof(Node));
    item1->item = create_item("Ear Plugs", 1);
    item1->next = NULL;

    NodePtr item2 = malloc(sizeof(Node));
    item2->item = create_item("Charger", 2);
    item2->next = NULL;

    NodePtr item3 = malloc(sizeof(Node));
    item3->item = create_item("Window Wiper", 3);
    item3->next = NULL;

    mylist = item1;
    item1->next = item2;
    item2->next = item3;

    display_list(mylist);
}