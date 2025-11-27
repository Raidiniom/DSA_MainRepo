#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

int main() {
    // Create a queue
    Queue movie_queue;
    create_queue(&movie_queue);

    // Create some people (movie goers)
    Person people[] = {
        create_movie_goers("Alice", 25, G),
        create_movie_goers("Bob", 15, R),
        create_movie_goers("Charlie", 60, R),
        create_movie_goers("Diana", 9, R),
        create_movie_goers("Ethan", 34, R),
        create_movie_goers("Fiona", 18, PG),
        create_movie_goers("George", 48, PG_13),
        create_movie_goers("Helen", 67, G),
        create_movie_goers("Ian", 5, NC_17),
        create_movie_goers("Jack", 27, NC_17),
        create_movie_goers("Kara", 13, PG),
        create_movie_goers("Liam", 21, R),
        create_movie_goers("Mona", 37, R),
        create_movie_goers("Nina", 12, NC_17),
        create_movie_goers("Oscar", 40, PG),
        create_movie_goers("Penny", 16, G),
        create_movie_goers("Quincy", 24, NC_17),
        create_movie_goers("Rachel", 29, PG),
        create_movie_goers("Steve", 11, G),
        create_movie_goers("Tina", 14, PG)
    };

    for (int i = 0; i < 20; i++)
    {
        enqueue(&movie_queue, people[i]);
    }
    
     // Display the initial movie line
    printf("Initial movie queue:\n");
    movie_line(movie_queue, 6, "The Revengers");
    
    return 0;
}
