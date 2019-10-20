#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXPECTED_NUM_ARGS 2

char *help_str = "ERROR: Incorrect number of arguments.\n\nNAME\n\tfilereader - Read and print contents of a file.\nSYNOPSIS\n\tfilereader nameofthefile.txt\n\n";

int main(int argc, char **argv)
{
    //Checking input parameters
    char *fileName;
    if (argc == EXPECTED_NUM_ARGS)
    {
        printf("Reading file %s\n", argv[1]);
        printf("***************************\n\n");
    }
    else if (argc > EXPECTED_NUM_ARGS)
    {
        //Show help in case of incorrect parameters
        printf("%s", help_str);
        exit(EXIT_FAILURE);
    }
    else
    {
        //Show help in case of incorrect parameters
        printf("%s", help_str);
        exit(EXIT_FAILURE);
    }
    //Try to open the file
    int num;
    FILE *fptr;
    if ((fptr = fopen(argv[1], "r")) == NULL)
    {
        printf("ERROR: File could not be opened.");
        // Program exits if the file pointer returns NULL.
        exit(EXIT_FAILURE);
    }
    //Read the file and print the contents.
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, fptr)) != -1)
    {
        printf("%s", line);
    }
    fclose(fptr);
    return EXIT_SUCCESS;
}
