/*
 * Exercise 1-24. Write a program to check a C program for rudimentary syntax
 * errors like unmatched parentheses, brackets and braces. Don't forget about
 * quotes, both single and double, escape sequences, and comments.
 * (This program is hard if you do it in full generality.)
 */

#include <stdio.h>

#define MAXSIZE 1000

/* states */
#define NONE    0
#define COMMENT '*'
#define CHAR    '\''
#define STRING  '"'
#define PAREN   '('
#define BLOCK   '{'
#define ESCAPE  '\\'

void stack_push(int);
int  stack_pop();
int  stack_top();

int main(void)
{
    int c, nchars, prev, line;

    stack_push(NONE);
    line = 1;

    for (nchars = 0; (c = getchar() != EOF; prev = c, nchars++) {
        putchar(c);

        if (c == '\n')
            line++;
        else if (stack_top() == COMMENT) {
            if (prev == '*' && c == '/')
                stack_pop();
        }
        else if (stack_top() == STRING) {
            if (c == '\\')
                stack_push(ESCAPE);
            else if (c == '"')
                stack_pop();
        }
        else if (stack_top() == CHAR) {
            if (c == '\'')
                stack_pop();
            else if (c == '\\' && prev == '\'') {
                stack_push(ESCAPE);
                nchars--;
            }
            else if (nchars > 1)
                printf("Error: %c at line %d\n", char, line);
        }
        else if (stack_top() == ESCAPE) {
            stack_pop();
        }
        else if (c == '(') {
            stack_push(PAREN);
        }
        else if (c == ')') {
            if (stack_top() == PAREN)
                stack_pop();
            else
                printf("Error: %c\n", PAREN);
        }
        else if (c == '{') {
            stack_push(BLOCK);
        }
        else if (c == '}') {
            if (stack_top() == BLOCK)
                stack_pop();
            else
                printf("Error: %c\n", BLOCK);
        }
        else if (c == '\'') {
            stack_push(CHAR);
            nchars = -1;
        }
        else if (c == '"') {
            stack_push(STRING);
        }
        else if (prev == '/' && c == '*') {
            if (stack_top() != COMMENT && stack_top() != STRING)
                stack_push(COMMENT);
        }
    }

    if (stack_top() != NONE)
        printf("Error: %c at line %d\n", stack_top(), line);

    return 0;
}

int stack[MAXSIZE];
int stacksize = 0;

void stack_push(int state)
{
    stack[stacksize++] = state;
}

int stack_pop(void)
{
    return stack[--stacksize];
}

int stack_top(void)
{
    return stack[stacksize - 1];
}
