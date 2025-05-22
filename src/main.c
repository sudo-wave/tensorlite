#include "perceptron.h"

int main() {
  srand(10);
  vector v1 = vec_unif(3, 1, 100);
  vector v2 = vec_bern(3, 0.5);
  vec_print(v1);
  matrix m1 = mat_unif(3, 3, 1, 100);
  matrix m2 = mat_bern(3, 3, 0.5);
  mat_print(m2);
  vector res1 = vec_mat_mult(v2, m1);
  vector res2 = mat_vec_mult(m2, v1);
  vec_print(res2);

  vector w = init_weights(4, 10);

  float res = perceptron_or_gate(w, 1e-3, 1e-3);
  return 0;
}
