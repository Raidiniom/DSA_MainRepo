#include <stdio.h>

#include "stqusort.h"

void main() {
    Stack mystack;
    initStack(&mystack);

    Queue myqueue;
    initQueue(&myqueue);

    push(&mystack, createProduct(12, "Phone", 10));
    push(&mystack, createProduct(6, "Mouse", 20));
    push(&mystack, createProduct(2, "Keyboard", 5));
    push(&mystack, createProduct(11, "Monitor", 9));

    
    debugStack(mystack);
    printf("\n[DEBUG] Top of the stack - ");
    displayProduct(top(mystack));
    
    sortStackToQueue(&mystack, &myqueue);

    debugQueue(myqueue);
}
