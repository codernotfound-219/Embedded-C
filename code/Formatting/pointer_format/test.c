#include <stdio.h>

int main() {
  int x = 5;
  int const *ptr = &x;
  printf("pointer: %p\n", ptr);
  return 0;
}
