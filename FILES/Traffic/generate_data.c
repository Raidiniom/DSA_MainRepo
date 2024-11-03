#include <stdio.h>

#include "traffic.h"

int main() {

    Traffic_Report this_report;

    init_Traffic_Report(&this_report);

     
     
    enqueue_data(&this_report, create_Traffic_Data(1, 30));
    enqueue_data(&this_report, create_Traffic_Data(7, 80));
    enqueue_data(&this_report, create_Traffic_Data(3, 46));
    enqueue_data(&this_report, create_Traffic_Data(4, 24));
    enqueue_data(&this_report, create_Traffic_Data(5, 64));
    enqueue_data(&this_report, create_Traffic_Data(1, 30));
    enqueue_data(&this_report, create_Traffic_Data(4, 24));
    enqueue_data(&this_report, create_Traffic_Data(6, 69));
    enqueue_data(&this_report, create_Traffic_Data(3, 46));
    enqueue_data(&this_report, create_Traffic_Data(5, 64));
    enqueue_data(&this_report, create_Traffic_Data(1, 30));
    enqueue_data(&this_report, create_Traffic_Data(4, 24));
    enqueue_data(&this_report, create_Traffic_Data(6, 69));
    enqueue_data(&this_report, create_Traffic_Data(3, 46));
    enqueue_data(&this_report, create_Traffic_Data(4, 24));
    enqueue_data(&this_report, create_Traffic_Data(8, 100));
    enqueue_data(&this_report, create_Traffic_Data(6, 69));


    display_report(this_report);

    // Only Testing the Dequeue Function
    // dequeue_data(&this_report);
    // dequeue_data(&this_report);

    // display_report(this_report);

    // Creating the dat file
    FILE *nano_filename;

    nano_filename = fopen("trafficreport.dat", "wb");

    if (nano_filename != NULL)
    {
        fwrite(this_report.list, sizeof(Traffic_Data), 17, nano_filename);
    }
    
    fclose(nano_filename);

    return 0;
}