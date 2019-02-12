#include <stdio.h>
#include "vector.h"

void Vector_ctor(Vector *vector){
	vector->elements = 0;
	vector->size = 10;
	vector->itemBuffer = malloc(sizeof(void*) * vector->size);
}

void Vector_dtor(Vector *vector){
	free(vector->itemBuffer);
}

// push value to vector, double vector size if filled, and double capacity
// Insert pointer to last element of vector and increment size by one
void Vector_push_back(Vector *vector, void *value){
	if(vector->elements == vector->size){
		void **newItemBuffer = realloc(vector->itemBuffer, sizeof(void *) * (vector->size*2));
		vector->itemBuffer = newItemBuffer;
		vector->size = vector->size*2;
	}
	vector->itemBuffer[vector->elements++] = value;
}

void *Vector_pop_back(Vector *vector){
	void *result = vector->itemBuffer[vector->elements-1];
	vector->itemBuffer[--vector->elements] = NULL;
	return result;
}

// const infront, mean that we only read from the parameters,
// and we do not write. 
size_t Vector_size(const Vector *vector){
	return vector->elements;
}

size_t Vector_capacity(const Vector *vector){
	return vector->size;
}

void *Vector_get(const Vector *vector, size_t index){
	return vector->itemBuffer[index];
}

void **Vector_data(const Vector *vector){
	return vector->itemBuffer;
}
