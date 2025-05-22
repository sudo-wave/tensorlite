#include "perceptron.h"

float difference(float (*f)(float), float x, float eps) {
  return (f(x + (eps / 2)) - f(x - (eps / 2))) / eps;
}

vector init_weights(size_t dim, float mult) {
  vector w = vec_zeros(dim);
  for (size_t i = 0; i < dim; i++) {
    float val = rnd_weight() * mult;
    vec_set(w, i, val);
  }
  return w;
}

float perceptron_or_gate(vector weights, float rate, float eps) {
  float OR_GATE[][3] = {
      {0.0, 0.0, 0.0},
      {1.0, 0.0, 1.0},
      {0.0, 1.0, 1.0},
      {1.0, 1.0, 1.0},
  };
  vector train_x1 = vec_zeros(4);
  for (size_t i = 0; i < 4; i++) {
    vec_set(train_x1, i, OR_GATE[i][0]);
  }
  vector train_x2 = vec_zeros(4);
  for (size_t i = 0; i < 4; i++) {
    vec_set(train_x2, i, OR_GATE[i][1]);
  }
  vector train_y = vec_zeros(4);
  for (size_t i = 0; i < 4; i++) {
    vec_set(train_y, i, OR_GATE[i][2]);
  }
  printf("Train x1: ");
  vec_print(train_x1);
  printf("Train x2: ");
  vec_print(train_x2);
  printf("Train y: ");
  vec_print(train_y);
  return 0;
}
