#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    char elem;
    struct node* link;
} *linkList;

void insert(linkList* head, char elem) {
    linkList new_node = malloc(sizeof(struct node));

    new_node->elem = elem;
    new_node->link = *head;
    *head = new_node;
}

void delete(linkList* head, char elem) {
    linkList locate = *head, prev = NULL;

    for (; locate != NULL && locate->elem != elem; locate = locate->link)
    {
        prev = locate;
    }

    prev->link = locate->link;

    free(locate);
}

void display(linkList head) {
    linkList trav = head;

    printf("\n");
    while (trav != NULL)
    {
        printf("%c ", trav->elem);

        trav = trav->link;
    }
    
}

#endif