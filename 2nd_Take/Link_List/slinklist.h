#ifndef SLINKLIST_H
#define SLINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char String[50];

typedef struct {
    String name;
    float price;
} Item;

// Node is just for getting the proper size of the node
typedef struct node {
    Item item;
    struct node* next;
} Node, *NodePtr;

Item create_item(String name, float price) {
    Item item_initializer;

    strcpy(item_initializer.name, name);
    item_initializer.price = price;

    return item_initializer;
}

NodePtr* create_list() {
    return NULL;
}

/*
Create the following:

is_empty

- Insert
insert_front
insert_at
insert_rear

- Delete
delete_front
delete_at
delete_item
delete_rear

- Search
search_alloccurance
search_firstoccurance

- Sort
sort_list

- Reverse
reverse_list

*/

// Start Here!
bool is_empty(NodePtr list) {
    return list == NULL;
}

void insert_front(NodePtr* list, Item item) {
    NodePtr new_node = malloc(sizeof(Node));

    new_node->item = item;
    new_node->next = *list;
    *list = new_node;
}

void insert_at(NodePtr* list, Item item, int pos) {
    if (!is_empty(list))
    {
        NodePtr new_node = malloc(sizeof(Node));

        new_node->item = item;
        
        
    }
    
}
// End Code Block!

void display_list(NodePtr list) {
    NodePtr trav = list;

    while (trav != NULL)
    {
        printf("Item Name: %s - %.2f\n", trav->item.name, trav->item.price);

        trav = trav->next;
    }
    
}

#endif