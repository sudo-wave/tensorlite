#ifndef LINALG_H
#define LINALG_H

#include "random.h"
#include <stdio.h>

typedef struct {
  size_t dim;
  float *data;
} vector;

static vector vec_alloc(size_t dim);

static void vec_free(vector vec);

float vec_get(vector vec, size_t idx);

void vec_set(vector vec, size_t idx, float val);

vector vec_zeros(size_t dim);

vector vec_ones(size_t dim);

vector vec_bern(size_t dim, float p);

vector vec_unif(size_t dim, int lo, int hi);

void vec_print(vector vec);

void vec_scale(vector vec, float sca);

void vec_add(vector vec1, vector vec2);

void vec_sub(vector vec1, vector vec2);

float vec_dot(vector vec1, vector vec2);

typedef struct {
  size_t row;
  size_t col;
  size_t dim;
  float *data;
} matrix;

static matrix mat_alloc(size_t row, size_t col);

static void mat_free(matrix mat);

float mat_get(matrix mat, size_t row, size_t col);

void mat_set(matrix mat, size_t row, size_t col, float val);

vector mat_get_row(matrix mat, size_t row);

vector mat_get_col(matrix mat, size_t col);

matrix mat_zeros(size_t row, size_t col);

matrix mat_ones(size_t row, size_t col);

matrix mat_bern(size_t row, size_t col, float p);

matrix mat_unif(size_t row, size_t col, int lo, int hi);

void mat_print(matrix mat);

void mat_scale(matrix mat, float sca);

void mat_add(matrix mat1, matrix mat2);

void mat_sub(matrix mat1, matrix mat2);

matrix mat_mult(matrix mat1, matrix mat2);

/*
 * Row vector x Matrix
 */

vector vec_mat_mult(vector vec, matrix mat);

/*
 * Matrix x Column vector
 */

vector mat_vec_mult(matrix mat, vector vec);

#endif // !LINALG_H
