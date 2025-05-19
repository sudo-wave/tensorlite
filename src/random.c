#include "random.h"

float rnd_bernoulli(float p) {
  float q = (double)rand() / (double)RAND_MAX;
  if (q <= p) {
    return 1.0;
  }
  return 0.0;
}

float rnd_uniform(int lo, int hi) { return (rand() % (hi - lo + 1)) + lo; }

float rnd_normal(float exp, float var) {
  float u1 = rnd_uniform(0, 1);
  float u2 = rnd_uniform(0, 1);
  float z0 = sqrt(-2 * log(u1)) * cos(2 * M_PI * u2);
  float z1 = sqrt(-2 * log(u1)) * sin(2 * M_PI * u2);
  return z0;
}
