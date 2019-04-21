#ifndef SVECTOR_H_INCLUDED
#define SVECTOR_H_INCLUDED

//#ifdef BUILD_DLL
//#define EXPORT __declspec(dllexport)
//#else
//#define EXPORT __declspec(dllimport)
//#endif

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
    size_t resize_rate;     // Grow (or shrink) vector in 'x' positions
} svector;

// Allocate and zero initialize vector
int setStrVector(svector *cvector, size_t initial_length);

// Append character into vector and resize it if necessary
int appendStrVector(svector *cvector, char *element);

// Concatenate string with vector and resize it if necessary
//EXPORT void __stdcall concatStrVector(svector *destination, char *source);

// Clear and reset vector
void clearStrVector(svector *cvector);

// Print vector data
//EXPORT void __stdcall showStrVector(svector *cvector);

// Clear and deallocate vector
void freeStrVector(svector *cvector);

#endif // SVECTOR_H_INCLUDED
