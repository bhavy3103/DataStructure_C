#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int size;
int front = -1;
int rear = -1;
int *queue;

void EnqueueCir(int val)
{
    if ((front == rear + 1) || (front == 0 && rear == size - 1))
    {
        printf("Queue is Full");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % size;
        queue[rear] = val;
        printf("Element %d added successfully\n", queue[rear]);
    }
    return;
}

void DequeueCir()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is Underflow");
    }
    else
    {
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
        printf("Element %d deleted successfully\n", queue[front - 1]);
        // front++;
    }
}

void DisplayCir()
{
    if (rear == -1)
    {
        printf("Queue is Empty");
    }
    else
    {
        printf("Queue is : ");
        if (front <= rear)
        {
            for (int i = front; i <= rear; i++)
            {
                printf("%d ", queue[i]);
            }
        }
        else
        {
            for (int i = front; i < size; i++)
            {
                printf("%d ", queue[i]);
            }
            for (int i = 0; i <= rear; i++)
            {
                printf("%d ", queue[i]);
            }
        }
    }
}
int main()
{
    printf("Enter the size of Queue element :");
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
            EnqueueCir(v);
            break;

        case 2:
            DequeueCir();
            break;

        case 3:
            DisplayCir();
            break;

        case 4:
            t = 0;
            break;
        }
    }
    return 0;
}
