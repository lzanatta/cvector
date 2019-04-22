#include <stdlib.h>
//#include <stdio.h>

#include "nvector.h"

// Allocate and zero initialize vector
void setNumVector(nvector *cvector, size_t initial_size)
{
    // Allocates the array and initializes all bits to zero
    cvector->data = (unsigned int *)calloc(initial_size, sizeof(unsigned int));
    cvector->length = initial_size;
    cvector->index = 0;
    cvector->print_index= 0;

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

// Append data into vector and resize it if necessary
int appendNumVector(nvector *cvector, unsigned int *element)
{
    if (cvector->index == (cvector->length - 1))
    {
        if (cvector->length < cvector->max_length)
        {
            cvector->length += NV_GROWTH_FACTOR;
            cvector->data = (unsigned int *)realloc(cvector->data, cvector->length * sizeof(unsigned int));

            for (unsigned int i = cvector->index; i < cvector->length; i++)
            {
                cvector->data[i] = 0;
            }
        }
        else
        {
            return -1;
        }
    }

    cvector->data[cvector->index++] = *element;

    return 0;
}

// Function to print the vector in the terminal
// void showNumVector(nvector *cvector, int i)
//{
//    printf("nvector holds: ");
//    for (cvector->printIndex = i; (cvector->printIndex) < (cvector->dataIndex); cvector->printIndex++)
//    {
//        printf("\t%d", cvector->data[cvector->printIndex]);
//        if ((cvector->printIndex) < (cvector->dataIndex - 1))
//        {
//            printf("\n\t");
//        }
//    }
//}

// Deallocate vector
void freeNumVector(nvector *cvector)
{
    cvector->data = NULL;
    cvector->length = cvector->index = cvector->print_index = 0;
    free(cvector->data);
}
