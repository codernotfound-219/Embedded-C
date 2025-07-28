```C
#include <stdio.h>
// Assume base address of "GeeksQuiz" to be 1000

int main()
{
   printf(5 + "GeeksQuiz"); // output: Quiz (skip 5 bytes)
   return 0;
}
```

```C
#include <stdio.h>
int main()
{
    int i = 3;
    printf("%d", (++i)++); // compile-time error: need lvalue to perform increments
    return 0;
}
```

```C
#include <stdio.h>

int main()
{
    unsigned int i = 65000;
    while (i++ != 0);
    printf("%d", i); // Ans is 1.
    return 0;
}

/*
Overflow, results i = 0;
0++ != 0;
i will become 1
```

```C
struct {int a[2];} arr[] = {1,2};
// OUTPUT:
arr[0].a[0] = 1
arr[0].a[1] = 2
```

```C
void f(int* p, int m)
{
    m = m + 5;
    *p = *p + m;
    return;
}
void main()
{
    int i=5, j=10;
    f(&i, j);
    printf("%d", i+j);
}
// OUTPUT:
 i = 20
 j = 10
ans = 30
```

What does the following expression means ?   
char ∗(∗(∗ a[N]) ( )) ( );

\*a[N] -> N pointers
\*(a[N])() -> Function pointer to N pointers
∗(∗(∗ a[N]) ( )) ( ) -> Function pointer to Function pointer to N pointers

```C
#include   
int tmp=20;  
main( ) {  
	printf("%d ",tmp);  
	func( );  
	printf("%d ",tmp);  
}  
func( ) {  
	static int tmp=10;  
	printf("%d ",tmp);  
}

OUTPUT: 20 10 20
```