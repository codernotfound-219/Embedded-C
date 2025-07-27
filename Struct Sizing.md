
| Data Type          |       Byte        |
| :----------------- | :---------------: |
| char               |         1         |
| short              |         2         |
| int                |         4         |
| unsigned int       |         4         |
| long               | 4 (8 for 64-bit)  |
| unsigned long      | 4 (8 for 64-bit)  |
| long long          |         8         |
| unsigned long long |         8         |
| float              |         4         |
| double             |         8         |
| long double        | 8 (10 for 64-bit) |

# Padding:
- 32-bit processor -> reads 4 bytes at a time
- 64-bit processor -> reads 8 bytes at a time

```C
struct ABC {
	char a; // 1 byte
	char b; // 1 byte
	int c;  // 4 byte
} var;
```
- var is an object of struct ABC.
- Size = 6 bytes? HELL NAH
- ![[Pasted image 20250727232956.png]]
- To read all information in through, a padding (empty bytes)  is to provided in the first 4 bytes as follows:![[Pasted image 20250727233043.png]]

```C
struct ABC {
	char a;
	int c;
	char b;
}var;
```
**Size:** 12 bytes
- 4 for `char a`
- 4 for `int c`
- 4 for `char b`