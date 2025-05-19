#include "random.h"

float bernoulli(float p) {
  float q = (double)rand() / (double)RAND_MAX;
  if (q <= p) {
    return 1.0;
  }
  return 0.0;
}
