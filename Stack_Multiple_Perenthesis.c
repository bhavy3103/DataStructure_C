#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n;
int top = -1;
char str[100];
char *stack;

#include "stack_char.h"

void main()
{
    printf("Enter the Expression : ");
    scanf("%[^\n]%*c", str);

    n = strlen(str);
    stack = (char *)malloc(n * sizeof(char));

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(')
            push('(');
        else if (str[i] == '{')
            push('{');
        else if (str[i] == '[')
            push('[');

        else if ((str[i] == ')' || str[i] == '}' || str[i] == ']') && top == -1)
        {
            printf("Expression is NOT Valid");
            return;
        }

        else if (str[i] == ')' && str[top] == '(')
        {
            pop();
        }
        else if (str[i] == '}' && str[top] == '{')
        {
            pop();
        }
        else if (str[i] == ']' && str[top] == '[')
        {
            pop();
        }
    }

    if (top == -1)
    {
        printf("Expression is Valid");
    }
    else
    {
        printf("Expression is NOT Valid");
    }
}
