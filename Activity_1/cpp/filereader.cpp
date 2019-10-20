#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define EXPECTED_NUM_ARGS 2

std::string help_str = "ERROR: Incorrect number of arguments.\n\nNAME\n\tfilereader - Read and print contents of a file.\nSYNOPSIS\n\tfilereader nameofthefile.txt\n\n";

//Create a helper class to parse the input arguments and read the file name.

class ArgumentParser
{ // Parses input arguments and assigns the first argument as the fileName
private:
    string _fileName = "";
    int _argc;
    char **_argv;

public:
    // Constructor
    ArgumentParser(int argc, char **argv)
    {
        _argc = argc;
        _argv = argv;
    }

    void ParseArguments()
    {
        //Checking input parameters
        char *fileName;
        if (_argc == EXPECTED_NUM_ARGS)
        {
            cout << "Reading file " << _argv[1] << "\n";
            cout << "***************************\n\n";
        }
        else if (_argc > EXPECTED_NUM_ARGS)
        {
            //Show help in case of incorrect parameters
            cout << help_str;
            exit(EXIT_FAILURE);
        }
        else
        {
            //Show help in case of incorrect parameters
            cout << help_str;
            exit(EXIT_FAILURE);
        }
        _fileName = _argv[1];
    }
    //Public method to access private variable
    string getFileName()
    {
        return (_fileName);
    }
};

int main(int argc, char **argv)
{
    ArgumentParser parser(argc, argv);
    parser.ParseArguments();
    //Checking input parameters
    string fileName;
    fileName = parser.getFileName();

    //Try to open the file
    ifstream myReadFile;
    string buffer;
    myReadFile.open(fileName);
    if (myReadFile.is_open())
    {
        while(!myReadFile.eof()) // To get you all the lines.
        {
	        getline(myReadFile,buffer); // Saves the line in STRING.
	        cout<<buffer << endl; // Prints our STRING.
        }
        myReadFile.close();
    }
    else
    {
        cout << "ERROR: File could not be opened.\n";
        // Program exits if the file pointer returns NULL.
        exit(EXIT_FAILURE);
    }
    return EXIT_SUCCESS;
}
