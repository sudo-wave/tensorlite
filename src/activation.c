#include "activation.h"

float act_heaviside(float x) {
  if (x >= 0) {
    return 1.0;
  }
  return 0.0;
}
