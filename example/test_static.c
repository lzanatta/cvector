#include <stdio.h>

#include "src/svector.h"

int main(int argc, char *argv[])
{   
    char ch = 0;
    size_t idx = 0;

    svector string;
    // nvector numbers;

    FILE *testFile;

    // Initializing the vector with the provided size macros; any value can be used though
    svector_set(&string, SV_INITIAL_LENGTH_ONE);
    // setNumVector(&numbers, NV_INITIAL_SIZE);

    printf("\n Using cvector built statically with test program.\n");

    printf("\n Testing svector functionality:\n");
    
    printf("\n Reading contents from '%s':\n\n", argv[1]);

    testFile = fopen(argv[1], "r");

    if (testFile != NULL)
    {   
        // Appending data one character at a time
        while ((ch = fgetc(testFile)) != EOF)
        {
            svector_add(&string, &ch);
        }

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

        // A print function is also included
        printf("\n Using built-in print function:\n\n");
        svector_print(&string);

        // If needed, the vector can be cleared
        printf("\n Clearing the vector:\n\n");
        svector_clear(&string);
        svector_print(&string);

        printf("\n");

        // After using the vector (allocated in the heap), it should be deallocated
        svector_free(&string);
    }
    else
    {
        printf(" Error opening file.\n");
    }

    return 0;
}
