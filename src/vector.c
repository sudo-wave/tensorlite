#include "vector.h"

vector vec_alloc(size_t d) {
  vector v;
  v.dim = d;
  v.data = malloc(sizeof(*v.data) * d);
  return v;
}

void vec_free(vector *v) {
  free(v->data);
  v->dim = 0;
  v->data = NULL;
}

void vec_print(vector *v) {
  for (size_t i = 0; i < v->dim; i++) {
    printf("%f ", v->data[i]);
  }
  printf("\n");
}

vector vec_ones(size_t d) {
  vector v = vec_alloc(d);
  for (size_t i = 0; i < v.dim; i++) {
    vec_set(&v, i, 1);
  }
  return v;
}

float vec_get(vector *v, size_t idx) { return v->data[idx]; }

void vec_set(vector *v, size_t idx, float val) { v->data[idx] = val; }

void vec_scale(vector *v, float s) {
  for (size_t i = 0; i < v->dim; i++) {
    v->data[i] = v->data[i] * s;
  }
}

void vec_add(vector *v, vector *u) {
  for (size_t i = 0; i < v->dim; i++) {
    v->data[i] = v->data[i] + u->data[i];
  }
}

void vec_sub(vector *v, vector *u) {
  for (size_t i = 0; i < v->dim; i++) {
    v->data[i] = v->data[i] - v->data[i];
  }
}

float vec_dot(vector *v, vector *u) {
  float res = 0;
  for (size_t i = 0; i < v->dim; i++) {
    res += v->data[i] * u->data[i];
  }
  return res;
}
