#ifndef NCVECTOR_H_INCLUDED
#define NCVECTOR_H_INCLUDED

//#include "stddef.h"

/*
    Last edited: 25/04/2017

	*/

/* ****************************************************************************************************************** */
/*
	Macros, types and variables

	*/

#define NV_INITIAL_SIZE     	4
#define NV_MAX_SIZE				128
#define NV_GROWTH_FACTOR		2

// Defining the nvector type for a dynamically sized array of numbers
typedef struct {
    unsigned int *data;     // Pointer to the actual vector
    size_t dataIndex;       // Indexes of the vector
    size_t printIndex;      // Another index counter for printing only
    size_t vectorSize;      // Current size of the vector (number of data indexes)
	size_t growthFactor;	// Factor in which the vector will expand
    size_t maxSize;			// Maximum size the vector can have
} nvector;

/* ****************************************************************************************************************** */
/*
	Prototypes

	*/

// Allocate and zero initialize vector
void setNumVector(nvector *cvector, size_t initialSize);

// Append number into vector and resize it if necessary
int appendNumVector(nvector *cvector, unsigned int *element);

// Print vector in the terminal
void showNumVector(nvector *cvector, int i);

// Clear and deallocate vector
void freeNumVector(nvector *cvector);

/* ****************************************************************************************************************** */

#endif // NCVECTOR_H_INCLUDED
