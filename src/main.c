#include "random.h"
#include "vector.h"

int main() {
  srand(time(NULL));
  float res = rnd_uniform(0, 10);
  printf("%f\n", res);
  return 0;
}
