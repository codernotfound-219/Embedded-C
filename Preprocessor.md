# 1. Define
- `#define` allows you to define constants, macros, etc. Allows replacement of text before compilation.

# 2. ifdef, ifndef, endif
```Rust
/* Conditional inclusion of code based on the defined macro */
#ifdef DEBUG
    printf("Debugging is enabled.\n");
#endif
/**< Prints a message only if the DEBUG macro is defined */

/* Prevent redefinition of the header */
#ifndef MY_HEADER_H
#define MY_HEADER_H

/* Header file content here */

#endif
/**< Ensures that the header file content is only included once */
```
- The code inside `ifdef` is only run if `DEBUG` macro is enabled.
- `ifndef`: if `MY_HEADER_H` is not defined, the define it, else leave it. (Prevent multiple redefinitions)

# 3. if, elif, else
```Rust
/* Conditional code for different microcontroller versions */
#if defined(MCU_VERSION_1)
    // Code for MCU version 1
#elif defined(MCU_VERSION_2)
    // Code for MCU version 2
#else
    // Default code for unsupported versions
#endif
/**< Compiles different code based on the defined MCU version */
```
- Specific code for each microcontroller variation.

# 4. undef
```Rust
/* Define and later undefine a macro */
#define MAX_TEMP 100
/**< Defines a maximum temperature constant */

/* Undefining the macro after use */
#undef MAX_TEMP
/**< Undefines the MAX_TEMP macro, so it is no longer available */
```

# 5. pragma
- To disable warnings
- Example:
```rust
/* Disabling specific compiler warnings */
#pragma GCC diagnostic ignored "-Wunused-variable"
/**< Ignores warnings about unused variables */

/* Restoring warnings */
#pragma GCC diagnostic warning "-Wunused-variable"
/**< Restores warnings about unused variables */
```

# 6. error, warnings
```rust
/* Displaying a warning if the system is in a low-power mode */
#if defined(LOW_POWER_MODE)
    #warning "Low power mode is enabled. Be sure to test functionality thoroughly." // compiler issues warning mesg
#endif
/**< Displays a warning if low power mode is active */
```

```rust
/* Raise an error if the microcontroller model is not defined */
#ifndef MCU_MODEL
    #error "MCU_MODEL must be defined!" // generate error message
#endif
/**< Ensures the MCU model is defined before proceeding */
```

# 7. include_next
```rust
/* Including the next instance of a file in the include search path */
#include_next <stdio.h>
/**< Includes the next available stdio.h file in the search path */
```
- It **includes the next file named `stdio.h`** found in the _include search path_, **skipping the current directory or the directory where the current file was found**.
- This means: if you already included a header named `stdio.h` from one directory, `#include_next <stdio.h>` will look **for another `stdio.h` file later in the include search path**, **after** the directory of the current include file.