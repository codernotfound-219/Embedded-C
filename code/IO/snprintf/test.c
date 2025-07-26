#include <stdio.h>

int main() 
{
    char buffer[20];  /**< Small buffer */
    int largeValue = 123456;

    /* Format the large integer into a small buffer */
    int written = snprintf(buffer, sizeof(buffer), "Value: %d", largeValue);

    /* Output the truncated string */
    printf("Formatted: %s\n", buffer);
    printf("Total characters would be: %d\n", written); // truncated to 13

    return 0;
}
