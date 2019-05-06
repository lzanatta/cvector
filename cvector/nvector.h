#ifndef NVECTOR_H_INCLUDED
#define NVECTOR_H_INCLUDED

#define NV_INITIAL_SIZE     4
#define NV_MAX_SIZE         128
#define NV_GROWTH_FACTOR    2

// svector struct for a dynamically sized array of numbers
typedef struct cvector {
    unsigned int *data;     // Vector data
    size_t index;           // Data index
    size_t length;          // Vector length
    size_t max_length;      // Maximum length
    size_t resize_rate;     // Grow (or shrink) vector 'x' positions
    size_t print_index;     // Another index for printing only
} nvector;

// Allocate and zero initialize vector
int nvector_init(nvector *cvector, size_t initial_length);

// Append data into vector and resize it if necessary
int nvector_add(nvector *cvector, unsigned int *element);

// Print vector in the terminal
// void showNumVector(nvector *cvector, int i);

// Clear and reset vector
void nvector_clear();

// Deallocate vector
void nvector_free(nvector *cvector);

#endif // NVECTOR_H_INCLUDED
