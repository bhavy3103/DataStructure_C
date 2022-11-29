void push(char ch)
{
    top++;
    stack[top] = ch;
}

char pop()
{
    if (top == -1)
    {
        return -1;
    }
    else
    {
        top--;
        return stack[top + 1];
    }
}

char peek()
{
    if (top >= (n - 1))
    {
        printf("Stack is overflow\n");
    }
    if (top == -1)
    {
        return -1;
    }
    return stack[top];
}
