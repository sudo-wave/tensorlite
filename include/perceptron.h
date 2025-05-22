#ifndef PERCEPTRON_H

#include "activation.h"
#include "matrix.h"

float forward_diff(float (*f)(float), float x, float eps);

float backward_diff(float (*f)(float), float x, float eps);

vector init_weights(size_t dim, float mult);

float grad_descent(float w, float rate, float eps);

float sgd(vector weights, float rate, float eps);

float perceptron(int *data[4][3], vector weights, float rate, float eps);

#endif // !PERCEPTRON_H
