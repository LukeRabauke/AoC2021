#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[])
{
    char const* const fileName = "input.txt";
    FILE* file = fopen(fileName, "r");
    char line[256], *ptr;
    int crab_pos[1008]={0}, i=0, k=0, sum_fuel=0, max_coord=0, lowest_fuel=0, first_run=0, number_inputs=0;
    char delim[]={","};

    while (fgets(line, sizeof(line), file)) {
        //printf("%s", line);
        ptr = strtok(line, delim);
       
        while (ptr != NULL)
        {
            //printf("'%s'\n", ptr);
            crab_pos[i] = atoi(ptr);
            ptr = strtok(NULL, delim);
            number_inputs++;
            i++;
        }
    }
  
    fclose(file);
    printf("Es gibt insgesamt: %d Inputs \n", i);
    i=0;
    for ( i = 0; i < number_inputs; i++)
    {
        if (crab_pos[i]>max_coord)
        {
            max_coord=crab_pos[i]+1;
        }
        
    }
    
   

    for ( i = 0; i < max_coord; i++)
    {
        sum_fuel=0;
        
        for ( k = 0; k < number_inputs; k++)
        {
            sum_fuel += abs(crab_pos[k]-i);
        }
        
        if (first_run==0)
        {
            first_run=1;
            lowest_fuel=sum_fuel;

        }
        else if (first_run == 1 && sum_fuel < lowest_fuel)
        {
            lowest_fuel=sum_fuel;
        }
        
        
    }
    
    printf("Lowest Fuel Consumption: %d \n", lowest_fuel);

    return 0;
}

