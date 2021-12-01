#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    char const* const fileName = "input.txt";
    FILE* file = fopen(fileName, "r");
    char line[256];
    int deeper = 0;
    double sonar_sum_1 = 0;
    double sonar_sum_2 = 0;
    long line_counter = 0;
    char *ptr;
    double ret;
    double sonar_arr [2000];

    while (fgets(line, sizeof(line), file)) {
        //printf("%s", line);
        if (line[0] == '\n') break;
        else 
        {
            sonar_arr[line_counter] = strtod(line, &ptr);
            line_counter++;
        }
    }
    
    long i = 0;
    int j;
    

    for (long k=0;k<2000;k++)
    {
        //if (k+i > 1999 || k+j >1999) break;
        
        for (i=0;i<3;i++)
        {
            if (k+i>line_counter)
            {
                break;
            }
            else sonar_sum_1=sonar_sum_1 + sonar_arr[k+i];
        
        }
        for (j=1;j<4;j++)
        {
            if (k+j>line_counter)
            {
                break;
            }
            else sonar_sum_2=sonar_sum_2 + sonar_arr[k+j];
        }
        if (sonar_sum_2 > sonar_sum_1)
        {
            deeper++;
        }
        sonar_sum_1 = 0;
        sonar_sum_2 = 0;
    }
    

    fclose(file);
    printf("Anzahl der increasten Sonars ist: %i \n", deeper);
    return 0;
}

