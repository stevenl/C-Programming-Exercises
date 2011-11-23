/* Exercise 1-17. Write a program to print all input lines that are longer than 80 characters. */

#include <stdio.h>

#define MAXLEN 1000
#define MINLEN 80

int getline(char[], int);

int main(void)
{
    int len;
    char line[MAXLEN];

    while ((len = getline(line, MAXLEN)) > 0)
        if (len > MINLEN)
            printf("%s", line);

    return 0;
}

int getline(char line[], int maxlen)
{
    int c, len;

    len = 0;
    while ((c = getchar()) != EOF) {
        if (len == maxlen) break;

        line[len++] = c;
        if (c == '\n') break;
    }
    line[len] = '\0';

    return len;
}

/* this is a long line ************************************************************/
