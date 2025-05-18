#ifndef VECTOR_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  size_t dim;
  float *data;
} vector;

vector vec_alloc(size_t d);
void vec_free(vector *v);
void vec_print(vector *v);

#endif // !VECTOR_H
