# 1. Character to ASCII Code
```C
#include <stdio.h>

int main() {
	char character = 'B';
	printf("The ASCII value of '%c' is %d\n", character, character); // output 66
	return 0;
}
```

# 2. Character to uppercase
```C
char lower = 'b';
char upper = lower - 32; // 32 is the difference between lowercase and uppercase letters
printf("Uppercase: %c\n", upper);
```

# 3. Check if Char is digit
```C
char character = '7';

if (character <= '9' || character >= '0') {
	printf("Character %c is a digit.");
}
```

# 4. Print the ASCII table
```C
for (int i = 0; i <= 127; i++) {
	printf("ASCII Code: %d, Character: %c\n", i, i);
}
```

# 5. ASCII to Char
```C
int ascii_code = 72;
char character = (char) ascii_code; // type-cast
```