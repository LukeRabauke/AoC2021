#include <stdio.h>

int main(int argc, char* argv[])
{
    char const* const fileName = "input.txt";
    FILE* file = fopen(fileName, "r");
    char line[256];

    while (fgets(line, sizeof(line), file)) {
        printf("%s", line); 
    }

    fclose(file);

    return 0;
}

