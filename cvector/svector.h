#ifndef SVECTOR_H_INCLUDED
#define SVECTOR_H_INCLUDED

#define SV_INITIAL_LENGTH_ONE   64
#define SV_MAX_LENGTH_ONE       1024
#define SV_RESIZE_RATE_ONE      32

#define SV_INITIAL_LENGTH_TWO   512
#define SV_MAX_LENGTH_TWO       8192
#define SV_RESIZE_RATE_TWO      256

#define SV_CAP_REACHED          -2
#define SV_CAP_ERROR_VERBOSE    "svector maximum size reached"
#define SV_ALLOC_ERROR          -1
#define SV_ALLOC_ERROR_VERBOSE  "svector allocation error"

// svector struct for a dynamically sized array of chars ("string")
typedef struct cvector {
    char *data;             // Vector data
    size_t index;           // Data index
    size_t length;          // Vector length
    size_t max_length;      // Maximum length
    size_t resize_rate;     // Grow (or shrink) vector 'x' positions
} svector;

// Allocate and zero initialize vector
int svector_set(svector *cvector, size_t initial_length);

// Append data into vector and resize it if necessary
int svector_add(svector *cvector, char *element);

// Concatenate string with vector and resize it if necessary
// void concatStrVector(svector *destination, char *source);

// Clear and reset vector
void svector_clear(svector *cvector);

// Deallocate vector
void svector_free(svector *cvector);

#endif // SVECTOR_H_INCLUDED
