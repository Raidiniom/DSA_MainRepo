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

void allowed_entrance(Queue *queue) {
    if (!is_empty(*queue))
    {
        while (queue->front != queue->rear || queue->front != NULL )
        {
            /* code */
        }
        
    }
    
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