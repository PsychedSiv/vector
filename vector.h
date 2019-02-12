#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

// forward declare strucs and bring them from the tag namespace to the ordinary namespace
typedef struct Vector Vector;

// actually define the structs
struct Vector{
	size_t elements;
	size_t size;
	void **itemBuffer;
};

// Initialize a vector to be empty
// Pre: 'vector' != NULL
void Vector_ctor(Vector *vector);

// Deallocate internal structures of the vector
// Note: the user is responsible for deleting all values
// Note: the user is responsible for deleting the actual vector if it was dynamically allocated
void Vector_dtor(Vector *vector);

// Insert a new element at the end of the vector
// Pre: 'vector' != NULL
void Vector_push_back(Vector *vector, void *value);

// Remove the last element in the vector.
// Pre: vector != NULL && Vector_size(v) > 0
void *Vector_pop_back(Vector *vector);

// Return the number of elements in the vector
// Pre: 'vector' != NULL
size_t Vector_size(const Vector *vector);

// Return the current capacity of the vector
// Pre: 'vector' != NULL
size_t Vector_capacity(const Vector *vector);

// Return the value at the given index
// Pre: v != NULL && index < vector_size(vector)
void *Vector_get(const Vector *vector, size_t index);

// Return a pointer to the underlying array
void **Vector_data(const Vector *vector);

#endif
