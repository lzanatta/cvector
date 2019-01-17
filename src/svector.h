#ifndef SCVECTOR_H_INCLUDED
#define SCVECTOR_H_INCLUDED

/* ****************************************************************************************************************** */
/*
	Macros, types and variables

	*/

#define SV_INITIAL_SIZE_ONE   	64
#define SV_MAX_SIZE_ONE			1024
#define SV_GROWTH_FACTOR_ONE	32

#define SV_INITIAL_SIZE_TWO		512
#define SV_MAX_SIZE_TWO			8192
#define SV_GROWTH_FACTOR_TWO	256

#define SV_CAP_REACHED			-2
#define SV_CAP_ERROR_VERBOSE	"svector maximum size reached"
#define SV_ALLOC_ERROR			-1
#define SV_ALLOC_ERROR_VERBOSE	"svector allocation error"

// Defining the svector type for a dynamically sized array of chars (string)
typedef struct {
    char *data;             // Pointer to the actual vector
    size_t index;           // Indexes of the vector
    size_t vectorSize;      // Current size of the vector (number of indexes)
    size_t growthFactor;	// Factor in which the vector will expand
    size_t maxSize;			// Maximum size the vector can have
} svector;

/* ****************************************************************************************************************** */
/*
	Prototypes

	*/

// Allocate and zero initialize vector
int setStrVector(svector *cvector, size_t initialSize);

// Append character into vector and resize it if necessary
int appendStrVector(svector *cvector, char *element);

// Concatenate string with vector and resize it if necessary
void concatStrVector(svector *destination, char *source);

// Clear vector and reset vector
void clearStrVector(svector *cvector);

// Print vector in the terminal
void showStrVector(svector *cvector);

// Clear and deallocate vector
void freeStrVector(svector *cvector);

/* ****************************************************************************************************************** */

#endif // SCVECTOR_H_INCLUDED
