# 1. Array:
Initialization
```C
int numbers[5];

int numbers[5] = {1, 2, 3, 4, 5};
int matrix[5][5];

int matrix[5][5] = {
	{1,2,3,4,5},
	{1,2,3,4,5},
	{1,2,3,4,5},
	{1,2,3,4,5},
	{1,2,3,4,5},
};

// U can have 3d array too... tetrix[5][5][5];
```

**LIMITATIONS:**
1. The size of array must be known at compile time.
2. Manually ensure out-of-bounds does not occur.

# 2. Strings
Initialization
```C
char greeting[] = "Hello, World!";
char name[20] = "Alexa"; // fixed size
```

Common functions
```C
#include <string.h>

// STRLEN
size_t length = strlen(greeting);
char copy[20];

// STRCPY
strcpy(copy, name);

// STRCAT - concatenation
char sentence[40] = "Hello";
strcat(sentence, ", World!");             // sentence = "Hello, World!"


// STRCMP - compare lexicographically
int result = strcmp("apple", "orange");   // returns a negative value as apple < orange

// STRCHR - finds the first occurence of a character in the string.
char *ptr = strchr(greeting, 'W');        // return pointer to "World!"

// STRSTR - finds the first occurence of a substring
char *substr = strstr(greeting, "World"); // Returns pointer to "World!";
```

# 3. Literals vs Character Array

- String literals are those that are constant.
```C
const char *str = "This is a string literal.";
```

**Storage**: Memory

# 4. Memory Management

- Each string is a character array with the last character being a null character '\0'; (its a zero not 'o')
- This character marks the termination of the string and is the reason why C doesn't store the size of the string beforehand.

# 5. Pitfalls
## 1. Null-Termination
```C
char incompleteString[6] = {'H', 'e', 'l', 'l', 'o'}; // string is read beyond memory (missing \0) 

// RIGHT-WAY
char completeString[6] = {'H', 'e', 'l', 'l', 'o', '\0'}; 
char completeString[6] = "Hello"; // auto-adds \0
```

## 2. Buffer Overflow
```C
char src[20] = "This is a long string";
char dest[10];

strcpy(dest, src); // buffer overflow
```
fix:
```C
strncopy(dest, src, sizeof(dest) - 1)
dest[sizeof(dest) - 1] = '\0'
```