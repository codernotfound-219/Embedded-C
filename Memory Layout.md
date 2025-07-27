![[Pasted image 20250727224849.png]]
# Text: (aka Code Section)
- Read-only 
- Contains machine code
- Fixed size
- Stores literals that may be in code

# Data

## Initialized: (aka Data Segment)
- Holds initialized global and static variables
- Fixed size
- Read/Write
- Data to be written to executable

## Uninitialized: (aka BSS Segment) - block started by symbol
- Holds uninitialized globals and statics
- Auto-initialized to zero
- Data is not written to executable. The  .bss segment simply reserves space in memory.
- Memory efficient as executable is not big.

## Heap:
- Can grow/shrink in size. (Decided by the programmer)
- When the stack pointer and the heap pointer point to the same address, it indicates memory overflow.