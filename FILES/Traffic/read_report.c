#include <stdio.h>

#include "traffic.h"

int main() {

    FILE *touch_filename;

    Traffic_Data data;

    touch_filename = fopen("trafficreport.dat", "rb");

    if (touch_filename != NULL)
    {
        printf("Report-List|_________________________________\n");
        while (fread(&data, sizeof(Traffic_Data), 1, touch_filename))
        {
            display_data(data);
            printf("\n");
        }
        
    }

    fclose(touch_filename);
    
    printf("\n\nTotal Time: %d\n\n", total_time("trafficreport.dat"));

    return 0;
}