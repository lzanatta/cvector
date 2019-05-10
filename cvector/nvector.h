#ifndef NVECTOR_H_INCLUDED
#define NVECTOR_H_INCLUDED

#define NV_INITIAL_LENGTH_ONE   64
#define NV_MAX_LENGTH_ONE       1024
#define NV_RESIZE_RATE_ONE      32

#define NV_INITIAL_LENGTH_TWO   512
#define NV_MAX_LENGTH_TWO       8192
#define NV_RESIZE_RATE_TWO      256

#define NV_CAP_ERROR            -2
#define NV_CAP_ERROR_VERBOSE    "nvector maximum size reached"
#define NV_ALLOC_ERROR          -1
#define NV_ALLOC_ERROR_VERBOSE  "nvector allocation error"

// svector struct for a dynamically sized array of numbers
typedef struct nvector {
    unsigned int *data;     // Vector data
    size_t index;           // Data index
    size_t length;          // Vector length
    size_t max_length;      // Maximum length
    size_t resize_rate;     // Grow (or shrink) vector 'x' positions
    size_t print_index;     // Another index for printing only
} nvector;

// Allocate and zero initialize vector
int nvector_set(nvector *cvector, size_t initial_length);

// Append data into vector and resize it if necessary
int nvector_add(nvector *cvector, unsigned int *element);

// Print vector in the terminal
// void showNumVector(nvector *cvector, int i);

// Clear and reset vector
void nvector_clear();

// Deallocate vector
void nvector_free(nvector *cvector);

#endif // NVECTOR_H_INCLUDED
