#ifndef CURSORBASE_H
#define CURSORBASE_H

#include <stdio.h>

#define MAX_SIZE 10

typedef struct {
    char data;
    int link;
} Node;

typedef struct {
    Node nodes[MAX_SIZE];
    int available;
} VirtualHeap;

typedef int LIST;

void initVirtualHeap(VirtualHeap* VH) {
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

        return address;
    }
    
}

void deallocSpace(VirtualHeap* VH, int index) {
    if (index != -1)
    {
        VH->nodes[index].link = VH->available;
        VH->available = index;
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

        printf("\n[DEBUG] trav %d\n", trav);
        VH->nodes[new_node].link = -1;
        VH->nodes[trav].link = new_node;
    }
    
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