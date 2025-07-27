#include <stdio.h>

int get_diff(int a, int b) {
  while (b != 0) {
    int borrow = (~a & b) << 1;
    a ^= b;
    b = borrow;
  }

  return a;
}

int main(void) {
  if (get_diff(3, 5) != -2) {
    printf("FAILED");
    return 1;
  }

  if (get_diff(1, 8) != -7) {
    printf("FAILED");
    return 1;
  }

  if (get_diff(7, 5) != 2) {
    printf("FAILED");
    return 1;
  }

  printf("PASSED");
  return 0;
}
