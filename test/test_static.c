#include <stdio.h>

#include "src/svector.h"
#include "src/nvector.h"

int main(int argc, char *argv[])
{   
    char ch = 0;
    size_t idx = 0;

    svector string;
    nvector numbers;

    FILE *testFile;

    // Initializing the vector with the provided size macros; any value can be used though
    setStrVector(&string, SV_INITIAL_LENGTH_ONE);
    setNumVector(&numbers, NV_INITIAL_SIZE);

    printf("\n Using cvector built statically with test program.\n\n");
    printf(" Reading contents from '%s':\n\n", argv[1]);

    testFile = fopen(argv[1], "r");

    if (testFile != NULL)
    {   
        // Appending data one character at a time
        while ((ch = fgetc(testFile)) != EOF)
        {
            appendStrVector(&string, &ch);
        }

        printf(" Done.\n\n");
        printf(" File contents:\n\n");

        /*
         * Using .index instead of .length because .index keeps track of the actual data length in the vector,
         * .length is the <current> allocated length
         */
        for (idx = 0; idx < string.index; idx++)
        {
            // Data inside the vector is accessible like a regular array
            printf("%c", string.data[idx]);
        }

        printf(" \nDone.\n\n");

        // After using the vector (allocated in the heap), it should be deallocated
        freeStrVector(&string);
    }
    else
    {
        printf(" Error opening file.\n");
    }

    return 0;
}
