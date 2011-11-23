/* Exercise 1.15. Rewrite the temperature conversion program of Section 1.2 to use a function for conversion. */

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

float f2c(float);
float c2f(float);

int main(void)
{
    int fahr;
    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf("%3d %6.1f %6.1f\n", fahr, f2c(fahr));

    return 0;
}

float f2c(float fahr)
{
    return (fahr - 32) * 5 / 9;
}

float c2f(float cels)
{
    return (cels / 5 * 9) + 32;
}
