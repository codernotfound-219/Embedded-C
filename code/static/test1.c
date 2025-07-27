#include <stdio.h>

int count;

void increment(void) {
  count++;
	printf("Value of Count: %d\n", count);
}

int main() {
  increment();
  increment();
  increment();
  increment();
  increment();

  return 0;
}
