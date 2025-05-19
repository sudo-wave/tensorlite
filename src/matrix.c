#include "matrix.h"

matrix mat_alloc(size_t ro, size_t co) {
  matrix m;
  m.row = ro;
  m.col = co;
  m.dim = ro * co;
  m.data = malloc(sizeof(*m.data) * ro * co);
  return m;
}

void mat_free(matrix *a) {
  free(a->data);
  a->row = 0;
  a->col = 0;
  a->dim = 0;
  a->data = NULL;
}

float mat_get(matrix *a, size_t ro, size_t co) {
  return a->data[ro * a->col + co];
}

void mat_set(matrix *a, size_t ro, size_t co, float val) {
  a->data[ro * a->col + co] = val;
}

vector mat_get_col(matrix *a, size_t co) {
  vector v = vec_alloc(a->row);
  for (size_t i = 0; i < a->row; i++) {
    vec_set(&v, i, mat_get(a, i, co));
  }
  return v;
}

vector mat_get_row(matrix *a, size_t ro) {
  vector v = vec_alloc(a->col);
  for (size_t i = 0; i < a->col; i++) {
    vec_set(&v, i, mat_get(a, ro, i));
  }
  return v;
}

matrix mat_ident(size_t d) {
  matrix a = mat_alloc(d, d);
  for (size_t i = 0; i < a.row; i++) {
    for (size_t j = 0; j < a.col; j++) {
      if (i == j) {
        mat_set(&a, i, j, 1);
      }
    }
  }
  return a;
}

matrix mat_bernoulli(size_t ro, size_t co, float p) {
  matrix a = mat_alloc(ro, co);
  for (size_t i = 0; i < a.row; i++) {
    for (size_t j = 0; j < a.col; j++) {
      mat_set(&a, i, j, rnd_bernoulli(p));
    }
  }
  return a;
}

matrix mat_uniform(size_t ro, size_t co, float lo, float hi) {
  matrix a = mat_alloc(ro, co);
  for (size_t i = 0; i < a.row; i++) {
    for (size_t j = 0; j < a.col; j++) {
      mat_set(&a, i, j, rnd_uniform(lo, hi));
    }
  }
  return a;
}

void mat_print(matrix *a) {
  for (size_t i = 0; i < a->row; i++) {
    for (size_t j = 0; j < a->col; j++) {
      printf("%f ", mat_get(a, i, j));
    }
    printf("\n");
  }
}

void mat_scale(matrix *a, float s) {
  for (size_t i = 0; i < a->row; i++) {
    for (size_t j = 0; j < a->col; j++) {
      float val = mat_get(a, i, j);
      mat_set(a, i, j, s * val);
    }
  }
}

void mat_add(matrix *a, matrix *b) {
  for (size_t i = 0; i < a->row; i++) {
    for (size_t j = 0; j < a->col; j++) {
      float a_val = mat_get(a, i, j);
      float b_val = mat_get(a, i, j);
      mat_set(a, i, j, a_val + b_val);
    }
  }
}

void mat_sub(matrix *a, matrix *b) {
  for (size_t i = 0; i < a->row; i++) {
    for (size_t j = 0; j < a->col; j++) {
      float a_val = mat_get(a, i, j);
      float b_val = mat_get(a, i, j);
      mat_set(a, i, j, a_val - b_val);
    }
  }
}

matrix mat_mult(matrix *a, matrix *b) {
  matrix c = mat_alloc(a->row, b->col);
  for (size_t i = 0; i < a->row; i++) {
    vector v = mat_get_row(a, i);
    for (size_t j = 0; j < b->col; j++) {
      vector u = mat_get_col(b, j);
      float tot = vec_dot(&v, &u);
      mat_set(&c, i, j, tot);
    }
  }
  return c;
}
