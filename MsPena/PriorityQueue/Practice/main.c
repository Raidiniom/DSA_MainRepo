#include "prioqv1.h"

void main() {
    PriorityQueue myPQ;
    initPriorityQueue(&myPQ);

    // Populate the Priority Queue with sample tickets
    enqueue(&myPQ, createTicket("No Display", 2));
    enqueue(&myPQ, createTicket("Forgot the password", 1));
    enqueue(&myPQ, createTicket("Keyboard does not work", 8));
    enqueue(&myPQ, createTicket("Printer not printing", 5));
    enqueue(&myPQ, createTicket("Slow internet", 10));
    enqueue(&myPQ, createTicket("Mouse not detected", 4));
    enqueue(&myPQ, createTicket("Blue screen error", 3));
    enqueue(&myPQ, createTicket("Software update needed", 7));
    enqueue(&myPQ, createTicket("Cannot connect to WiFi", 6));
    enqueue(&myPQ, createTicket("Battery not charging", 9));

    displayPQ(myPQ, "Initial Queue");

    // Heapify from the root to enforce min-heap property
    // for (int i = (myPQ.lastNdx - 1) / 2; i >= 0; i--) {
    //     heapify(&myPQ, i);
    // }

    dequeue(&myPQ);

    displayPQ(myPQ, "Testing Dequeue");
}