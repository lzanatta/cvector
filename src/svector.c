#include <stdlib.h>
#include <stdio.h>

#include "svector.h"

// Allocate and zero initialize vector
int setStrVector(svector *cvector, size_t initialSize)
{
	/*
        Other possible methods to allocate and clear the array:

        Using malloc (requires manually clearing the array after allocation):

        cvector->data = (char *)malloc(initialSize * sizeof(char));
        for (cvector->index = 0; cvector->index < initialSize; cvector->index++)
        {
            cvector->data[cvector->index] = '\0';
        }
        cvector->vectorSize = initialSize;
        cvector->index = 0;

        Using memset (requires string.h):

        memset(cvector->data, 0, initialSize * (sizeof(cvector->data[cvector->index])));

        */

    // Allocates the array and initializes all bits to zero
    cvector->data = (char *)calloc(initialSize, sizeof(char));

	if (cvector->data == NULL)
	{
		return SV_ALLOC_ERROR;
	}
	else
	{
		cvector->vectorSize = initialSize;
		cvector->index = 0;

		switch (initialSize)
		{
		case SV_INITIAL_SIZE_ONE:
			cvector->growthFactor = SV_GROWTH_FACTOR_ONE;
			cvector->maxSize = SV_MAX_SIZE_ONE;
			break;
		case SV_INITIAL_SIZE_TWO:
			cvector->growthFactor = SV_GROWTH_FACTOR_TWO;
			cvector->maxSize = SV_MAX_SIZE_TWO;
			break;
		}
	}

	return 0;
}

// Append character into vector and resize it if necessary
int appendStrVector(svector *cvector, char *element)
{
    if (cvector->index == (cvector->vectorSize - 1))
    {
        //if (cvector->vectorSize < SV_MAX_SIZE_ONE)
        if (cvector->vectorSize < cvector->maxSize)
		{
			//cvector->vectorSize += SV_GROWTH_FACTOR_ONE;
			cvector->vectorSize += cvector->growthFactor;
			cvector->data = (char *)realloc(cvector->data, cvector->vectorSize * sizeof(char));

			for (unsigned int i = cvector->index; i < cvector->vectorSize; i++)
			{
				cvector->data[i] = '\0';
			}
		}
		else
		{
			return SV_CAP_REACHED;
		}
    }

    cvector->data[cvector->index++] = *element;

	return 0;
}

// Append character into vector and resize it if necessary
void concatStrVector(svector *destination, char *source)
{
	while (*source != '\0')
	{
		appendStrVector(destination, source);
		source++;
	}
}

// Clear vector and reset vector
void clearStrVector(svector *cvector)
{
    for (cvector->index = 0; cvector->index < cvector->vectorSize; cvector->index++)
    {
        cvector->data[cvector->index] = '\0';
    }
    cvector->index = 0;
}

// Print vector in the terminal
void showStrVector(svector *cvector)
{
    printf("%s", cvector->data);
}

// Clear and deallocate vector
void freeStrVector(svector *cvector)
{
    cvector->data = NULL;
    cvector->vectorSize = 0;
    cvector->index = 0;
    cvector->maxSize = 0;
    cvector->growthFactor = 0;
    free(cvector->data);
}
