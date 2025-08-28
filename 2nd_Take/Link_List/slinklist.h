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

        int count_elements = 0;
        
        if (new_node != NULL)
        {
            new_node->item = item;

            NodePtr trav = *list;

            for (int i = 1; i < pos - 1 && trav != NULL; i++, trav = trav->next)
            {
                count_elements++;
            }

            if (count_elements > pos)
            {
                new_node->next = trav->next;
                trav->next = new_node;
            }
            else
            {
                printf("Invalid Postion\n");
            }
            
            printf("[DEBUG] count_element: %d\n", count_elements);
            
        }
    }  
}

void insert_rear(NodePtr* list, Item item) {
    NodePtr new_node = malloc(sizeof(Node));

    if (new_node != NULL)
    {
        new_node->item = item;
        new_node->next = NULL;

        if (is_empty(list))
        {
            new_node->next = *list;
            *list = new_node;
        }
        else
        {
            NodePtr trav = *list, prev =  NULL;

            for (; trav->next != NULL; trav = trav->next){}
            
            trav->next = new_node;
        }
    }
        
}

void delete_front(NodePtr* list) {
    if (!is_empty(list))
    {
        NodePtr delete = *list;
        *list = (*list)->next;

        free(delete);
    }
    
}

void delete_at(NodePtr* list, int pos) {
    if (!is_empty(list))
    {
        if (pos == 1)
        {
            delete_front(list);
        }
        else
        {
            NodePtr trav = *list, delete = NULL;

            for (int i = 1; i < pos - 1 && trav != NULL; i++){trav = trav->next;}

            delete = trav->next;
            trav->next = delete->next;

            free(delete);
        }
        
    }
    
}

void delete_item(NodePtr* list, String item_name) {
    NodePtr trav = *list, prev = NULL;

    while (trav != NULL && strcmp(trav->item.name, item_name) != 0)
    {
        prev = trav;
        trav = trav->next;
    }

    if (prev == NULL)
    {
        *list = trav->next;
    }
    else
    {
        prev->next = trav->next;
    }
    
    free(trav);
}

void delete_all(NodePtr* list, String item_name) {
    if (!is_empty(list))
    {
        NodePtr trav = *list, prev = NULL;

        while (trav != NULL)
        {
            if (strcmp(trav->item.name, item_name) == 0)
            {
                NodePtr delete = trav;

                if (prev == NULL)
                {
                    *list = trav->next;
                }
                else
                {
                    prev->next = trav->next;
                }
                
                trav = trav->next;
                free(delete);
            }
            else
            {
                prev = trav;
                trav = trav->next;
            }
            
        }
        
    }
    
}

void delete_rear(NodePtr* list) {
    NodePtr trav = *list;

    for (; trav != NULL; trav = trav->next){}

    printf("%s\n", trav ? trav->item.name : "NULL");
    
}
// End Code Block!

void display_list(NodePtr list) {
    if (!is_empty(list))
    {
        NodePtr trav = list;

        printf("Items available:\n");
        for (; trav != NULL; trav = trav->next)
        {
            printf("| %s - %.2f\n", trav->item.name, trav->item.price);
        }
    }
    else
    {
        printf("Please list the items from the inventory. \n");
    }
    
}

#endif