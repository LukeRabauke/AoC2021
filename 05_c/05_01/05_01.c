#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char const* const fileName = "input.txt";
    FILE* file = fopen(fileName, "r");
    char line[256];

    char delimiter[] = ", ->";
    char *ptr;
    
    int coord[1000][4]={0}, i=0,k=0;
    int max_number=0;
    // initialisieren und ersten Abschnitt erstellen
    
    while (fgets(line, sizeof(line), file)) {
        //printf("%s", line); 
        ptr = strtok(line, delimiter);
        k=0;
        while(ptr != NULL) {
            //printf("Abschnitt gefunden: %s\n", ptr);
            coord[i][k]=atoi(ptr);
            if (coord[i][k]>max_number) max_number=coord[i][k];
            
            ptr = strtok(NULL, delimiter);
            k++;
        }
        i++;
    }
    fclose(file);
    printf("Zeilenanzahl: %d \n", i);

    for ( i = 0; i < 500; i++)
    {
        if (coord[i][0]==coord[i][2] || coord[i][1] == coord[i][3] )
        {
            /* code */
        }
        
    }
    
    return 0;
}

