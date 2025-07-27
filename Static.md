```C
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

output:
Value of Count: 1
Value of Count: 2
Value of Count: 3
Value of Count: 4
Value of Count: 5
```
Equivalent:
```C
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
```

**Advantage:**
1. in the first case, the var `count` is scoped to the function `increment()`.