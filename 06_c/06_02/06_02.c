#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char const *const fileName = "input.txt";
    FILE *file = fopen(fileName, "r");
    char line[256], *ptr;
    char delim[] = ",";
    int input_vec[1000]={0}, input_counter=0, first_line=0;
    char glow_fish[1000]={0} ;
    //char glow_fish[7000000]={9};
    int day=0;
    long long current_entries=300,i=0;
    int max_old=0;
    long long sum=0;
    int first_run=0;
    long long ptr_array[9]={0};

    while (fgets(line, sizeof(line), file))
    {
        //printf("%s", line);

        if (first_line == 0 && line[0] != '\n')
        {
            // printf("%s \n", line);
            

            ptr = strtok(line, delim);
            // if (input_vec[0] != 0)
            // {
            //     first_line = 1;
            // }
            while (ptr != NULL)
            {
                // printf("'%s'\n", ptr);
                input_vec[i] = atoi(ptr);
                glow_fish[i] = atoi(ptr);
                if (glow_fish[i]>max_old)
                {
                    max_old=glow_fish[i];
                }
                
                ptr = strtok(NULL, delim);
                input_counter++;
                i++;
            }
        }
    }
    fclose(file);
    //printf(" Anzahl an Einträgen in Vektor : %d \n", input_counter);
    long long anzahl_0=0, anzahl_1=0, anzahl_2=0, anzahl_3=0, anzahl_4=0, anzahl_5=0, anzahl_6=0, anzahl_7=0, anzahl_8=0;
    for ( i = 0; i < current_entries; i++)
    {
        if (glow_fish[i]==0) anzahl_0++;
        else if (glow_fish[i]==1) anzahl_1++;
        else if (glow_fish[i]==2) anzahl_2++;
        else if (glow_fish[i]==3) anzahl_3++;
        else if (glow_fish[i]==4) anzahl_4++;
        else if (glow_fish[i]==5) anzahl_5++;
        
    }
    long long glow_new_array[9]={anzahl_0, anzahl_1, anzahl_2, anzahl_3, anzahl_4, anzahl_5, anzahl_6, anzahl_7, anzahl_8};

    for (day = 0; day < 256; day++)
    {
        for(i=0 ;i<9 ;i++)
        { 
            if (i==8)
            {
                ptr_array[i] = glow_new_array[0];
            }
            else if (i==6)
            {
                ptr_array[i] = glow_new_array[0]+glow_new_array[7];
            }
            else if (i!=8 && i!=6)
            {
                ptr_array[i]= glow_new_array[i+1];
            }
            else printf("Error, unzulässige Nummer als Eintrag gefunden!");
            
        }

        for ( i = 0; i < 9; i++)
        {
            glow_new_array[i] = ptr_array[i];
        }
        

        //current_entries=sliding_numb+1; //übertrage die neuen Tage als neues Schleifenende
        //printf("We are at day: %d \n", day);
    }
    
    for ( i = 0; i < 9; i++)
    {
        sum+=glow_new_array[i];
    }
    
    printf("Anzahl der Fische ingesamt: %lld \n", sum);

    return 0;
}