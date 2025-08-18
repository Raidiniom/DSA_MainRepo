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

    if (new_node != NULL)
    {
        new_node->elem = elem;
        new_node->link = *head;
        *head = new_node;
    }
    
}

void delete(linkList* head, char elem) {
    if (*head != NULL)
    {
        linkList locate = *head, prev = NULL;

        for (; locate != NULL && locate->elem != elem; locate = locate->link)
        {
            prev = locate;
        }

        prev->link = locate->link;

        free(locate);
    }
    
}

void deleteV2(linkList* head, char elem) {
    if (*head != NULL)
    {
        linkList locate = *head, delete;

        for (; locate != NULL && locate->link->elem != elem; locate = locate->link){}
        delete = locate->link;
        locate->link = locate->link->link;

        free(delete);
    }
    
}

void display(linkList head) {
    linkList trav = head;

    while (trav != NULL)
    {
        printf("%c ", trav->elem);

        trav = trav->link;
    }
    
    printf("\n");
}

#endif