/* Exercise 1-8. Write a program to count blanks, tabs, and newlines. */

#include <stdio.h>

int main(void)
{
	int chr;
	long blanks, tabs, newlines;

	blanks = tabs = newlines = 0;

	while ((chr = getchar()) != EOF) {
		if (chr == ' ')
			++blanks;
		else if (chr == '\t')
			++tabs;
		else if (chr == '\n')
			++newlines;
	}
	printf("blanks=%ld; tabs=%ld; newlines=%ld\n", blanks, tabs, newlines);

	return 0;
}
