# 1. Implicit Casting (Automatic)
```C
int16_t smallint = 10;
int32_t largeint;

largint=smallint; // int16 is auto converted to int32
```

1. Results in overflow when target destination is smaller than src.

# 2. Explicit Casting (Manual)
```C
/**< Declare a floating-point number */
float floatNumber = 3.14;
/**< Declare an integer */
int32_t intNumber;
/**< Explicit casting from float to int32_t */
intNumber = (int32_t) floatNumber;  // Result will be 3, fractional part is lost
```