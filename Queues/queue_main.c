#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

int main() {
    // Create a queue
    Queue movie_queue;
    create_queue(&movie_queue);

    // Create some people (movie goers)
    Person person1 = create_movie_goers("Alice", 25, Adult);
    Person person2 = create_movie_goers("Bob", 17, Teens);
    Person person3 = create_movie_goers("Charlie", 35, Adult);

    // Enqueue people to the queue
    enqueue(&movie_queue, person1);
    enqueue(&movie_queue, person2);
    enqueue(&movie_queue, person3);

    // Debug the queue and print the people in it
    printf("Queue:\n");
    debug_queue(movie_queue);

    return 0;
}
