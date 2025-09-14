#include <stdio.h>
#include <assert.h>

#include "queuecircular.h"

void main() {
    Queue myQueue;
    initQueue(&myQueue);

    enqueue(&myQueue, createPerson("Ratilla", "Voltaire", 'L'));
    enqueue(&myQueue, createPerson("Diangco", "Clarence", 'A'));
    enqueue(&myQueue, createPerson("Doe", "Jane", 'C'));
    enqueue(&myQueue, createPerson("Doe", "John", 'B'));

    displayQueue(&myQueue);

    // dequeue(&myQueue);

    // debugQueue(myQueue, "Original Queue");
}