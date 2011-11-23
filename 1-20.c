/*
 * Exercise	1-20. Write	a program detab	that replaces tabs in the input	with the
 * proper number of	blanks to space	to the next	tab	stop.
 * Assume a	fixed set of tab stops,	say	every n	columns.
 * Should n	be a variable or a symbolic	parameter?
 */

#include <stdio.h>

#define	TABSTOP	4

int	main(void)
{
	int	c, i, col, stop;

	col	= 0;
	while ((c =	getchar()) != EOF) {
		if (c == '\n') {
			putchar(c);
			col	= 0;
		}
		else if	(c == '\t')	{
			stop = nexttabstop(col)	- col;
			//printf("[stop=%d]", stop);
			for	(i = 0;	i <	stop; i++) {
				putchar(' ');
				col++;
			}
		}
		else {
			putchar(c);
			col++;
		}
	}
	return 0;
}

int	nexttabstop(int	col)
{
	int	n =	(col / TABSTOP + 1)	* TABSTOP;
	return (col	/ TABSTOP +	1) * TABSTOP;
}
