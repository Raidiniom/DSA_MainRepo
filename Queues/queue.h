#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Movie Theater
typedef enum {
    New_Spawn,
    Everyone,
    Pre_Teens,
    Teens,
    Adult,
    Ancient
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

void debug_queue(Queue queue) {
    NodePtr temp = queue.front;

    while (temp != NULL)
    {
        printf("%s, %d \n", temp->movie_goers.name, temp->movie_goers.age);
        temp = temp->next;
    }
    
}

#endif