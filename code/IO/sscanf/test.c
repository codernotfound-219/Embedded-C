#include <stdio.h>

int main() {
  char input[] = "Temperature: 25, Voltage: 3.3";
  int temperature;
  float voltage;

  /* Parse multiple values from the string */
  sscanf(input, "Temperature: %d, Voltage: %f", &temperature, &voltage);

  /* Output the parsed values */
  printf("Temperature: %d°C, Voltage: %.2fV\n", temperature, voltage);

  char input_2[] = "0x1A2B3C";
  unsigned int address;

  sscanf(input_2, "0x%X", &address);
  printf("address: 0x%X\n", address);

  return 0;
}
