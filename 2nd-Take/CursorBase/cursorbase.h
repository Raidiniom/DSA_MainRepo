#ifndef CURSORBASE_H
#define CURSORBASE_H

/**
 * @file    cursorbase.h
 * @brief   Cursor-based implementation of a singly linked list using a virtual heap.
 *
 * Detailed description:
 * This header file implements a linked list using a static array to simulate
 * dynamic memory allocation, also known as a "cursor-based" list.
 * Instead of using pointers, each node uses integer indices (`link`) to
 * connect to the next node in the list.
 *
 * The VirtualHeap structure maintains an array of nodes and an `available`
 * index that tracks free memory slots. Memory allocation and deallocation
 * are managed manually through `allocSpace` and `deallocSpace`, simulating
 * how dynamic allocation works but within a fixed-size array.
 *
 * Functions implemented:
 *  - initVirtualHeap : Initializes the virtual heap and sets up the free list.
 *  - allocSpace      : Allocates space for a new node.
 *  - deallocSpace    : Frees a node and returns it to the available list.
 *  - insertFront     : Inserts a new element at the head of the list.
 *  - insertLast      : Inserts a new element at the end of the list.
 *  - insertAt        : Inserts a new element at a specified position.
 *  - insertSorted    : Inserts a new element while keeping the list sorted.
 *  - deleteFront     : Removes the first element of the list.
 *  - deleteLast      : Removes the last element of the list.
 *  - deleteAt        : Removes an element at a specified position.
 *  - deleteElem      : Removes the first occurrence of a specific element.
 *  - displayLIST     : Prints the contents of the list with indices and links.
 *
 * This cursor-based approach is useful for understanding low-level
 * data structure memory management, especially in environments
 * where pointer usage is restricted.
 *
 * @author   Voltaire Ratilla
 * @date     Created: ??/??/2025
 * @date     Completed: 24/09/2025
*/

#include <stdio.h>

#define MAX_SIZE 20

typedef struct {
    char data;
    int link;
} Node;

typedef struct {
    Node nodes[MAX_SIZE];
    int available;
} VirtualHeap;

typedef int LIST;

void initVirtualHeap(VirtualHeap* VH, LIST* L) {
    *L = -1;
    VH->available = MAX_SIZE - 1;
    for (int i = -1; i < MAX_SIZE; i++)
    {
        VH->nodes[i + 1].link = i;
    }
    
}

int allocSpace(VirtualHeap* VH) {
    int address = VH->available;
    
    if (address != -1)
    {
        VH->available = VH->nodes[address].link;

    }
    
    return address;
}

void deallocSpace(VirtualHeap* VH, LIST* index) {
    if (*index != -1)
    {
        VH->nodes[*index].link = VH->available;
        VH->available = *index;
    }
    
}

void insertFront(LIST* L, VirtualHeap* VH, char elem) {
    int new_node = allocSpace(VH);

    if (new_node != 1)
    {
        VH->nodes[new_node].data = elem;
        VH->nodes[new_node].link = *L;
        *L = new_node;
    }
    
}

void insertLast(LIST* L, VirtualHeap* VH, char elem) {
    int new_node = allocSpace(VH);

    if (new_node != -1)
    {
        VH->nodes[new_node].data = elem;
        int trav = *L;

        for (; VH->nodes[trav].link != -1; trav = VH->nodes[trav].link){}

        VH->nodes[new_node].link = -1;
        VH->nodes[trav].link = new_node;
    }
    
}

void insertAt(LIST* L, VirtualHeap* VH, char elem, int position) {
    int new_node = allocSpace(VH);

    if (new_node != -1)
    {
        VH->nodes[new_node].data = elem;
        int trav = *L, index = position - 1;

        for (int i = 1; VH->nodes[trav].link != -1 && i < index; i++, trav = VH->nodes[trav].link){}

        VH->nodes[new_node].link = VH->nodes[trav].link;
        VH->nodes[trav].link = new_node;
        
    }
    
}

void insertSorted(LIST* L, VirtualHeap* VH, char elem) {
    int new_node = allocSpace(VH);
    
    if (new_node != -1)
    {
        VH->nodes[new_node].data = elem;
        
        if (elem < VH->nodes[*L].data)
        {
            VH->nodes[new_node].link = *L;
            *L = new_node;
        }
        else
        {
            int trav = *L;
        
            for (; VH->nodes[trav].link != -1 && elem > VH->nodes[VH->nodes[trav].link].data; trav = VH->nodes[trav].link){}

            VH->nodes[new_node].link = VH->nodes[trav].link;
            VH->nodes[trav].link = new_node;
        }
        
        
    }
    
}

void deleteFront(LIST* L, VirtualHeap* VH) {
    LIST head = *L;
    *L = VH->nodes[head].link;
    deallocSpace(VH, &head);
}

void deleteLast(LIST* L, VirtualHeap* VH) {
    LIST trav = *L;

    for (; VH->nodes[VH->nodes[trav].link].link != -1; trav = VH->nodes[trav].link){}

    deallocSpace(VH, &VH->nodes[trav].link);

    VH->nodes[trav].link = -1;
    
}

void deleteAt(LIST* L, VirtualHeap* VH, int position) {
    int index = position - 1;

    LIST trav = *L;

    for (int i = 1; VH->nodes[trav].link != -1 && i < index; i++, trav = VH->nodes[trav].link){}
    int hold = VH->nodes[VH->nodes[trav].link].link;
    deallocSpace(VH, &VH->nodes[trav].link);
    VH->nodes[trav].link = hold;
}

void deleteElem(LIST* L, VirtualHeap* VH, char elem) {
    LIST trav = *L;

    for (; VH->nodes[trav].link != -1 && VH->nodes[VH->nodes[trav].link].data != elem; trav = VH->nodes[trav].link){}
    int delete = VH->nodes[trav].link;
    VH->nodes[trav].link = VH->nodes[delete].link;
    deallocSpace(VH, &delete);
}

void displayLIST(LIST L, VirtualHeap VH) {
    int temp = L;
    printf("VH Address - data - link\n");
    for (; temp != -1; temp = VH.nodes[temp].link)
    {
        printf("%d - %c - %d\n", temp, VH.nodes[temp].data, VH.nodes[temp].link);
    }
    
}

#endif