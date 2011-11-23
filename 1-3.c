/* Exercise 1-3. Modify the temperature conversion program to print a heading above the table. */

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

    fahr = LOWER;
    while (fahr <= UPPER) {
        celsius = (5.0 / 9.0) * (fahr - 32);
        printf("%9.0f  %6.1f\n", fahr, celsius);
        fahr += STEP;
    }
    return 0;
}
