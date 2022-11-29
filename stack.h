void push(int x, int *stack)
{
    if (top >= (n - 1))
    {
        printf("Stack is overflow\n");
    }
    else
    {
        top++;
        stack[top] = x;
    }
}

int pop(int *stack)
{
    if (top == -1)
    {
        printf("Stack underflow");
        return -1;
    }
    else
    {
        top--;
        return stack[top + 1];
    }
}

int peep(int *stack, int loc)
{
    if ((top + 1 - loc) <= -1)
    {
        printf("Stack underflow");
        return -1;
    }
    else
    {
        return stack[top - loc + 1];
    }
}

void change(int *stack, int loc, int x)
{
    if ((top + 1 - loc) <= 0)
    {
        printf("Stack underflow");
    }
    else
    {
        stack[top - loc + 1] = x;
    }
}

void display(int *stack, int temp)
{
    while (temp != -1)
    {
        printf("stack[%d] = %d\n", temp, stack[temp]);
        temp--;
    }
}
