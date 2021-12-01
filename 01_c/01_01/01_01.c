#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    char const* const fileName = "input.txt";
    FILE* file = fopen(fileName, "r");
    char line[256];
    int deeper = 0;
    double sonar_new;
    double sonar_old;
    char *ptr;
    double ret;
    int first_label = 0;

    while (fgets(line, sizeof(line), file)) {
        //printf("%s", line);
        sonar_new = strtod(line, &ptr); 
        if (sonar_new > sonar_old && first_label != 0)
        {
            first_label = 1;
            deeper++;
            sonar_old = sonar_new;

        }
        else 
        {
            first_label = 1;
            sonar_old = sonar_new;
        }
        //printf("The number(double) is %lf\n", sonar_1);
    }

    fclose(file);
    printf("Anzahl der increasten Sonars ist: %i", deeper);
    return 0;
}

