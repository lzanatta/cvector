#include <stdio.h>

#include "cvector/svector.h"
#include "cvector/nvector.h"

int main(int argc, char *argv[])
{
    svector string;
    nvector numbers;

    // setStrVector(&string, SV_INITIAL_SIZE_ONE);
    // setNumVector(&numbers, NV_INITIAL_SIZE);

//    FILE *testFile;
//
//    testFile = fopen("input.txt", "r");

    printf("\n Using cvector as a shared library.\n");

    printf("\n Testing svector functionality:\n");

    // appendStrVector(&string, "x");

    printf("string contents: ");

    // for (i = 0; i < string.vectorSize; i++) {
    //     printf("%c", string.data[i]);
    // }

    printf("\n\n");

    return 0;
}
