#include <stdio.h>

typedef struct {
  char a;
  char b;
  int c;
} CCI;

typedef struct {
  int c;
  char a;
  char b;
} ICC;

typedef struct {
  char a;
  int c;
  char b;
} CIC;

int main(void) {
  CCI var1;
  CIC var2;
  ICC var3;

  printf("Size of struct CCI: %d\n", (int) sizeof(var1));
  printf("Size of struct CIC: %d\n", (int) sizeof(var2));
  printf("Size of struct ICC: %d\n", (int) sizeof(var3));

  return 0;
}
