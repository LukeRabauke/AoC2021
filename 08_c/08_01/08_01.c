#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char const* const fileName = "input.txt";
    FILE* file = fopen(fileName, "r");
    char line[1000000], digits[4][7]={};
    char delim[]={" "}, *ptr;
    int i=0, number_inputs, digits_int[4]={0}, digit_read=0, counter=0, k=0, digit_counter=0;

    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
        ptr = strtok(line, delim);
        digit_read=0;
        i=0;
        while (ptr != NULL)
        {
            //printf("'%s'\n", ptr);
            char hold[10]="";
            if (digit_read==1)
            {
                strcat(hold,ptr);
                //digits[i] = *ptr;
                counter=0;
                for (k=0;k<10;k++)
                {
                    if (strcmp(&hold[k],"\0")!=0 && strcmp(&hold[k],"\n")!=0 )
                    {
                        counter++;
                    }
                }
                i++;
                if (counter== 2 || counter ==4 || counter==3 || counter==7)
                {
                    digit_counter++;
                }
                
            }
            else if (digit_read==0 && strcmp(ptr,"|")==0)
            {
                digit_read=1;
            }
            
            
            ptr = strtok(NULL, delim);
            number_inputs++;
        }
    }

    fclose(file);
    printf(" Anzahl der gesuchten Digits: %d \n", digit_counter);

    return 0;
}

