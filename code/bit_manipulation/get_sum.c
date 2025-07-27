#include <stdio.h>

// Add without '+'
int get_sum(int a, int b) {
  while (b != 0) {
    int carry = (a&b) << 1;
    a ^= b;
    b = carry;
  }

  return a;
}

int main(void) {
  if (get_sum(4, 3) != 7) {
    printf("FAILED");
    return 1;
  }

  if (get_sum(6, 5) != 11) {
    printf("FAILED");
    return 1;
  }

  if (get_sum(2, 1) != 3) {
    printf("FAILED");
    return 1;
  }

  printf("PASSED");
  return 0;
}
