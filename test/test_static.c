#include <stdio.h>

#include "src/svector.h"
#include "src/nvector.h"

int main(void)
{   
    char c = 0;
    size_t i = 0;

    svector string;
    nvector numbers;

    setStrVector(&string, SV_INITIAL_SIZE_ONE);
    setNumVector(&numbers, NV_INITIAL_SIZE);

    FILE *testFile;

    testFile = fopen("input.txt", "r");

    printf("\n Using cvector built statically with test program\n\n");

    while ((c = fgetc(testFile)) != EOF) {
        appendStrVector(&string, &c);
    }

    printf(" <string> contents:\n\n");

    for (i = 0; i < string.vectorSize; i++) {
        printf("%c", string.data[i]);
    }

    printf("\n");

    return 0;
}
