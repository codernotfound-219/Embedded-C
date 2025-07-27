#include <stdint.h>
#include <stdio.h>

int reverse(int n) {
  int32_t max = INT32_MAX;
  int32_t min = INT32_MIN;

  int res = 0;
  while (n) {
    int digit = n % 10;
    n /= 10;

    if (res > max / 10 || (res == max / 10 && digit > max%10)) return 0;
    if (res < min / 10 || (res == min / 10 && digit > min%10)) return 0;
    res = (res * 10) + digit;
  }

  return res;
}

int main() {
  if (reverse(1235) != 5321) {
    printf("FAILED");
    return 1;
  }
  if (reverse(-1235) != -5321) {
    printf("FAILED");
    return 1;
  }
  if (reverse(1234236467) != 0) {
    printf("FAILED");
    return 1;
  }

  printf("PASSED");
  return 0;
}
