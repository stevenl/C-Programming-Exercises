/*
 * Exercise 1-19. Write a function reverse(s) that reverses the character string s.
 * Use it to write a program that reverses its input a line at a time.
 */

#include <stdio.h>

#define MAXLEN 1000

int getline(char[], int);
void reverse(char[], int);

int main(void)
{
    char line[MAXLEN];
    int len;

    while ((len = getline(line, MAXLEN)) > 0) {
        reverse(line, MAXLEN);
        printf("%s", line);
    }
    return 0;
}

void reverse(char s[], int maxlen)
{
    int i, len;
    char cache[maxlen];

    for (i = 0; s[i] != '\0'; i++)
        cache[i] = s[i];
    len = i - 1;

    for (i = 0; i < len; i++)
        s[i] = cache[len - i - 1];
}

int getline(char line[], int maxlen)
{
    int c, len;

    len = 0;
    while ((c = getchar()) != EOF) {
        if (len == maxlen)
            break;

        line[len++] = c;
        if (c == '\n')
            break;
    }
    line[len] = '\0';

    return len;
}
