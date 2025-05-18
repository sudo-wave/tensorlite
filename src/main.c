#include "vector.h"

int main() {
  vector v = vec_ones(5);
  vector u = vec_ones(5);
  vec_print(&v);
  vec_scale(&v, 2);
  vec_scale(&u, 3);
  vec_print(&v);
  vec_add(&v, &u);
  vec_print(&v);
  vec_sub(&v, &v);
  vec_print(&v);
  return 0;
}
