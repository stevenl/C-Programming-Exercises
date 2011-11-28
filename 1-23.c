/*
 * Exercise 1-23. Write a program to remove all comments from a C program.
 * Don't forget to handle quoted strings and character constants properly.
 * C comments don't nest.
 */

#include <stdio.h>

/* states */
#define NONE    0
#define COMMENT 1
#define CHAR    2
#define STRING  3

int main(void)
{
    int c, prev, state;

    for (c = prev = state = 0; (c = getchar()) != EOF; prev = c) {
        if (state == COMMENT) {
            if (prev == '*' && c == '/') {
                state = NONE;
                c = '\0'; /* prevent '/' from being printed on next iteration */
            }
            continue;
        }

        if (state == STRING) {
            if (c == '"')
                state = NONE;
            putchar(c);
            continue;
        }

        if (state == CHAR) {
            if (c == '\'')
                state = NONE;
            putchar(c);
            continue;
        }

        /* state == NONE */
        if (c == '\'') {
            state = CHAR;
        }
        else if (c == '"') {
            state = STRING;
        }
        else if (c == '/') {
            continue;
        }
        else if (prev == '/') {
            if (c == '*') {
                state = COMMENT;
                continue;
            } else {
                putchar(prev);
            }
        }
        putchar(c);
    }
    return 0;
}

/*********
   tests
 *********/

/* a single line comment */

/*
a multi line comment
*/

/* "not a string" */
/* 'c' is not a char */
char string[20] = "/* not a comment */";
