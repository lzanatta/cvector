#include <stdlib.h>
#include <stdio.h>

#include "nvector.h"

/*
    Last edited: 25/04/2017

	*/

// Function to initialize the vector
void setNumVector(nvector *cvector, size_t initialSize)
{
    // Allocates the array and initializes all bits to zero
    cvector->data = (unsigned int *)calloc(initialSize, sizeof(unsigned int));
    cvector->vectorSize = initialSize;
    cvector->dataIndex = 0;
    cvector->printIndex= 0;

    /*
        Other possible methods to allocate and clear the array:

        Using malloc (requires manually clearing the array after allocation):

        cvector->data = (unsigned int *)malloc(initialSize * sizeof(unsigned int));
        for (cvector->dataIndex = 0; cvector->dataIndex < initialSize; cvector->dataIndex++)
        {
            cvector->data[cvector->dataIndex] = 0;
        }
        cvector->vectorSize = initialSize;
        cvector->dataIndex = 0;
        cvector->printIndex= 0;

        Using memset (requires string.h):

        memset(cvector->data, 0, initialSize * (sizeof(cvector->data[cvector->dataIndex])));

        */
}

// Function to append data into the vector and resize it if necessary
int appendNumVector(nvector *cvector, unsigned int *element)
{
    if (cvector->dataIndex == (cvector->vectorSize - 1))
    {
        if (cvector->vectorSize < NV_MAX_SIZE)
		{
			cvector->vectorSize += NV_GROWTH_FACTOR;
			cvector->data = (unsigned int *)realloc(cvector->data, cvector->vectorSize * sizeof(unsigned int));

			for (unsigned int i = cvector->dataIndex; i < cvector->vectorSize; i++)
			{
				cvector->data[i] = 0;
			}
		}
		else
		{
			return -1;
		}
    }

    cvector->data[cvector->dataIndex++] = *element;

	return 0;
}

// Function to print the vector in the terminal
void showNumVector(nvector *cvector, int i)
{
    printf("nvector holds: ");
    for (cvector->printIndex = i; (cvector->printIndex) < (cvector->dataIndex); cvector->printIndex++)
    {
        printf("\t%d", cvector->data[cvector->printIndex]);
        if ((cvector->printIndex) < (cvector->dataIndex - 1))
        {
            printf("\n\t");
        }
    }
}

// Function to clear and deallocate the vector
void freeNumVector(nvector *cvector)
{
    cvector->data = NULL;
    cvector->vectorSize = cvector->dataIndex = cvector->printIndex = 0;
    free(cvector->data);
}
