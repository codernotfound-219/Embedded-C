- Indicates to the compiler that the variable is subject to change even though the actual program code doesn't change it.
- It can change via interrupt routines, or a different thread or so.
- The compiler will not optimize the volatile variable.

