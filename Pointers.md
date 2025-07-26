# Dynamic Allocation Example : Traversing Array
```C
#include <stdio.h>

int main() {
	int *arr;
	int n =5;

	arr = (int *)malloc(n * sizeof(int));
	if (arr == NULL) {
		printf("Memory Allocation Failed!");
		return 1;
	}
	
	for (int i = 0;i < n;i++) {
		*(arr+i) = i+1;
	}

	for (int i =0 ; i < n; i++) {
		printf("Element: %d, %d\n", i, *(arr+i));
	}

	free(arr);
	return 0;
}
```

# Function pointer
```C
void add(int a1, int a2) {
	return a1+a2;
}
void sub(int a, int b) {
	return a -b;
}

int (* operation)(int, int);

int main() {
	int a = 5, b =3;
	operation = add;
	printf("Addition: %d", operation(a, b));
	operation=sub;
	printf("Subtraction: %d", operation(a, b));
	return 0;
}
```