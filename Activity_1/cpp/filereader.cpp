#include<iostream> 
#include <string>

#define EXPECTED_NUM_ARGS 2

std::string help_str = "ERROR: Incorrect number of arguments.\n\nNAME\n\tfilereader - Read and print contents of a file.\nSYNOPSIS\n\tfilereader nameofthefile.txt\n\n";


int main(int argc, char **argv)
{
    //Checking input parameters
    char *fileName;
    if (argc == EXPECTED_NUM_ARGS)
    {
        std::cout << "Reading file "<< argv[1] << "\n";
        std::cout << "***************************\n\n";
    }
    else if (argc > EXPECTED_NUM_ARGS)
    {
        //Show help in case of incorrect parameters
        std::cout << help_str;
        exit(EXIT_FAILURE);
    }
    else
    {
        //Show help in case of incorrect parameters
        std::cout << help_str;
        exit(EXIT_FAILURE);
    }
    //Try to open the file
    int num;
    FILE *fptr;
    if ((fptr = fopen(argv[1], "r")) == NULL)
    {
        std::cout << "ERROR: File could not be opened.\n";
        // Program exits if the file pointer returns NULL.
        exit(EXIT_FAILURE);
    }
    //Read the file and print the contents.
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, fptr)) != -1)
    {
        std::cout << line;
    }
    fclose(fptr);
    return EXIT_SUCCESS;
}


