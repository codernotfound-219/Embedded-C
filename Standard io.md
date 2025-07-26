# Format Specifiers
## Integer Format
- **`%d`** or **`%i`**: Signed integer (decimal)
    - **Example**: `printf("%d", -45);` will output `-45`.
	
- **`%u`**: Unsigned integer (decimal)
    - **Example**: `printf("%u", 45);` will output `45`.
	
- **`%x`** or **`%X`**: Unsigned integer (hexadecimal, lowercase/uppercase)
    - **Example**: `printf("%x", 255);` will output `ff`, and `printf("%X", 255);` will output `FF`.
	
- **`%o`**: Unsigned integer (octal)
    - **Example**: `printf("%o", 8);` will output `10`.

## Floating Point Format
- **`%f`**: Floating-point number (default precision is 6 decimal places)
    - **Example**: `printf("%f", 3.14159);` will output `3.141590`.
	
- **`%e`** or **`%E`**: Floating-point number (scientific notation, lowercase/uppercase)
    - **Example**: `printf("%e", 12345.678);` will output `1.234568e+04` (scientific notation).
	
- **`%g`** or **`%G`**: Floating-point number (either `f` or `e` format, depending on the number)
    - **Example**: `printf("%g", 0.00012345);` will output `1.2345e-04`.

## String Format
- **`%s`**: String
    - **Example**: `printf("%s", "Hello World");` will output `Hello World`.
	
- **`%c`**: Single character
    - **Example**: `printf("%c", 'A');` will output `A`.

## Pointer Format
- **`%p`**: Pointer (address in memory)
    - **Example**: `printf("%p", &variable);` will output the memory address of the variable.

## Width & Precision Modifiers
#### Width
- Specifies the minimum number of characters to be printed.
    - **Example**: `printf("%5d", 42);` will output  `   42` (with leading spaces to meet the width of 5).

#### Precision (for floating-point)
- Specifies the number of digits after the decimal point.
    - **Example**: `printf("%.2f", 3.14159);` will output `3.14`.

### Width and Precision together
You can use both width and precision modifiers together, especially for floating-point numbers.
- **Example**: `printf("%8.2f", 3.14159);` will output  `    3.14`.

## Sign Modifiers
- **`+`**: Forces the sign to be printed for positive numbers as well as negative ones.
    - **Example**: `printf("%+d", 45);` will output `+45`.
	
- **`-`**: Left-justifies the output within the specified width.
    - **Example**: `printf("%-5d", 45);` will output `45   `  (left-aligned).
	
- **`0`**: Pads the output with zeros instead of spaces.
    - **Example**: `printf("%05d", 45);` will output `00045`.

# Integer Literals
#### Decimal Integer Literals
- Decimal integer literals are the most common and represent numbers in the base-10 system.
- **Example**: `int value = 123;`
#### Octal Integer Literals
- Octal literals start with a leading `0` and represent numbers in base-8.
- **Example**: `int value = 075;` (equivalent to decimal `61`)
#### Hexadecimal Integer Literals
- Hexadecimal literals start with a leading `0x` or `0X` and represent numbers in base-16.
- **Example**: `int value = 0x7F;` (equivalent to decimal `127`)
#### Binary Integer Literals (C11 and beyond)
- Binary literals are introduced in C11 and start with a leading `0b` or `0B`.
- **Example**: `int value = 0b1010;` (equivalent to decimal `10`)


# Alternative for StringStream: sprintf
```C
#include <stdio.h>

int main() 
{
    char buffer[50];  /**< Declare a buffer to store the formatted string */
    int value = 123;  /**< Example integer value */

    /* Format the integer into the string */
    sprintf(buffer, "The value is %d", value);

    /* Print the formatted string */
    printf("%s", buffer);

    return 0;
}
```

**Syntax**: just like printf, with an additional initial parameter, to store the buffer value.
- The integer is read into a string buffer.
- The buffer is relayed by printf.

**LIMITATIONS**:
1. Memory-Intensive
2. Makes program slow
3. Buffer-Overflow possibility

# Overcoming overflow with sprintf : snprintf
```C
int snprintf(char *str, size_t size, const char *format, ...);
```
- mention length.
USAGE:
```C
#include <stdio.h>

int main() 
{
    char buffer[20];  /**< Small buffer */
    int largeValue = 123456;

    /* Format the large integer into a small buffer */
    int written = snprintf(buffer, sizeof(buffer), "Value: %d", largeValue);

    /* Output the truncated string */
    printf("Formatted: %s\n", buffer);
    printf("Total characters would be: %d\n", written);

    return 0;
}
```

// Buffer-overflow is handled

#  sscanf
```C
#include <stdio.h>

int main() 
{
    char input[] = "Value: 123";  /**< String containing the value */
    int value;

    /* Parse the integer from the string */
    sscanf(input, "Value: %d", &value);

    /* Output the parsed value */
    printf("Parsed value: %d", value);

    return 0;
}
```
- The function scans for the value after "Value: " and stores it in value.

Multi-parsing
```C
#include <stdio.h>

int main() 
{
    char input[] = "Temperature: 25, Voltage: 3.3";
    int temperature;
    float voltage;

    /* Parse multiple values from the string */
    sscanf(input, "Temperature: %d, Voltage: %f", &temperature, &voltage);

    /* Output the parsed values */
    printf("Temperature: %d°C, Voltage: %.2fV", temperature, voltage);

    return 0;
}
```
**Limitations:**
1. Memory Intensive
2. Slow
3. Can return EOF due to failed parsing