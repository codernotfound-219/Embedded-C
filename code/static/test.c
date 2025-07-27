#include <stdio.h>

void increment(void) {
	static int count = 0;
	count++;
	printf("Value of Count: %d\n", count);
}

int main(void) {
	increment();
	increment();
	increment();
	increment();
	increment();
	return 0;
}
