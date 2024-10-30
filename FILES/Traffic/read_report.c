#include <stdio.h>

#include "traffic.h"

int main() {

    FILE *touch_filename;

    Traffic_Data data;

    touch_filename = fopen("trafficreport.txt", "rb");

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
    

    return 0;
}