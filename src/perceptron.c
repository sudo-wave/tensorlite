#include "perceptron.h"

float forward_diff(float (*f)(float), float x, float eps) {
  return ((*f)(x + eps) - (*f)(x)) / eps;
}

float backward_diff(float (*f)(float), float x, float eps) {
  return ((*f)(x) - (*f)(x - eps)) / eps;
}

vector init_weights(size_t dim, float mult) {
  vector w = vec_alloc(dim);
  for (size_t i = 0; i < dim; i++) {
    float val = rnd_weight() * mult;
    vec_set(&w, i, val);
  }
  return w;
}

float grad_descent(float w, float rate, float eps) { return w; }

float sgd(vector weights, float rate, float eps);

float perceptron(int *data[][3], vector weights, float rate, float eps) {
  vector train_x1 = vec_alloc(4);
  for (size_t i = 0; i < 4; i++) {
    vec_set(&train_x1, i, *data[i][0]);
  }
  vector train_x2 = vec_alloc(4);
  for (size_t i = 0; i < 4; i++) {
    vec_set(&train_x2, i, *data[i][1]);
  }
  vector train_y = vec_alloc(4);
  for (size_t i = 0; i < 4; i++) {
    vec_set(&train_y, i, *data[i][2]);
  }
  printf("Train x1: ");
  vec_print(&train_x1);
  printf("Train x2: ");
  vec_print(&train_x2);
  printf("Train y: ");
  vec_print(&train_y);
  return 0;
}
