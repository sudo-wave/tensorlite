#include "perceptron.h"

int main() {
  srand(time(0));
  vector w = init_weights(3, 10);
  printf("Weights: ");
  vec_print(&w);
  return 0;
}
