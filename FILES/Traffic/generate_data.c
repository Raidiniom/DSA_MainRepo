#include <stdio.h>

#include "traffic.h"

int main() {

    Traffic_Report this_report;

    init_Traffic_Report(&this_report);

     
     
    enqueue_data(&this_report, create_Traffic_Data(1, 1)); // 1
    enqueue_data(&this_report, create_Traffic_Data(7, 80)); // 2
    enqueue_data(&this_report, create_Traffic_Data(3, 1)); // 3
    enqueue_data(&this_report, create_Traffic_Data(4, 1)); // 4
    enqueue_data(&this_report, create_Traffic_Data(5, 1)); // 5
    enqueue_data(&this_report, create_Traffic_Data(1, 1)); // 6
    enqueue_data(&this_report, create_Traffic_Data(4, 1)); // 7
    enqueue_data(&this_report, create_Traffic_Data(6, 1)); // 8
    enqueue_data(&this_report, create_Traffic_Data(3, 1)); // 9
    enqueue_data(&this_report, create_Traffic_Data(5, 1)); // 10
    enqueue_data(&this_report, create_Traffic_Data(1, 1)); // 11
    enqueue_data(&this_report, create_Traffic_Data(4, 1)); // 12
    enqueue_data(&this_report, create_Traffic_Data(6, 1)); // 13
    enqueue_data(&this_report, create_Traffic_Data(3, 1)); // 14
    enqueue_data(&this_report, create_Traffic_Data(4, 1)); // 15
    enqueue_data(&this_report, create_Traffic_Data(8, 100)); // 16
    enqueue_data(&this_report, create_Traffic_Data(6, 1)); // 17

    printf("\nInitail List\n");
    display_report(this_report);

    // Only Testing the Dequeue Function
    // for (int i = 0; i < 17; i++)
    // {
    //     dequeue_data(&this_report);

    //     printf("\nDeleted %d From list\n", i + 1);
    //     display_report(this_report);
    // }
    

    // Creating the dat file
    FILE *nano_filename;

    nano_filename = fopen("trafficreport.dat", "wb");

    if (nano_filename != NULL)
    {
        fwrite(&this_report.count, sizeof(int), 1, nano_filename);
        fwrite(this_report.list, sizeof(Traffic_Data), this_report.count, nano_filename);
    }
    
    fclose(nano_filename);

    return 0;
}