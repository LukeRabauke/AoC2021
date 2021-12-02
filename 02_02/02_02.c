#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char const* const fileName = "input.txt";
    FILE* file = fopen(fileName, "r");
    char line[256];
    int line_counter=0;

    double depth=0;
    double horizontal=0;
    double result=0;
    double value=0;
    double aim=0;
    int state=0;

     while (fgets(line, sizeof(line), file)) {
        
        if (line[0] == '\n') break;
        else 
        {
            char *ch;
            ch = strtok(line, " ");
            int i=0;
            state = 0;
            while (ch != NULL) {
                //printf("%s\n", ch);
                if (strcmp(ch,"up")==0 && state==0)
                {
                    state = 1;
                }
                else if (strcmp(ch,"down")==0 && state==0)
                {
                    state = 2;
                    
                }
                else if (strcmp(ch,"forward")==0 && state==0 )
                {
                    state = 3;
                    
                }
                else if (state!=0)
                {
                    sscanf(ch, "%lf", &value);
                }
                ch = strtok(NULL, " ,");
            }
            
            if (state ==1)
            {
                //means up
                aim = aim-value;
            }
            else if (state==2)
            {
                //means down
                aim= aim+value;
            }

            else if (state==3)
            {
                //means horizontal
                horizontal = horizontal + value;
                depth = depth + (aim*value);
            }
            //printf("%f", value);
            line_counter++;
        }
    }  

    fclose(file);
    result = depth*horizontal;
    printf("Das Ergebnis lautet: %f", result);
    return 0;
}

