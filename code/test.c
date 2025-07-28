#include <stdio.h>

int main() {
  float x=7.5, j=-1.0, n=1.0, m=2.0;
  float ans = --x + j == x>n >= m;
  printf("value: %f", ans);
  return 0;
}
