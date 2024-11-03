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
    Traffic_Data end_data;

    if (report->count <= 0)
    {
        return create_Traffic_Data(0, 0);
    }
    
    end_data = report->list[report->count - 1];

    (report->count)--;

    int index = 0, less;

    while (index < report->count)
    {
        int left = (2 * index) + 1;

        if (left >= report->count) break;

        if (left + 1 < report->count && report->list[left + 1].type < report->list[left].type)
        {
            less = left + 1;
        }
        else
        {
            less = left;
        }


        if (end_data.type <= report->list[less].type) break;
        
        report->list[index] = report->list[less];
        
        index = less;
    }

    report->list[index] = end_data;

    return end_data;
}

int total_time(String filename) {
    FILE *this_file = fopen(filename, "rb");

    int sum_time = 0;

    if (this_file == NULL)
    {
        return sum_time;
    }

    Traffic_Report temp_report;
    init_Traffic_Report(&temp_report);

    fread(&temp_report.count, sizeof(int), 1, this_file);

    for (int i = 0; i < temp_report.count; i++)
    {
        Traffic_Data data_format;

        if (fread(&data_format, sizeof(Traffic_Data), 1, this_file) == 1)
        {
            temp_report.list[i] = data_format;
        }
        else
        {
            fclose(this_file);

            return sum_time;
        }
    }

    fclose(this_file);

    for (int j = 0; j < temp_report.count && temp_report.list[j].type < PM; j++)
    {
        sum_time += temp_report.list[j].sec;
        dequeue_data(&temp_report);
    }
    
    return sum_time;
}

void display_data(Traffic_Data data) {
    printf("  %30s    -    %d", convert_enum(data.type), data.sec);
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