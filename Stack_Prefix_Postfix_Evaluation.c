#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int top = -1;
char *stack;
int n;

#include "stack_char.h"

int isoperator(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^')
        return 1;
    else
        return 0;
}

void reversestr(char exp[])
{
    int k;
    for (k = 0; k < n; k++)
        push(exp[k]);

    for (k = 0; top != -1; k++)
        exp[k] = pop();
}

void evalution(char exp[])
{
    for (int i = 0; i < n; i++)
    {
        int val1, val2, val;
        if (isdigit(exp[i]))
        {
            push(exp[i] - '0');
        }
        else
        {
            val2 = pop();
            val1 = pop();

            switch (exp[i])
            {
            case '+':
                val = val1 + val2;
                break;
            case '-':
                val = val1 - val2;
                break;
            case '*':
                val = val1 * val2;
                break;
            case '/':
                val = val1 / val2;
                break;
            case '^':
                val = 1;
                for (int k = 0; k < val2; k++)
                {
                    val *= val1;
                }
                break;
            }
            push(val);
        }
    }
}

void main()
{
    char exp[100];

    printf("\nEnter the Expression : ");
    scanf("%[^\n]%*c", exp);

    n = strlen(exp);

    char postfix[100];
    stack = (char *)malloc((n) * sizeof(char));

    if (isoperator(exp[0]))
        reversestr(exp);

    printf("%s\n", exp);
    evalution(exp);

    printf("Result of Expression : %d", pop());
}
