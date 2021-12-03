#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char const* const fileName = "input.txt";
    FILE* file = fopen(fileName, "r");
    char line[256];
    int lines=1000;
    int rows=12;
    int debug_arr[lines][rows];
    int line_counter=0;
    int i =0;
     while (fgets(line, sizeof(line), file)) {
        //printf("%s", line);
        if (line[0] == '\n') break;
        else 
        {
            for (i = 0; line[i] != 0; i++)
            {
                debug_arr[line_counter][i] = line[i] -'0';
            }
            
            line_counter++;
        }

    }
    fclose(file);
    printf("%d \n", line_counter);
    
    int k=0;
    int count_one=0;
    int count_arr[rows];
    int count_zero=0;
    for ( i = 0; i < rows; i++)
    {
        count_one=0;
        count_zero=0;
        for ( k = 0; k < lines; k++)
        {
            if (debug_arr[k][i]==1)
            {
                count_one++;
            }
            else if (debug_arr[k][i]==0)
            {
                count_zero++;
            }
            else printf("Error Handler im Counter \n");
                      
        }

        if (count_one>count_zero)
        {
            count_arr[i]=1;
        }
        else if (count_zero>count_one)
        {
            count_arr[i]=0;
        }
        else printf("Error Handler Prüfung 1>0 \n");   
    }
    
    for ( i = 0; i < rows; i++)
    {
        printf(" %d ", count_arr[i] );
    }
    
    return 0;
}