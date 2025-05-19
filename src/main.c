#include "matrix.h"
#include "random.h"

int main() {
  matrix m1 = mat_ident(3);
  matrix m2 = mat_ident(3);
  mat_scale(&m1, 2);
  mat_scale(&m2, 4);
  mat_print(&m1);
  mat_print(&m2);
  matrix m3 = mat_mult(&m1, &m2);
  mat_print(&m3);
  return 0;
}
