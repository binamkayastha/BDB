#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    /*
     * Take arg as shell script file input.
     * Prompt user for next action
     *  -> step: run one line in shell script
     *  -> break #: add breakpoint at line #
     *  -> continue: run till completion or reach breakpoint
     *  -> printf "%s/n" "var": prints the variable (run bash command)
     *  -> anything else: run bash command
     */
    // If there isn't one arguement
    if(argc != 2) {
        printf("Usage: ./BDB \"filename\"\n");
        return(1); // Failure
    } else {
        printf("Analyzing script %s...\n", argv[1]);
    }

    // Try to open file
    FILE *file;
    char *filename = argv[1];

    file = fopen(filename, "r");

    if(file == NULL) { // Throw error if not found
        perror(filename);
    }


    // lineBuffer, assuming that the line in the script isn't goin to be more than 1024 characters long.
    char *lineBuffer = (char *) malloc(sizeof(char)* 1024);
    // Size of lineBuffer
    int lineBufferMaxSize = sizeof(char) * 1024;



    // Used to keep track of line number in code
    int lineNum = 1;

    if(file) {
        while (fgets(lineBuffer, lineBufferMaxSize, file) != NULL) {
            printf("%i: %s", lineNum, lineBuffer);
            lineNum++;
        }
        fclose(file);
    }


    return (0); //Sucess
}
