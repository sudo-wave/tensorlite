#ifndef RANDOM_H

#include <math.h>
#include <stdlib.h>
#include <time.h>

float rnd_bernoulli(float p);
float rnd_uniform(int lo, int hi);
float rnd_normal(float exp, float var);

#endif // !RANDOM_H
