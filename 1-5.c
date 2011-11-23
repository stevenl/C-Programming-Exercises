/*
 * Exercise 1-5. Modify the temperature conversion program to
 * print the table in reverse order, that is, from 300 degrees to 0.
 */

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main(void)
{
    float fahr, celsius;
    float lower, upper, step;

    printf("fahrenheit celsius\n");
    printf("---------- -------\n");

    for (fahr = UPPER; fahr >= LOWER; fahr -= STEP) {
        celsius = (5.0 / 9.0) * (fahr - 32);
        printf("%9.0f  %6.1f\n", fahr, celsius);
    }
    return 0;
}
