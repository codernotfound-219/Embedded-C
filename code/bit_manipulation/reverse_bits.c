#include <stdint.h>
#include <stdio.h>

uint32_t reverse_bit(uint32_t n) {
  uint32_t res = 0;
  for (int i = 0; i<32; i++) {
    uint32_t bit = (n >> i) & 1;
    res += bit << (31-i);
  }

  return res;
}

int main(void) {
  if (reverse_bit(21) != 2818572288) {
    printf("FAILED");
    return 1;
  }

  printf("PASSED");
  return 0;
}
