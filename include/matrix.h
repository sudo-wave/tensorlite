#ifndef MATRIX_H

#include "random.h"
#include "vector.h"

typedef struct {
  size_t row;
  size_t col;
  size_t dim;
  float *data;
} matrix;

matrix mat_alloc(size_t ro, size_t co);
void mat_free(matrix *a);

float mat_get(matrix *a, size_t ro, size_t co);
void mat_set(matrix *a, size_t ro, size_t co, float val);

vector mat_get_col(matrix *a, size_t co);
vector mat_get_row(matrix *a, size_t ro);

void mat_print(matrix *a);
matrix mat_ident(size_t d);
matrix mat_bernoulli(size_t ro, size_t co, float p);

void mat_scale(matrix *a, float s);
void mat_add(matrix *a, matrix *b);
void mat_sub(matrix *a, matrix *b);
matrix mat_mult(matrix *a, matrix *b);

#endif // !MATRIX_H
