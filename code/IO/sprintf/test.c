#include <stdio.h>

int main() {
  char buffer[100];
  int temperature = 130;
  float voltage = 3.3;

  sprintf(buffer, "The temperature is: %d˚C, and the voltage level is: %.2f V", temperature, voltage);
  printf("%s", buffer);

  return 0;
}
