/*
 * Exercise 1-13. Write a program to print a histogram of the lengths of words
 * in its input. It is easy to draw the histogram with the bars horizontal;
 * a vertical orientation is more challenging.
 */

#include <stdio.h>

#define MAXLEN 10

void print_array(int[]);
void print_horizontal(int[]);
void print_vertical(int[]);

int main(void)
{
    int c, i, len;
    int lenfreq[MAXLEN];

    for (i = 0; i < MAXLEN; i++)
        lenfreq[i] = 0;

    len = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (len > 0)
                lenfreq[len]++;
            len = 0;
        } else {
            len++;
        }
    }
    /*print_array(lenfreq);*/
    /*print_horizontal(lenfreq);*/
    print_vertical(lenfreq);

    return 0;
}

void print_array(int array[])
{
    int i;
    for (i = 0; i < MAXLEN; i++)
        printf("%2d => %d\n", i, array[i]);
}

void print_horizontal(int lenfreq[])
{
    int i, j;
    for (i = 1; i < MAXLEN; i++) {
        printf("%2d | ", i);
        for (j = 0; j < lenfreq[i]; j++)
            putchar('#');
        putchar('\n');
    }
}

void print_vertical(int lenfreq[])
{
    int i, max, freq;

    max = 0;
    for (i = 0; i < MAXLEN; i++)
        if (max < lenfreq[i])
            max = lenfreq[i];

    for (freq = max; freq >= 0; freq--) {
        printf("%4d |", freq);
        for (i = 1; i < MAXLEN; i++)
            if (freq <= lenfreq[i])
                printf(" #");
            else
                printf("  ");

        putchar('\n');
    }

    printf("      ");
    for (i = 1; i < MAXLEN; i++)
        printf("--");

    printf("\n      ");
    for (i = 1; i < MAXLEN; i++)
        printf("%2d", i);
}
