#include <stdio.h>
#include <stdlib.h>

int size;
int *queue;
int front = -1, rear = -1;

void enqueue_front(int x)
{
    if ((front == rear + 1) || (front == 0 && rear == size - 1))
        printf("Queue is Full\n");
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[front] = x;
    }
    else if (front == 0)
    {
        front = size - 1;
        queue[front] = x;
    }
    else
    {
        front--;
        queue[front] = x;
        printf("Element %d added successfully\n", queue[front]);
    }
}

void enqueue_rear(int x)
{
    if ((front == rear + 1) || (front == 0 && rear == size - 1))
        printf("Queue is Full\n");
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else if (rear == size - 1)
    {
        rear = 0;
        queue[rear] = x;
    }
    else
    {
        rear++;
        queue[rear] = x;
        printf("Element %d added successfully\n", queue[rear]);
    }
}

void DisplayDE()
{
    for (int i = front; i != rear;)
    {
        printf("%d ", queue[i]);
        i = (i + 1) % size;
    }
    printf("%d\n", queue[rear]);
}

// void getfront()
// {
//     if (front == -1 && rear == -1)
//         printf("Queue is Empty\n");
//     else
//         printf("%d\n", queue[front]);
// }

// void getrear()
// {
//     if (front == -1 && rear == -1)
//         printf("Queue is Empty\n");
//     else
//         printf("%d\n", queue[rear]);
// }

void dequeue_front()
{
    if (front == -1 && rear == -1)
        printf("Queue if Empty\n");
    else if (front == rear)
        front = rear = -1;
    else if (front == size - 1)
        front = 0;
    else
    {
        printf("Element %d deleted successfully\n", queue[front]);
        front++;
    }
}

void dequeue_rear()
{
    if (front == -1 && rear == -1)
        printf("Queue if Empty\n");
    else if (front == rear)
        front = rear = -1;
    else if (rear == 0)
        rear = size - 1;
    else
    {
        printf("Element %d deleted successfully\n", queue[rear]);
        rear--;
    }
}

void main()
{
    printf("Enter the Total size of Queue : ");
    scanf("%d", &size);

    queue = (int *)malloc(size * sizeof(int));

    int temp = 1;
    while (temp)
    {
        int choice;
        printf("1. Insert at front  2. Insert at rear  3. Delete at front  4. Delete at rear  5. Display  6. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            int x;
            printf("Enter the Data : ");
            scanf("%d", &x);
            enqueue_front(x);
            break;
        }
        case 2:
        {
            int x;
            printf("Enter the Data : ");
            scanf("%d", &x);
            enqueue_rear(x);
            break;
        }
        case 3:
            dequeue_front();
            break;
        case 4:
            dequeue_rear();
            break;
        case 5:
            DisplayDE();
            break;

        case 6:
            temp = 0;
            break;
        }
    }
}