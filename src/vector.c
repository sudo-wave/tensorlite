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
