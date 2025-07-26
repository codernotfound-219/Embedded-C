#include <stdio.h>
#include <stdint.h>

union Converter {
  uint32_t fullValue;
  uint8_t byte[4];
};

int main() {
  union Converter converter;

  converter.fullValue = 0x12345678;
  printf("32-bit value: 0x%X\n", converter.fullValue);

  printf("Byte 1: 0x%X\n", converter.byte[0]);
  printf("Byte 2: 0x%X\n", converter.byte[1]);
  printf("Byte 3: 0x%X\n", converter.byte[2]);
  printf("Byte 4: 0x%X\n", converter.byte[3]);

  return 0;
}
