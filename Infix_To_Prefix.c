#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int top = -1;
char *stack;
int n;

#include "stack_char.h"

int priority_input(char x)
{
    if (x == '+' || x == '-')
        return 2;
    if (x == '*' || x == '/')
        return 4;
    if (x == '^')
        return 6;
    if (isalnum(x))
        return 7;
    if (x == '(')
        return 9;
    if (x == ')')
        return 0;

    return 0;
}

int priority_stack(char x)
{
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 3;
    if (x == '^')
        return 6;
    if (isalnum(x))
        return 8;
    if (x == '(')
        return 0;

    return 0;
}

int rank(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^')
        return -1;
    if (isalnum(x))
        return 1;
}

void reversestr(char str[])
{
    int k;
    for (k = 0; str[k] != '\0'; k++)
    {
        if (str[k] == '(')
            push(')');
        else if (str[k] == ')')
            push('(');
        else
            push(str[k]);
    }

    for (k = 0; top != -1; k++)
    {
        str[k] = pop();
    }
}

void main()
{
    char infix[100];

    printf("\nEnter the Expression : ");
    scanf("%[^\n]%*c", infix);

    n = strlen(infix) + 1;
    char postfix[100];
    stack = (char *)malloc((n) * sizeof(char));

    reversestr(infix);

    push('(');
    strcat(infix, ")");

    int i = 0, j = 0, Rank = 0;
    char x;

    char nextchar = infix[i];

    for (j = 1; j <= strlen(infix); j++)
    {
        while (priority_stack(stack[top]) > priority_input(nextchar))
        {
            x = pop();
            postfix[i] = x;
            i++;

            Rank += rank(x);
            if (Rank < 1)
            {
                printf("Invalid Expression");
                return;
            }
        }

        if (priority_input(nextchar) != priority_stack(stack[top]))
        {
            push(nextchar);
        }
        else
            pop();

        nextchar = infix[j];
    }

    if (top != -1 || Rank != 1)
    {
        printf("Invalid Expression");
        return;
    }

    reversestr(postfix);
    printf("\nPrefix Expression is: %s", postfix);
}
