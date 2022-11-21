#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct stack
{
    int size;
    int top;
    int *a;
};
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    else
        return 0;
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
        return 1;
    else
        return 0;
}

void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack is Overflow\n");
    }
    else
    {
        ptr->top++;
        ptr->a[ptr->top] = val;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is Underflow\n");
    }
    else
    {
        int val = ptr->a[ptr->top];
        ptr->top--;
        return val;
    }
}

int peep(struct stack *ptr, int loc)
{
    int val = ptr->a[ptr->top - loc + 1];
    return val;
}

int change(struct stack *ptr, int loc, int new_val)
{
    int val = ptr->a[ptr->top - loc + 1];
    ptr->a[ptr->top - loc + 1] = new_val;
    val = new_val;
    return val;
}

void display(struct stack *ptr, int *a)
{
    for (int i = 1; i <= ptr->top + 1; i++)
    {
        printf("%d\n", ptr->a[ptr->top - i + 1]);
    }
}

int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->a = (int *)malloc(sp->size * sizeof(int));
    while (1)
    {
        int n, v, pos, nval;
        printf("\n1.Push 2.Pop 3.Peep 4.Change 5.Display\n");
        printf("Enter Number corrsponding to operation which you want ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Enter a number : ");
            scanf("%d", &v);
            push(sp, v);
            printf("Element added successfully\n");
            break;

        case 2:
            printf("Element %d is popped successfully\n", pop(sp));
            break;

        case 3:
            printf("Enter position of element : ");
            scanf("%d", &pos);
            printf("Element at location %d from the top is %d\n", pos, peep(sp, pos));
            break;

        case 4:
            printf("Enter position of element : ");
            scanf("%d", &pos);
            printf("Enter New Value at position %d is : ", pos);
            scanf("%d", &nval);
            printf("Element %d successfully added at position %d\n", change(sp, pos, nval), pos);
            break;

        case 5:
            printf("Elements in the stack are\n");
            display(sp, sp->a);
        }
    }

    return 0;
}