/*
 * Exercise 1-9. Write a program to copy its input to its output,
 * replacing each string of one or more blanks by a single blank.
 */

#include <stdio.h>

int main(void)
{
    int chr;
    int lastchr = 'a';

    while ((chr = getchar()) != EOF) {
        if (chr != ' ' || lastchr != ' ')
            putchar(chr);
        lastchr = chr;
    }
    return 0;
}
