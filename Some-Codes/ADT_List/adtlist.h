#ifndef ADTLIST_H
#define ADTLIST_H

#define MAX 15

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char String[50];

typedef struct {
    String name;
    int age;
} Person;

typedef struct {
    Person person[MAX];
    int count;
} List;

Person create_person(String name, int age) {
    Person init_person;

    strcpy(init_person.name, name);
    init_person.age = age;

    return init_person;
}

void init_list(List* list) {
    list->count = 0;
}

bool is_empty(List list) {
    return list.count == 0;
}

void insert_person(List* list, Person person) {
    list->person[list->count++] = person;
}

void remove_person(List* list, String name) {
    if (!is_empty(*list))
    {
        for (int i = 0; i < list->count; i++)
        {
            if (strcmp(list->person[i].name, name) == 0)
            {
                for (int vi = i; vi != list->count - 1; vi++)
                {
                    list->person[vi] = list->person[vi + 1];
                }
                
                list->count--;
                break;
            }
            
        }
        
    }
    
}

void sort_by_age(List* list) {
    // 
}

void display_list(List list) {
    printf("\nPerson List:\n");
    for (int i = 0; i < list.count; i++)
    {
        printf("%s - %d\n", list.person[i].name, list.person[i].age);
    }
    printf("Person Count: %d\n", list.count);
}

#endif