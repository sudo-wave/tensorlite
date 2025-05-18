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

vector vec_ones(size_t d);

float vec_get(vector *v, size_t idx);
void vec_set(vector *v, size_t idx, float val);

void vec_scale(vector *v, float s);
void vec_add(vector *v, vector *u);
void vec_sub(vector *v, vector *u);
float vec_dot(vector *v, vector *u);

#endif // !VECTOR_H
