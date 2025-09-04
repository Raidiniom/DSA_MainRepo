#include <stdio.h>

#include "StackLinkList.h"

void main() {
    Stack myStack;

    initList(&myStack);

    push(&myStack, createStud(createName("Voltaire", "Ratilla", 'L'), 111, "BSIT"));
    push(&myStack, createStud(createName("Charles", "Boqecosa", 'X'), 222, "BSIT"));
    push(&myStack, createStud(createName("Clarence", "Diangco", 'V'), 333, "BSIT"));

    displayStack(myStack);

    printf("Pop 1\n");
    pop(&myStack);

    displayStack(myStack);

    top(myStack);

    // printf("Pop Return 1\n");
    // displayStud(popReturn(&myStack));

    // printf("Final Stack\n");
    // displayStack(myStack);
}