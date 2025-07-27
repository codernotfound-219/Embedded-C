#include <stdint.h>
#include <stdio.h>

int count_bits(uint32_t n) {
  int res = 0;
  while (n) {
    n &= n-1;
    res++;
  }
  return res;
}

int main(void) {
  if (count_bits(5) != 2) {
    printf("Failed");
    return 1;
  }
  if (count_bits(8) != 1) {
    printf("Failed");
    return 1;
  }
  if (count_bits(15) != 4) {
    printf("Failed");
    return 1;
  }

  printf("PASSED");
  return 0;
}
