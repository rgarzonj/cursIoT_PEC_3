#include <stdio.h>

char *tmpnam(char *s);
FILE *tmpfile(void);

#define EXPECTED_NUM_ARGS 3



int main(int argc, char **argv)
{
    if( argc == EXPECTED_NUM_ARGS ) {
      printf("The argument supplied is %s\n", argv[1]);
   }
   else if( argc > EXPECTED_NUM_ARGS ) {
      printf("Too many arguments supplied.\n");
   }
   else {
      printf("One argument expected.\n");
   }

for (int i = 1; i < argc; i++)
{  
    if (i + 1 != argc)
    {
        if (strcmp(argv[i], "-filename") == 0) // This is your parameter name
        {                 
            char* filename = argv[i + 1];    // The next value in the array is your value
            i++;    // Move to the next flag
        }
    }
}

    for (int i = 0; i < argc; ++i)
    {
        printf("argv[%d]: %s\n", i, argv[i]);
    }
}


