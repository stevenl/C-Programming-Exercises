/*
 * Exercise 1-21. Write a program entab that replaces strings of blanks by the
 * minimum number of tabs and blanks to achieve the same spacing. Use the same
 * tab stops as for detab. When either a tab or a single blank would suffice to
 * reach a tab stop, which should be given preference?
 */

#include <stdio.h>

#define TABSTOP 4

int main(void)
{
    int c, col, i, nspaces;

    col = nspaces = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            col++;
            nspaces++;
            if (col % TABSTOP == 0) {
                putchar('\t');
                nspaces = 0;
            }
            continue;
        }

        if (c == '\t')
            col += nexttabstop(col);
        else if (c == '\n')
            col = 0;
        else {
            for (i = 0; i < nspaces; i++)
                putchar(' ');
            col++;
        }
        nspaces = 0;
        putchar(c);
    }
    return 0;
}

int	nexttabstop(int	col)
{
	return (col	/ TABSTOP +	1) * TABSTOP;
}
