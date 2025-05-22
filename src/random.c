#include "random.h"

float rnd_bernoulli(float p) {
  float q = (float)rand() / (float)RAND_MAX;
  if (q <= p) {
    return 1.0;
  }
  return 0.0;
}

float rnd_uniform(int lo, int hi) { return (rand() % (hi - lo + 1)) + lo; }

float rnd_normal(float exp, float var);

float rnd_weight() { return (float)rand() / (float)RAND_MAX; }
