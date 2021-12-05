#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
    char const *const fileName = "input.txt";
    FILE *file = fopen(fileName, "r");
    char line[256], *ptr, *ptr2;
    int first_line = 0;
    int input_vec[100] = {0};
    int i = 0,k=0, input_counter=0, space_counter=0, line_counter=0, sheet_counter=0;
    int bingo_sheet [100][5][5]={0}, bingo_sheet_state [100][5][5]={0};
    char delim2[] = " ";
    int j=0, t=0;
    int bingo_count_column=0, bingo_count_row=0;
    int winner_sheet=0, input_number_win=0;
    int max_input=0,max_input_old=0;
    int sum=0;
 

    while (fgets(line, sizeof(line), file))
    {
        //printf("%s", line);
        if (line[0]=='\n')
        {
            space_counter++;
        }
        
        if (first_line == 0 && line[0] != '\n')
        {
            //printf("%s \n", line);
            char delim[] = ",";

            ptr = strtok(line, delim);
            if (input_vec[0]!=0)
            {
                first_line=1;
            }
            while (ptr != NULL)
            {
                //printf("'%s'\n", ptr);
                input_vec[i]=atoi(ptr);
                ptr = strtok(NULL, delim);
                input_counter++;
                i++;
            }
        }

        else if (first_line!=0 && line[0] != '\n')
        {   
            ptr2 = strtok(line, delim2);
            i=0;
            while (ptr2 != NULL)
            {
                //printf("'%s'\n", ptr);
                
                bingo_sheet[sheet_counter][line_counter][i]=atoi(ptr2);
                ptr2 = strtok(NULL, delim2);
                i++;
            }
            line_counter++;
            if (line_counter>4)
            {
                sheet_counter++;
                line_counter=0;
            }
            
            
        }
        

    }
    fclose(file);
    //printf("Es gibt %d Inputs für das Raetsel", input_counter);
    //printf("Anzahl leerer Zeilen %d ", space_counter);

    for ( i = 0; i < 100; i++) //Schleife über die Bingo Sheets
    {
        end:
        //printf("Zufallszahl: %d \n", input_vec[i]);
        for ( k = 0; k < 100; k++)  //Schleife über Zufallszahlen
        {
            for (j= 0; j < 5; j++)  //Schleife über Zeile des Sheets
            {
                for (t= 0; t < 5; t++) // Schleife über Spalte des Sheets
                {
                    if (bingo_sheet[i][j][t]==input_vec[k])
                    {
                        bingo_sheet_state[i][j][t]=1;
                    }
                    
                }   
            }

            bingo_count_row=0;
            bingo_count_column=0;
            for (j= 0; j < 5; j++)  //Schleife über Zeile des Sheets
            {
                bingo_count_row=0;
                for (t= 0; t < 5; t++) // Schleife über Spalte des Sheets
                {
                    if (bingo_sheet_state[i][j][t]==1)
                    {
                        bingo_count_row++;
                    }
                    if (bingo_count_row==5) 
                    {
                        //winner_sheet=k;
                        //input_number_win=i;
                        if (k>max_input)
                        {
                            max_input=k;
                            winner_sheet=i;
                            printf("Winnersheet Nummer: %d \n",winner_sheet);
                        }
                        //printf("Winnersheet Nummer: %d \n",winner_sheet);
                        i++;
                        goto end;
                    }
                }
            }
            
            
            for (j= 0; j < 5; j++)  //Schleife über Zeile des Sheets
            {
                bingo_count_column=0;
                for (t= 0; t < 5; t++) // Schleife über Spalte des Sheets
                {
                    if (bingo_sheet_state[i][t][j]==1)
                    {
                        bingo_count_column++;
                    }
                    if (bingo_count_column==5) 
                    {
                        if (k>max_input)
                        {
                            max_input=k;
                            winner_sheet=i;
                            
                            printf("Winnersheet Nummer: %d \n",winner_sheet); 
                        }
                        i++;
                        goto end;
                    }
                }
            }      
        }
        
    }

    //end:
    printf("Last Winnersheet Number: %d \n", winner_sheet);
    
    for ( i = 0; i < 5; i++)
    {
        for (k = 0; k < 5; k++)
        {
        if (bingo_sheet_state[winner_sheet][i][k]==0)
        {
            sum += bingo_sheet[winner_sheet][i][k];
            //printf("Summe: %d \n", sum);
        }
            
        }
        
    }
    printf("Das Ergebnis des Rätsels lautet %d \n", sum*input_vec[max_input]);

    return 0;
}
