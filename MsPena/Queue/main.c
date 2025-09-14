#include <stdio.h>

#include "queuelink.h"

void main() {
    Queue myQueue;
    initQueue(&myQueue);

    enqueue(&myQueue, createPerson("Ratilla", "Voltaire", 'L'));
    enqueue(&myQueue, createPerson("Diangco", "Clarence", 'A'));
    enqueue(&myQueue, createPerson("Doe", "Jane", 'C'));
    enqueue(&myQueue, createPerson("Doe", "John", 'B'));

    displayQueue(&myQueue);
}