# 1. Enum
Syntax
```C
enum enum_name {
	value_1 = x,
	value_2 = y,
	value_3 = z,
	...
};
```
Example
```C
#include <stdio.h>

enum LEDState {
	OFF = 0,
	ON = 1,
	BLINK = 2
};
```
**Benefits**:
1. Type-safety
2. Maintenance
3. Readability

# 2. Struct
Syntax
```C
struct struct_name {
	type member1;
	type member2;
	type member3;
	...
};
```
Example:
```C
struct SensorData {
	float temperature;
	float humidity;
	int sensorID;
};

int main() {
	struct SensorData mySensor = {.temperature = 4.25, .humidity = 2.34, .sensorID = 12};
	...
}
```
**Benefits**:
1. organization
2. readability
3. data handling

BETTER WAY:
```C
typdef struct {
	float temperature;
	float humidity;
	int sensorID;
} SensorData;

int main() {
	SensorData mySensor; // No need to type out struct everywhere
}
```

# 3. Union
Syntax
```C
union union_name {
	type member1;
	type member2;
	type member3;
	...
};
```
Example:
```C
union Data {
	int i;
	float f;
	char str[20];
};

int main() 
{
    union Data data; /**< Declare a variable of type union Data */
    
    /* Assign an integer value to the union */
    data.i = 10; /**< Store an integer in the union */
    printf("Integer: %d\n", data.i);
    
    /* Assign a float value to the union (overwrites the previous data) */
    data.f = 3.14; /**< Store a float in the union */
    printf("Float: %.2f\n", data.f);
    
    /* Assign a string value to the union (overwrites the previous data) */
    snprintf(data.str, sizeof(data.str), "Hello, World!"); /**< Store a string in the union */
    printf("String: %s\n", data.str);
    
    return 0;
}
```

1. In a union all members share the same memory location. Writing to a member means overwriting the previously stored value.
2. Initially data was 10, it was overwritten to 3.14 and then overwritten to "Hello, World!"

**Benefits**:
1. Efficient memory usage
2. Flexible data storage
3. Mainly useful when a variable can be represented in multiple formats.

# Example: 32-bit integer to 4 8-bit bytes using Union
```C
#include <stdio.h>
#include <stdint.h>

/* Defining a union to convert a 32-bit unsigned integer to four 8-bit unsigned integers */
union Converter 
{
    uint32_t fullValue; /**< 32-bit unsigned integer */
    uint8_t byte[4]; /**< Array of 4 bytes (uint8_t) */
};

int main() 
{
    union Converter converter; /**< Declare a variable of type union Converter */
    
    /* Assign a 32-bit value to the union */
    converter.fullValue = 0x12345678; /**< Example 32-bit value */
    
    printf("32-bit value: 0x%X\n", converter.fullValue); /**< Print the full 32-bit value */
    
    /* Print the 4 bytes */
    printf("Byte 1: 0x%X\n", converter.byte[0]); /**< Output: 0x78 */
    printf("Byte 2: 0x%X\n", converter.byte[1]); /**< Output: 0x56 */
    printf("Byte 3: 0x%X\n", converter.byte[2]); /**< Output: 0x34 */
    printf("Byte 4: 0x%X\n", converter.byte[3]); /**< Output: 0x12 */
    
    return 0;
}
```
- As the address is stored in the same memory, we are able to access it via array and full value as well.

# 4. Bitfield
```C
struct struct_name {
	type member_name : number_of_bits;
}
```
example:
```C
typedef struct {
	uint8_t PIN0 : 1;
	uint8_t PIN1 : 1;
	uint8_t PIN2 : 1;
	uint8_t PIN3 : 1;
	uint8_t PIN4 : 1;
	uint8_t PIN5 : 1;
	uint8_t PIN6 : 1;
	uint8_t PIN7 : 1;
} GPIO_pinType;

typedef union {
	uint8_t reg;      // FullByte Access
	GPIO_pinType Bit; // Bit level access
} U_type;
```

1. Widely used for storing flags, control registers in microcontrollers.

# 5. Typedef
- Used to create alias