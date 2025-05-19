#include "random.h"
#include "vector.h"

int main() {
  float val;
  for (int i = 0; i < 50; i++) {
    val = bernoulli(0.5);
    printf("Trial #%d: %f\n", i, val);
  }
  return 0;
}
