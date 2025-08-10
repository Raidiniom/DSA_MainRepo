#ifndef GRAPHAH_H
#define GRAPHAH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String[20];

typedef struct {
    String first_name;
    String last_name;
} Name;

typedef struct node {
    Name person;
    struct node *next;
} Node, *NodePtr;

typedef struct {
    NodePtr *adjList;
    int numVertices;
} Graph;

Graph create_graph(int max) {
    Graph graph;

    graph.numVertices = max;
    graph.adjList =(NodePtr *) malloc(max * sizeof(NodePtr));

    for (int i = 0; i < max; i++) {
        graph.adjList[i] = NULL;
    }

    return graph;
}

Name create_name(String first_name, String last_name) {
    Name start_name;

    strcpy(start_name.first_name, first_name);
    strcpy(start_name.last_name, last_name);

    return start_name;
}

unsigned int hash_function(Graph source, String name) {
    unsigned int hash = 5381;

    int c, x = 0;

    while ((c = name[x++]) != '\0')
    {
        hash = ((hash << 5) + hash) + c;
        x++;
    }
    

    return hash % source.numVertices;
}

void add_edge(Graph *graph, Name from_person, Name to_person) {
    NodePtr new_node =(NodePtr) malloc(sizeof(Node));

    int start = hash_function(*graph, from_person.last_name);
    int end = hash_function(*graph, to_person.last_name);

    new_node->person = to_person;
    new_node->next = graph->adjList[start];
    
    graph->adjList[start] = new_node;

    new_node =(NodePtr) malloc(sizeof(Node));

    new_node->person = from_person;
    new_node->next = graph->adjList[end];

    graph->adjList[end] = new_node;
}

void display_graph(Graph graph) {
    printf("Facebook Accounts ====================== \n");
    for (int i = 0; i < graph.numVertices; i++)
    {
        printf("%s : ", graph.adjList[i]->person.first_name);

        NodePtr temp = graph.adjList[i];

        while (temp)
        {
            printf("%s, %s ", temp->person.last_name, temp->person.first_name);
            temp = temp->next;
            
            if (temp != NULL)
            {
                printf("-> ");
            }
            
        }
        printf("\n");
    }
    
}

#endif