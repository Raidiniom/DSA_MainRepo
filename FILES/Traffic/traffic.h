#ifndef TRAFFIC_H
#define TRAFFIC_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef char String[20];

typedef enum {
    M = 1, D, ML, DL, MR, DR, PM, PD
} Type;

typedef struct {
    Type type;
    int sec;
} Traffic_Data;

typedef struct {
    Traffic_Data list[20];
    int count;
} Traffic_Report; // Binary Heap

void init_Traffic_Report(Traffic_Report *report) {
    report->count = 0;
}

Traffic_Data create_Traffic_Data(Type type, int sec) {
    Traffic_Data start;

    start.type = type;
    start.sec = sec;

    return start;
}

const char* convert_enum(Type type) {
    switch (type)
    {
        // Pedestrian Main
        case 7:
            return "Pedestrian_Main";
        break;

        // Pedestrian Diversion
        case 8:
            return "Pedestrian_Diversion";
        break;

        // Main Road
        case 1:
            return "Main_Road";
        break;

        // Diversion Road
        case 2:
            return "Diversion_Road";
        break;

        // Main Left
        case 3:
            return "Main_Left";
        break;

        // Diversion Left
        case 4:
            return "Diversion_Left";
        break;

        // Main Right
        case 5:
            return "Main_Right";
        break;

        // Diversion Right
        case 6:
            return "Diversion_Right";
        break;
    
        default:
            return "NaN";
        break;
    }
}

void enqueue_data(Traffic_Report *report, Traffic_Data data) {
    if (report->count >= 20)
    {
        return;
    }

    int index = report->count, parent;

    while (index > 0 && data.type < report->list[(index - 1) / 2].type)
    {
        parent = (index - 1) / 2;
        report->list[index] = report->list[parent];
        index = parent;
    }
    
    report->list[index] = data;
    report->count++;
    
}

Traffic_Data dequeue_data(Traffic_Report *report) {
    Traffic_Data deleted_data;

    if (report->count >= 20)
    {
        return create_Traffic_Data(0, 0);
    }
    



    return deleted_data;
}

void display_data(Traffic_Data data) {
    printf("%20s      %d", convert_enum(data.type), data.sec);
}

void display_report(Traffic_Report report) {
    printf("Report-List|_________________________________\n");
    for (int i = 0; i < report.count; i++)
    {
        display_data(report.list[i]);
        printf("\n");
    }
    
}

#endif