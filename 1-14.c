/*
 * Exercise 1-14. Write a program to print a histogram of the frequencies of
 * different characters in its input.
 */

#include <stdio.h>

#define CHAR_MAX 256

int main(void)
{
    int i, j, c;
    int charfreq[CHAR_MAX];

    for (i = 0; i < CHAR_MAX; i++)
        charfreq[i] = 0;

    while ((c = getchar()) != EOF)
        charfreq[c]++;

    for (i = 0; i < CHAR_MAX; i++) {
        if (charfreq[i] == 0)
            continue;

        printf("%2c | ", i);
        for (j = 0; j < charfreq[i]; j++)
            putchar('#');
        putchar('\n');
    }
    return 0;
}
