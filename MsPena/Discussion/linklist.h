#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    char elem;
    struct node* link;
} *linkList;

/*
for debugging purpose, use this line of code

printf("%c", pointer ? pointer->data : '-');
*/

void insertFront(linkList* head, char elem) {
    linkList new_node = malloc(sizeof(struct node));

    if (new_node != NULL)
    {
        new_node->elem = elem;
        new_node->link = *head;
        *head = new_node;
    }
    
}

void insertLast(linkList* head, char elem) {
    linkList new_node = malloc(sizeof(struct node));

    if (new_node != NULL)
    {
        new_node->elem = elem;
        new_node->link = NULL;

        linkList trav = *head;

        for (; trav->link != NULL; trav = trav->link){}

        trav->link = new_node;
        
    }
    
}

void insertLastUnique(linkList* head, char elem) {
    linkList locate = *head;

    for (; locate != NULL && locate->elem != elem; locate = locate->link){}

    if (locate == NULL)
    {
        linkList new_node = malloc(sizeof(struct node));

            if (new_node != NULL)
            {
                new_node->elem = elem;
                new_node->link = NULL;

                linkList trav = *head;

                for (; trav->link != NULL; trav = trav->link){}

                trav->link = new_node;
            }
        
    }
    
    
}

void insertAt(linkList* head, char elem, int position) {
    linkList new_node = malloc(sizeof(struct node));
    int index = position - 1;

    if (new_node != NULL)
    {
        new_node->elem = elem;

        linkList trav = *head;

        for (int i = 1; trav != NULL && i < index; i++, trav = trav->link){}

        new_node->link = trav->link;
        trav->link = new_node;
    }
    
}

void insertSorted(linkList *head, char elem) {
    linkList new_node = malloc(sizeof(struct node));
    
    if (new_node != NULL)
    {
        new_node->elem = elem;

        if (elem < (*head)->elem)
        {
            insertFront(head, elem);
        }
        else
        {
            linkList trav = *head;
            for (; trav->link != NULL && trav->link->elem < elem; trav = trav->link){}
            
            new_node->link = trav->link;
            trav->link = new_node;
        }
        
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

void deleteAll(linkList* head, char elem) {
    if (*head != NULL)
    {
        linkList locate = *head, prev = NULL;

        while (locate != NULL)
        {
            if (locate->elem == elem)
            {
                linkList delete = locate;

                if (prev == NULL)
                {
                    *head = locate->link;
                }
                else
                {
                    prev->link = locate->link;
                }
                
                locate = locate->link;
                free(delete);
                
            }
            else
            {
                prev = locate;
                locate = locate->link;
            }
        }
    }
    
}

void display(linkList head) {
    linkList trav = head;

    for (; trav != NULL; trav = trav->link)
    {
        printf("%c ", trav->elem);    
    }
    printf("\n");
}

#endif