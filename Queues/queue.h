#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Movie Theater
typedef enum {
    G = 1, // All ages
    PG, // 8 and above
    PG_13, // 13 and above
    NC_17, // 18 and above
    R, // 30 and above
} Ratings;

typedef char String[20];

typedef struct {
    String name;
    int age;
    Ratings movie;
} Person;

typedef struct node
{
    Person movie_goers;
    struct node *next;
} Node, *NodePtr;

typedef struct {
    NodePtr front;
    NodePtr rear;
} Queue;

Person create_movie_goers(String name, int age, Ratings movie) {
    Person start_person;

    strcpy(start_person.name, name);
    start_person.age = age;
    start_person.movie = movie;

    return start_person;
}

void create_queue(Queue *queue) {
    queue->front =  NULL;
    queue->rear = NULL;
}

bool is_empty(Queue queue) {
    return queue.front == NULL;
}

Person peek(Queue queue) {
    return queue.front->movie_goers;
}

void enqueue(Queue *queue, Person in_line) {
    NodePtr new_node =(NodePtr) malloc(sizeof(Node));

    new_node->movie_goers = in_line;
    new_node->next = NULL;

    if (is_empty(*queue))
    {
        queue->front = new_node;
        queue->rear = new_node;
    }
    else
    {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
    
}

void dequeue(Queue *queue) {

    if (queue->front == queue->rear)
    {
        free(queue->front);

        return;
    }
    

    NodePtr delete_this = queue->front;

    queue->front = queue->front->next;

    free(delete_this);
}

bool check_ticket(Person person, Ratings movie) {
    switch (movie) {
        case G:
            return person.age >= 0;
        case PG:
            return person.age >= 8;
        case PG_13:
            return person.age >= 13;
        case NC_17:
            return person.age >= 18;
        case R:
            return person.age >= 30;
        default:
            return false;
    }
}

NodePtr allowed_entrance(Queue *queue, Ratings rating) {
    NodePtr allowed = NULL, trav =  queue->front;

    while (trav != NULL)
    {
        if (check_ticket(trav->movie_goers, rating))
        {
            NodePtr new_node =(NodePtr) malloc(sizeof(Node));

            new_node->movie_goers = trav->movie_goers;
            new_node->next = allowed;
            allowed = new_node;
        }
        

        trav = trav->next;
    }
    

    return allowed;
}

Queue allowed_entrance_v2(Queue *queue, Ratings rate) {
    Queue allowed;
    create_queue(&allowed);

    if (!is_empty(*queue))
    {

        NodePtr prev = NULL, curr = queue->front;


        while (curr != NULL)
        {
            if (check_ticket(curr->movie_goers, rate))
            {
                NodePtr trav = curr;
                
                if (prev == NULL)
                {
                    queue->front = curr->next;
                }
                else
                {
                    prev->next = curr->next;
                }
                
                curr = curr->next;

                trav->next = NULL;

                if (allowed.rear == NULL)
                {
                    allowed.front = allowed.rear = trav;
                }
                else
                {
                    allowed.rear->next = trav;
                    allowed.rear = trav;
                }
                
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }

        if (queue->front == NULL)
        {
            queue->rear = NULL;
        }
    }
    
    return allowed;
}

void movie_line(Queue queue, int cinema_room_no, String movie_title) {
    NodePtr temp = queue.front;

    printf("Cinema Room #%d === %s ===\n", cinema_room_no, movie_title);
    while (temp != NULL)
    {
        printf("%s, %d \n", temp->movie_goers.name, temp->movie_goers.age);
        temp = temp->next;
    }
    
}

#endif