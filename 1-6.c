/* Exercsise 1-6. Verify that the expression getchar() != EOF is 0 or 1. */

#include <stdio.h>

int main(void)
{
    int c = 0;
    while (c != EOF) {
        c = getchar();

        if (c != '\n')
            printf("%4d %c  => %d\n", c, c, (c != EOF));
        else
            printf("%4d \\n => %d\n", c, (c != EOF));
    }
    return 0;
}
