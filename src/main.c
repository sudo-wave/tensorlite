#include "matrix.h"
#include "random.h"

int main() {
  matrix m1 = mat_bernoulli(3, 3, 0.5);
  matrix m2 = mat_uniform(3, 3, 0, 100);
  /*mat_scale(&m1, 2);*/
  /*mat_scale(&m2, 4);*/
  printf("Matrix 1:\n");
  mat_print(&m1);
  printf("Matrix 2:\n");
  mat_print(&m2);
  /*matrix m3 = mat_mult(&m1, &m2);*/
  /*mat_print(&m3);*/
  return 0;
}
