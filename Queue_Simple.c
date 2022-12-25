#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int size;
int front = -1;
int rear = -1;
int *queue;

void EnqueueSin(int val)
{
    if (rear == size - 1)
    {
        printf("Queue is Full");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = val;
        printf("Element %d added successfully\n", queue[rear]);
    }
}

void DequeueSin()
{
    if (front == rear)
    {
        printf("Queue is Underflow");
    }
    else
    {
        printf("Element %d deleted successfully\n", queue[front]);
        front++;
    }
}

void DisplaySin()
{
    if (rear == -1)
    {
        printf("Queue is Empty");
    }
    else
    {
        printf("Queue is : ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
}

int main()
{
    printf("Enter the Size of Queue elements : ");
    scanf("%d", &size);

    queue = (int *)malloc(size * sizeof(int));
    int choice, v;
    int t = 1;
    while (t)
    {
        printf("\n 1.Insert  2.Delete  3.Display  4.Back");
        printf("\n Enter Number corresponding to your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value here : ");
            scanf("%d", &v);
            EnqueueSin(v);
            break;

        case 2:
            DequeueSin();
            break;

        case 3:
            DisplaySin();
            break;

        case 4:
            t = 0;
            break;

        default:
            printf("Wrong input");
        }
    }

    return 0;
}
