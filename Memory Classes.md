## 1. Auto:
```C
void function() {
	auto int num = 10;
	printf("%d", num);
}
```

1. Modern C, does not require this keyword before every local initialization.
2. By default, all local initializations are auto.

**Storage**: Stack
**Lifetime**: Scope of function block

## 2. Static:
```C
void function() {
	static int count = 0;
	count++;
	printf("%d\n", count):
}
```

1. Used to extend the lifetime of a variable to the entire run-time.

**Storage**: Memory
**Lifetime**: Full Run-Time

## 3. Extern
file-1.c
```C
int globalVar = 5;
```
file-2.c
```C
extern int globalVar;  // declaration of globalVar declared in file-1.c
void function() {
	printf("%d\n", globalVar);
}
```

1. To access global variables in a different source file.

**Storage**: Memory
**Lifetime**: Global so, full run-time (mostly)

## 4. Volatile
```C
volatile int flag = 0;  // Tells the compiler not to optimize access to 'flag'

void interruptHandler() {
    flag = 1;  // Flag is set in an interrupt (it could change unexpectedly)
}

void main() {
    while (flag == 0) {
        // Wait for the interrupt to set 'flag' to 1
    }
    printf("Interrupt occurred!\n");
}
```

1. Tells compiler not to optimize the variable as its value may change.
2. Commonly used for hardware registers / flags / variables shared between interrupt handler and program.

**Storage**: Memory (unoptimized)
**Lifetime**: Scope life-time

## 5. Register
```C
void function() {
    register int i = 0;  // Suggests to the compiler to use a register for 'i'
    for (i = 0; i < 1000; i++) {
        // Some operation
    }
}
```

1. Used to store in CPU register (if available)

**Storage**: CPU register
**Lifetime**: Scope life-time


## 6. const
```C
const int MAX_USERS = 100;   // 100 cannot be changed

// Constant pointer 
int x = 10;
int * const ptr = &x;       // ptr address cannot be changed

// Pointer to a constant
const int * ptr = &x;       // the value pointed to by ptr cannot be changed

// Constant pointer to a constant
const int * const ptr = &x; // value pointed and the address of the value cannot be changed
```

1. Disables modifications

**Storage:** Memory (protection from modifications)
**Lifetime**:  Scope life-time

# Summary
![[Pasted image 20250726145818.png]]