#include <stdio.h>

#include "cvector/svector.h"
#include "cvector/nvector.h"

int main(int argc, char *argv[])
{
    char ch = 0;
    int result = 0;
    int status = 0;
    size_t idx = 0;

    svector string;
    nvector numbers;

    FILE *testFile;

    printf("\n Using cvector built statically with test program.\n");

    printf("\n Testing svector functionality:\n");

    // Initializing the vector with the provided size macros; any value can be used though
    result = svector_set(&string, SV_INITIAL_LENGTH_ONE);
    if (result != 0)
    {
        printf("\n Error allocating svector.\n");
        status = -1;
    }
    else
    {
        printf("\n Reading contents from '%s':\n", argv[1]);

        testFile = fopen(argv[1], "r");

        if (testFile != NULL)
        {   
            // Appending data one character at a time
            while ((ch = fgetc(testFile)) != EOF)
            {
                svector_add(&string, &ch);
            }

            /*
             * Using .index instead of .length because .index keeps track of the actual data length in the vector,
             * .length is the <current> allocated length
             */
            printf("\n File contents:\n\n");
            for (idx = 0; idx < string.index; idx++)
            {
                // Data inside the vector is accessible like an array
                printf("%c", string.data[idx]);
            }

            // The vector can also be printed directly like a string
            printf("\n Printing like a string:\n\n");
            printf("%s", string.data);

            // Changing some characters inside the vector and printing
            for (idx = 0; idx < string.index; idx++)
            {
                if (idx == string.index / 2)
                {
                    string.data[idx] = '*';
                }
                if (idx == string.index / 3)
                {
                    string.data[idx] = '@';
                }
                if (idx == string.index / 4)
                {
                    string.data[idx] = '%';
                }
                if (idx == string.index / 5)
                {
                    string.data[idx] = '#';
                }
                if (idx == string.index / 6)
                {
                    string.data[idx] = '&';
                }
            }
            printf("\n Changing some chars:\n\n");
            printf("%s", string.data);

            // If needed, the vector can be cleared
            printf("\n Clearing the vector:\n\n");
            svector_clear(&string);
            printf("%s", string.data);
            printf(" ^^^(empty)^^^\n");

            // After using the vector (allocated in the heap), it should be deallocated
            svector_free(&string);
        }
        else
        {
            printf("\n Error opening file.\n");
            status = -1;
        }
    }
    
    // printf("\n Testing nvector functionality:\n");

    // // Initializing the vector with the provided size macros; any value can be used though
    // result = nvector_set(&numbers, NV_INITIAL_LENGTH_ONE);
    // if (result != 0)
    // {
    //     printf("Error allocating nvector");
    //     status = -1;
    // }
    // else
    // {
    //     /* code */
    // }
    
    if (result == 0)
    {
        printf("\n End example! \n\n");
    }
    return status;
}
