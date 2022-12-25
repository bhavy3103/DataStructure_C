#include <stdio.h>
#include <string.h>

#define max 100
int top = -1;
int stack[max];

void push(char x)
{
    if (top == max - 1)
    {
        printf("stack overflow");
    }
    else
    {
        stack[++top] = x;
    }
}

void pop()
{
    printf("%c", stack[top--]);
}

int main()
{
    char str[100];
    printf("Enter String here: ");
    scanf("%[^\n]%*c", str);
    int len = strlen(str);
    int i;

    for (i = 0; i < len; i++)
        push(str[i]);

    printf("Reverse String is : ");
    for (i = 0; i < len; i++)
        pop();
}
