#include <stdio.h>

#include "stackarray.h"
// #include "stacklink.h"

void main() {
    Stack myStack;
    initStack(&myStack);

    push(&myStack, createPerson("Voltaire", "Ratilla", 'L'));
    push(&myStack, createPerson("Charles", "Boqeucosa", 'C'));
    push(&myStack, createPerson("Clarence", "Diangco", 'X'));

    
    displayStack(&myStack);
    
    // top(myStack);
    // pop(&myStack);

    // printf("makeNull\n");
    // makeNull(&myStack);
    
    // displayStack(myStack);
}   