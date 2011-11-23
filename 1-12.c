/* Exercise 1-12. Write a program that prints its input one word per line. */

#include <stdio.h>

#define IN  1
#define OUT 0

int main(void)
{
    int chr;
    int state;

    state = OUT;
    while ((chr = getchar()) != EOF) {
        if (chr == ' ' || chr == '\t' || chr == '\n') {
            if (state == IN) {
                state = OUT;
                putchar('\n');
            }
        } else {
            state = IN;
            putchar(chr);
        }
    }
    return 0;
}
