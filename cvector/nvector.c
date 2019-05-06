#include <stdlib.h>

#include "nvector.h"

// Allocate and zero initialize vector
int nvector_set(nvector *cvector, size_t initial_length)
{
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

    // Allocates the array and initializes all bits to zero
    cvector->data = (unsigned int *)calloc(initial_length, sizeof(unsigned int));
    cvector->length = initial_length;
    cvector->index = 0;
    cvector->print_index= 0;
}

// Append data into vector and resize it if necessary
int nvector_add(nvector *cvector, unsigned int *element)
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

// Clear and reset vector
void nvector_clear(nvector *cvector)
{
    for (cvector->index = 0; cvector->index < cvector->length; cvector->index++)
    {
        cvector->data[cvector->index] = 0;
    }
    cvector->index = 0;
}

// Deallocate vector
void nvector_free(nvector *cvector)
{
    cvector->data = NULL;
    cvector->length = cvector->index = cvector->print_index = 0;
    free(cvector->data);
}
