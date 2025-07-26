#include <stdio.h>

int main() {
  int a =5;  // binary: 0000000000000101
  int result = ~5; //  result is 1111111111111010, its value is 2's complement which is -6 (reason: msb is 1 -> negative)
  printf("result: %d\n", result);
  return 0;
}
