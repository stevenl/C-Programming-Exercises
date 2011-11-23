/*
 * Exercise 1-10. Write a program to copy its input to its output,
 * replacing each tab by \t, each backspace by \b, and each backslash by \\.
 * This makes tabs and backspaces visible in an unambiguous way.
 */

#include <stdio.h>

int main(void) {
	int chr;
	while ((chr = getchar()) != EOF) {
		if (chr == '\t')
			printf("\\t");
		else if (chr == '\b')
			printf("\\b");
		else if (chr == '\\')
			printf("\\\\");
		else
			putchar(chr);
	}
	return 0;
}
