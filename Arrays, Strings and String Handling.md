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
strcat(sentence, ", World!"); // sentence = "Hello, World!"


// STRCMP - compare lexicographically
int result = strcmp("apple", "orange");   // returns a negative value as apple < orange

// STRCHR - finds the first occurence of a character in the string.
char *ptr = strchr(greeting, 'W'); // return pointer to "World!"

// STRSTR - finds the first occurence of a substring
char *substr = str
```