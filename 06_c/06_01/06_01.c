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
    char *glow_fish = (char*)malloc(9000000000000 * sizeof(char));
    //char glow_fish[7000000]={9};
    int day=0;
    long long current_entries=300; 
    long long sliding_numb=299, i=0;

    while (fgets(line, sizeof(line), file))
    {
        printf("%s", line);

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
                ptr = strtok(NULL, delim);
                input_counter++;
                i++;
            }
        }
    }
    fclose(file);
    printf(" Anzahl an Einträgen in Vektor : %d \n", input_counter);
    i=0;

    for (day = 0; day < 80; day++)
    {
        
        for (i=0;i<current_entries;i++)
        {
            if (glow_fish[i]!=0 && glow_fish[i]>0 )
            {
                glow_fish[i]--;
            }
            else if (glow_fish[i]==0)
            {
                glow_fish[i]=6;
                sliding_numb++;
                glow_fish[sliding_numb]=8;
            }
            else printf("Error, unzulässige Nummer als Eintrag gefunden!");
            
        }
        current_entries=sliding_numb+1; //übertrage die neuen Tage als neues Schleifenende
        printf("We are at day: %d \n", day);
    }
    
    printf("Anzahl der Fische ingesamt: %lld \n", current_entries);

    return 0;
}
