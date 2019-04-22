#include <stdio.h>

#include "cvector/svector.h"
#include "cvector/nvector.h"

int main(void)
{
    svector string;
    nvector numbers;

    int i = 0;

    // setStrVector(&string, SV_INITIAL_SIZE_ONE);
    // setNumVector(&numbers, NV_INITIAL_SIZE);

//    FILE *testFile;
//
//    testFile = fopen("input.txt", "r");

    printf("\nUsing cvector as a DLL\n\n");

    // appendStrVector(&string, "x");

    printf("string contents: ");

    // for (i = 0; i < string.vectorSize; i++) {
    //     printf("%c", string.data[i]);
    // }

    printf("\n\n");

    return 0;
}
