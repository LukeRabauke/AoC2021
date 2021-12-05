#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, char* argv[])
{
    char const* const fileName = "input.txt";
    FILE* file = fopen(fileName, "r");
    char line[256];
    int lines=1000;
    int rows=12;
    enum { x=1000 };
    enum { y=12 };
    int debug_arr[x][y]={0};
    int debug_arr_neg[x][y]={0};
    int line_counter=0;
    int i =0;
    int dezimal1=0;
    double potenz_counter=11;
    int dezimal2=0;
    int count_arr[i];
    int oxygen_arr[y];
    int co2_arr[y];


     while (fgets(line, sizeof(line), file)) {
        //printf("%s", line);
        if (line[0] == '\n') break;
        else 
        {
            for (i = 0; line[i] != 0; i++)
            {
                debug_arr[line_counter][i] = line[i] -'0';
                debug_arr_neg[line_counter][i] = line[i] -'0';
            }
            
            line_counter++;
        }

    }
    fclose(file);
    printf("%d \n", line_counter);
    

    int k=0;
    int s=0;
    int count_one=0;
    int count_one_neg=0;
    int count_zero=0;
    int count_zero_neg=0;

    for ( i = 0; i < rows; i++)
    {
        count_one=0;
        count_zero=0;
        count_one_neg=0;
        count_zero_neg=0;
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

            if (debug_arr_neg[k][i]==1)
            {
                count_one_neg++;
            }
            else if (debug_arr_neg[k][i]==0)
            {
                count_zero_neg++;
            }
                     
        }

        if (count_one>count_zero && count_one+count_zero>1)
        {
            for (s = 0; s < rows; s++)
            {
                for (k = 0; k < lines; k++)
                {
                    if (debug_arr[k][i] == 0 || debug_arr[k][i]==9)
                    {
                        debug_arr[k][s]=9;
                    } 
                }
            }
        }    
            
        else if (count_zero>count_one && count_one+count_zero>1)
        {
            for (s = 0; s < rows; s++)
            {
                for (k = 0; k < lines; k++)
                {
                    if (debug_arr[k][i]==1 || debug_arr[k][i]==9)
                    {
                        debug_arr[k][s]=9;
                    }  
                }
            }
        }

        else if (count_zero==count_one && count_one+count_zero>1)
        {
            for (s = 0; s < rows; s++)
            {
                for (k = 0; k < lines; k++)
                {
                    if (debug_arr[k][i]==0 || debug_arr[k][i]==9)
                    {
                        debug_arr[k][s]=9;
                    }
                }
            }
        }
        else printf("Error Handler Prüfung 1>0 \n");

        if (count_one_neg>count_zero_neg && count_one_neg+count_zero_neg>1)
        {
            for (s = 0; s < rows; s++)
            {
                for (k = 0; k < lines; k++)
                {
                    if (debug_arr_neg[k][i] == 1 || debug_arr_neg[k][i]==9)
                    {
                        debug_arr_neg[k][s]=9;
                    }  
                }
            }
        }    
            
        else if (count_zero_neg>count_one_neg && count_one_neg+count_zero_neg>1)
        {
            for (s = 0; s < rows; s++)
            {
                for (k = 0; k < lines; k++)
                {
                    if (debug_arr_neg[k][i]==0 || debug_arr_neg[k][i]==9)
                    {
                        debug_arr_neg[k][s]=9;
                    }   
                }
            }
        }

        else if (count_zero_neg==count_one_neg && count_one_neg+count_zero_neg>1)
        {
            for (s = 0; s < rows; s++)
            {
                for (k = 0; k < lines; k++)
                {
                    if (debug_arr_neg[k][i] == 1 || debug_arr_neg[k][i]==9)
                    {
                        debug_arr_neg[k][s]=9;
                    }   
                }
            }
        }
             
    }
   
    for ( i = 0; i < rows; i++)
    { 
        for (k = 0; k < lines; k++)
        {
            if (debug_arr[k][i]!=9)
            {
                oxygen_arr[i]=debug_arr[k][i];
            }
            if (debug_arr_neg[k][i]!=9)
            {
                co2_arr[i]=debug_arr_neg[k][i];
            }
        }
    }
    
    for ( i = 0; i < y; i++)
    {
        dezimal1 += oxygen_arr[i]*pow(2,potenz_counter);
        dezimal2 += co2_arr[i]*pow(2,potenz_counter);
        potenz_counter--;

    }
    printf("Die Lösung lautet: %d \n" , dezimal1*dezimal2);
    return 0;
}