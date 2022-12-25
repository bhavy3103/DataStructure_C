#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int size; // declare global variable
int front = -1;
int rear = -1;
int *queue;

void EnqueueSin(int val) // insert function for Simple Queue
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

void DequeueSin() // Delete function for simple queue
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

void DisplaySin() // Display function for Simple queue
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

void EnqueueCir(int val) // Insert value for circular queue
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

void DequeueCir() // Delete Function for Circular queue
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
    }
}

void DisplayCir() // Display function for Circular Queue
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

void enqueue_front(int x) // Insert element at a front
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
    }
}

void enqueue_rear(int x) // Insert element at a rear
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
    }
}

void DisplayDE() // Display All element of Double Ended Queue
{
    for (int i = front; i != rear;)
    {
        printf("%d ", queue[i]);
        i = (i + 1) % size;
    }
    printf("%d\n", queue[rear]);
}

void dequeue_front() // Delete element from Front
{
    if (front == -1 && rear == -1)
        printf("Queue if Empty\n");
    else if (front == rear)
        front = rear = -1;
    else if (front == size - 1)
        front = 0;
    else
        front++;
}

void dequeue_rear() // Delete element from rear
{
    if (front == -1 && rear == -1)
        printf("Queue if Empty\n");
    else if (front == rear)
        front = rear = -1;
    else if (rear == 0)
        rear = size - 1;
    else
        rear--;
}

int main()
{
    int qc; // qc for queue choice
    printf("Enter the size of Queue Element : ");
    scanf("%d", &size);
    queue = (int *)malloc(size * sizeof(int)); // Dynamic memory allocation
    int t = 1, choice, choice2, choice3, v;
    while (t)
    {
        printf("1.Singly 2.Circular 3.Double Ended 4.Exit\n");
        printf("On Which queue you want to perform operation: ");
        scanf("%d", &qc);
        // apply switch cases for choose different Queue
        switch (qc)
        {
        case 1:
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
                    printf("Wrong input !! Try again\n");
                }
            }
        case 2:
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

                default:
                    printf("Wrong input !! Try again\n");
                }
            }
        case 3:
            while (t)
            {
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
                    printf("Queue is : ");
                    DisplayDE();
                    break;

                case 6:
                    t = 0;
                    break;

                default:
                    printf("Wrong input !! Try again\n");
                }
            }
        case 4:
            t = 0;
            break;

        default:
            printf("Wrong input !!! Try again\n");
        }
    }
    return 0;
}
