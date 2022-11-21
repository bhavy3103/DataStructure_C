// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <math.h>

// struct stack
// {
//     int size;
//     int top;
//     char *a;
// };
// int isEmpty(struct stack *ptr)
// {
//     if (ptr->top == -1)
//         return 1;
//     else
//         return 0;
// }

// int isFull(struct stack *ptr)
// {
//     if (ptr->top == ptr->size - 1)
//         return 1;
//     else
//         return 0;
// }

// void push(struct stack *ptr, int val)
// {
//     if (isFull(ptr))
//     {
//         printf("Stack is Overflow\n");
//     }
//     else
//     {
//         ptr->top++;
//         ptr->a[ptr->top] = val;
//     }
// }

// int pop(struct stack *ptr)
// {
//     if (isEmpty(ptr))
//     {
//         printf("Stack is Underflow\n");
//     }
//     else
//     {
//         int val = ptr->a[ptr->top];
//         ptr->top--;
//         return val;
//     }
// }

// void revstr(struct stack *ptr, int *a)
// {
// }

// int main()
// {
//     char s[100], a[100];
//     for (int i = 0; i != '\0'; i++)
//     {
//         scanf("%c", &s[i]);
//     }
//     struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
//     sp->size = 100;
//     sp->top = -1;
//     sp->a = (char *)malloc(sp->size * sizeof(char));
//     printf("string after reverse is : ");
//     for (int i = 1; i <= strlen(s); i++)
//     {
//         a[i] = pop(sp);
//     }
//     for (int i = 0; i < strlen(s); i++)
//     {
//         printf("%c", a[i]);
//     }

//     return 0;
// }

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