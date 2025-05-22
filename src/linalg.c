#include "linalg.h"

static vector vec_alloc(size_t dim) {
  vector vec;
  vec.dim = dim;
  vec.data = malloc(sizeof(*vec.data) * dim);
  return vec;
}

static void vec_free(vector vec) {
  free(vec.data);
  vec.dim = 0;
  vec.data = NULL;
}

float vec_get(vector vec, size_t idx) { return vec.data[idx]; }

void vec_set(vector vec, size_t idx, float val) { vec.data[idx] = val; }

vector vec_zeros(size_t dim) {
  vector vec = vec_alloc(dim);
  for (size_t i = 0; i < vec.dim; i++) {
    vec_set(vec, i, 0.0);
  }
  return vec;
}

vector vec_ones(size_t dim) {
  vector vec = vec_alloc(dim);
  for (size_t i = 0; i < vec.dim; i++) {
    vec_set(vec, i, 1.0);
  }
  return vec;
}

vector vec_bern(size_t dim, float p) {
  vector vec = vec_alloc(dim);
  for (size_t i = 0; i < vec.dim; i++) {
    int val = rnd_bernoulli(p);
    vec_set(vec, i, val);
  }
  return vec;
}

vector vec_unif(size_t dim, int lo, int hi) {
  vector vec = vec_alloc(dim);
  for (size_t i = 0; i < vec.dim; i++) {
    float val = rnd_uniform(lo, hi);
    vec_set(vec, i, val);
  }
  return vec;
}

void vec_print(vector vec) {
  for (size_t i = 0; i < vec.dim; i++) {
    printf("%f ", vec.data[i]);
  }
  printf("\n");
}

void vec_scale(vector vec, float sca) {
  for (size_t i = 0; i < vec.dim; i++) {
    vec_set(vec, i, vec_get(vec, i) * sca);
  }
}

void vec_add(vector vec1, vector vec2) {
  for (size_t i = 0; i < vec1.dim; i++) {
    vec_set(vec1, i, vec_get(vec1, i) + vec_get(vec2, i));
  }
}

void vec_sub(vector vec1, vector vec2) {
  for (size_t i = 0; i < vec1.dim; i++) {
    vec_set(vec1, i, vec_get(vec1, i) - vec_get(vec2, i));
  }
}

float vec_dot(vector vec1, vector vec2) {
  float tot = 0;
  for (size_t i = 0; i < vec1.dim; i++) {
    tot += vec_get(vec1, i) * vec_get(vec2, i);
  }
  return tot;
}

static matrix mat_alloc(size_t row, size_t col) {
  matrix mat;
  mat.row = row;
  mat.col = col;
  mat.dim = row * col;
  mat.data = malloc(sizeof(*mat.data) * row * col);
  return mat;
}

static void mat_free(matrix mat) {
  free(mat.data);
  mat.row = 0;
  mat.col = 0;
  mat.dim = 0;
  mat.data = NULL;
}

float mat_get(matrix mat, size_t row, size_t col) {
  return mat.data[row * mat.col + col];
}

void mat_set(matrix mat, size_t row, size_t col, float val) {
  mat.data[row * mat.col + col] = val;
}

vector mat_get_row(matrix mat, size_t row) {
  vector vec = vec_alloc(mat.col);
  for (size_t i = 0; i < mat.col; i++) {
    vec_set(vec, i, mat_get(mat, row, i));
  }
  return vec;
}

vector mat_get_col(matrix mat, size_t col) {
  vector vec = vec_alloc(mat.row);
  for (size_t i = 0; i < mat.row; i++) {
    vec_set(vec, i, mat_get(mat, i, col));
  }
  return vec;
}

matrix mat_zeros(size_t row, size_t col) {
  matrix mat = mat_alloc(row, col);
  for (size_t i = 0; i < mat.row; i++) {
    for (size_t j = 0; j < mat.col; j++) {
      mat_set(mat, i, j, 0.0);
    }
  }
  return mat;
}

matrix mat_ones(size_t row, size_t col) {
  matrix mat = mat_alloc(row, col);
  for (size_t i = 0; i < mat.row; i++) {
    for (size_t j = 0; j < mat.col; j++) {
      mat_set(mat, i, j, 1.0);
    }
  }
  return mat;
}

matrix mat_bern(size_t row, size_t col, float p) {
  matrix mat = mat_alloc(row, col);
  for (size_t i = 0; i < mat.row; i++) {
    for (size_t j = 0; j < mat.col; j++) {
      float val = rnd_bernoulli(p);
      mat_set(mat, i, j, val);
    }
  }
  return mat;
}

matrix mat_unif(size_t row, size_t col, int lo, int hi) {
  matrix mat = mat_alloc(row, col);
  for (size_t i = 0; i < mat.row; i++) {
    for (size_t j = 0; j < mat.col; j++) {
      float val = rnd_uniform(lo, hi);
      mat_set(mat, i, j, val);
    }
  }
  return mat;
}

void mat_print(matrix mat) {
  for (size_t i = 0; i < mat.row; i++) {
    for (size_t j = 0; j < mat.col; j++) {
      printf("%f ", mat_get(mat, i, j));
    }
    printf("\n");
  }
}

void mat_scale(matrix mat, float sca) {
  for (size_t i = 0; i < mat.row; i++) {
    for (size_t j = 0; j < mat.col; j++) {
      float val = mat_get(mat, i, j);
      mat_set(mat, i, j, sca * val);
    }
  }
}

void mat_add(matrix mat1, matrix mat2) {
  for (size_t i = 0; i < mat1.row; i++) {
    for (size_t j = 0; j < mat1.col; j++) {
      float val1 = mat_get(mat1, i, j);
      float val2 = mat_get(mat2, i, j);
      mat_set(mat1, i, j, val1 + val2);
    }
  }
}

void mat_sub(matrix mat1, matrix mat2) {
  for (size_t i = 0; i < mat1.row; i++) {
    for (size_t j = 0; j < mat1.col; j++) {
      float val1 = mat_get(mat1, i, j);
      float val2 = mat_get(mat2, i, j);
      mat_set(mat1, i, j, val1 - val2);
    }
  }
}

matrix mat_mult(matrix mat1, matrix mat2) {
  matrix mat3 = mat_alloc(mat1.row, mat2.col);
  for (size_t i = 0; i < mat1.row; i++) {
    vector vec1 = mat_get_row(mat1, i);
    for (size_t j = 0; j < mat2.col; j++) {
      vector vec2 = mat_get_col(mat2, j);
      float tot = vec_dot(vec1, vec2);
      mat_set(mat3, i, j, tot);
    }
  }
  return mat3;
}

vector vec_mat_mult(vector vec, matrix mat) {
  vector ret = vec_alloc(mat.col);
  for (size_t i = 0; i < ret.dim; i++) {
    float val = vec_dot(vec, mat_get_col(mat, i));
    vec_set(ret, i, val);
  }
  return ret;
}

vector mat_vec_mult(matrix mat, vector vec) {
  vector ret = vec_alloc(mat.row);
  for (size_t i = 0; i < ret.dim; i++) {
    float val = vec_dot(mat_get_row(mat, i), vec);
    vec_set(ret, i, val);
  }
  return ret;
}
