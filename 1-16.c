/*
 * Exercise 1-16. Revise the main routine of the longest-line program so it
 * will correctly print the length of arbitrary long input lines,
 * and as much as possible of the text.
 */

#include <stdio.h>

#define MAXLINE 80 /* maximum input line length */

int getline(char line[], int maxline);
int getline2(char line[], int maxline);
void copy(char to[], char from[]);

int main(void)
{
    int c;
    int len;                /* current line length */
    int max;                /* maximum length seen so far */
    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE];  /* longest line saved here */

    max = 0;
    while ((len = getline(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);

            if (max == MAXLINE)
                while ((c = getchar()) != EOF) {
                    max++;
                    if (c == '\n') break;
                }
        }
    if (max > 0) {
        printf("max line length = %d\n", max);
        printf("%s", longest);
    }

    return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* getline: read a line into s, return length */
int getline2(char s[], int lim)
{
    int c, i;

    for (i = 0; (c = getchar()) != EOF; ++i) {
        if (i < lim)
            s[i] = c;
        else if (i == lim)
            s[i] = '\0';

        if (c == '\n') {
            ++i;
            s[i] = '\0';
            break;
        }
    }
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

/* a line that exceeds the max input size of 80 **********************************/
