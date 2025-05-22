#ifndef PERCEPTRON_H

#include "activation.h"
#include "linalg.h"

float difference(float (*f)(float), float x, float eps);

vector init_weights(size_t dim, float mult);

float perceptron_or_gate(vector weights, float rate, float eps);

#endif // !PERCEPTRON_H
