#include <stdio.h>

#include "queuearray.h"

void main() {
    Queue myQueue;
    initQueue(&myQueue);

    enqueue(&myQueue, createPerson("Ratilla", "Voltaire", 'L'));
    enqueue(&myQueue, createPerson("Ratilla", "Voltaire", 'L'));
    enqueue(&myQueue, createPerson("Ratilla", "Voltaire", 'L'));
    enqueue(&myQueue, createPerson("Ratilla", "Voltaire", 'L'));
    enqueue(&myQueue, createPerson("Ratilla", "Voltaire", 'L'));
    enqueue(&myQueue, createPerson("Ratilla", "Voltaire", 'L'));

    displayQueue(myQueue);
}