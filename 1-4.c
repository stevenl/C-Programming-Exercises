/* Exercise 1-4. Write a program to print the corresponding Celsius to Fahrenheit table. */

#include <stdio.h>

#define LOWER -20
#define UPPER 140
#define STEP 10

int main(void)
{
    float celsius, fahr;
    float lower, upper, step;

    celsius = lower;
    while (celsius <= upper) {
        fahr = celsius / (5.0 / 9.0) + 32;
        printf("%4.0f %4.0f\n", celsius, fahr);
        celsius += step;
    }
    return 0;
}
