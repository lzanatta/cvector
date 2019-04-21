#include <stdio.h>

#include "src/svector.h"
#include "src/nvector.h"

int main(void)
{
    svector string;
    nvector numbers;

    setStrVector(&string, SV_INITIAL_SIZE_ONE);
    setNumVector(&numbers, NV_INITIAL_SIZE);

    FILE *testFile;

    testFile = fopen("input.txt", "r");

    printf("\nUsing cvector built statically with test program\n\n");

    return 0;
}
