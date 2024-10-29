#ifndef TRAFFIC_H
#define TRAFFIC_H

#include <stdio.h>
#include <stdbool.h>

typedef enum {
    Main, Diversion, MainR, MainL, DivsionR, DivsionL, PedesMain, PedesDiv
} desc;

typedef struct {
    desc status;
    int secs;
} Traffic_Data;

typedef struct {
    Traffic_Data data[10];
    int count;
    int max;
} Queue;

void init_Queue(Queue *que, int max) {
    que->max = max;
    que->count = 0;
}

Traffic_Data create_data(desc stat, int secs) {
    Traffic_Data start_data;

    start_data.status = stat;
    start_data.secs = secs;

    return start_data;
}

bool enqueue(Queue *que, Traffic_Data t_data) {
    if (que->count < que->max)
    {
        que->data[que->count] = t_data;
        que->count++;

        return true;
    }
    

    return false;
}

Traffic_Data dequeue(Queue *que) {
    Traffic_Data dequeued_data = que->data[0];

    for (int i = 0; i < que->count; i++)
    {
        que->data[i] = que->data[i + 1];
    }
    
    que->count--;

    return dequeued_data;
}

#endif