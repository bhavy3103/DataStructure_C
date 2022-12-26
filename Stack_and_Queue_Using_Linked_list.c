#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;
int size, ct = 0;

void push()
{
    int x;
    if (size - ct <= 0)
        printf("Stack is Overflow\n");
    else
    {
        printf("Enter the Value : ");
        scanf("%d", &x);
        struct node *new_node;
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->prev = new_node->next = NULL;
        new_node->data = x;
        if (head == NULL)
        {
            head = tail = new_node;
        }
        else
        {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
        ct++;
    }
}
void pop()
{
    if (ct == 0)
        printf("Stack is Underflow!!\n");
    else
    {
        struct node *temp;
        temp = tail;
        temp->prev->next = NULL;
        tail = temp->prev;
        printf("Poped Value is : %d\n", temp->data);
        free(temp);
        ct--;
    }
}
void peak()
{
    if (ct == 0)
        printf("Stack is Underflow!!\n");
    else
    {
        printf("Top Value is : ");
        printf("%d\n", tail->data);
    }
}
void peep()
{
    int pos, j;
    struct node *temp;
    temp = tail;
    printf("Enter the position from the top : ");
    scanf("%d", &pos);
    if (pos > ct)
        printf("Invalid Position!!!\n");
    else
    {
        j = pos - 1;
        while (j--)
        {
            temp = temp->prev;
        }
        printf("Value at position %d from top is : %d \n", pos, temp->data);
    }
}
void DisplayS()
{
    struct node *temp;
    temp = tail;
    if (ct == 0)
        printf("Stack is Empty\n");
    else
    {
        printf("Stack is : \n");
        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->prev;
        }
    }
}
void Insert()
{
    int x;
    if (size - ct <= 0)
        printf("Queue is Full\n");
    else
    {
        printf("Enter the Value : ");
        scanf("%d", &x);
        struct node *new_node;
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->prev = new_node->next = NULL;
        new_node->data = x;
        if (head == NULL)
        {
            head = tail = new_node;
        }
        else
        {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
        ct++;
    }
}
void Delete()
{
    if (ct == 0)
        printf("Queue is Empty!!!");
    else
    {
        struct node *temp;
        temp = head;
        head = temp->next;
        temp->prev = NULL;
        printf("Deleted element is : %d\n", temp->data);
        free(temp);
    }
}
void DisplayQ()
{
    if (ct == 0)
        printf("Queue is Empty!!");
    else
    {
        struct node *temp;
        temp = head;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void stack()
{
    printf("Enter the Size of Stack : ");
    scanf("%d", &size);
    int k = 1;
    while (k)
    {
        int choice;
        printf("1.Push\t 2.Pop\t 3.Peak\t 4.Peep\t 5.Display\t 6.Exit\n");
        printf("Which operation you want to perform : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peak();
            break;
        case 4:
            peep();
            break;
        case 5:
            DisplayS();
            break;
        case 6:
            k = 0;
            break;
        default:
        {
            printf("Invalid Input !!!");
            break;
        }
        }
    }
}

void queue()
{
    printf("Enter the Size of Queue : ");
    scanf("%d", &size);
    int p = 1;
    while (p)
    {
        int choice;
        printf("1.Inset\t 2.Delete\t 3.Display\t 4.Exit\n");
        printf("Enter Which operation you want to perform : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Insert();
            break;
        case 2:
            Delete();
            break;
        case 3:
            DisplayQ();
            break;
        case 4:
            p = 0;
            break;
        default:
            printf("Invalid Input\n");
            break;
        }
    }
}

int main()
{
    int t = 1, ch;
    while (t)
    {
        printf("1.Stack\t2.Queue\t3.Exit\n");
        printf("Enter the Which you want to perform : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            stack();
            break;
        case 2:
            queue();
            break;
        case 3:
            t = 0;
            break;
        default:
            printf("plz give correct input !!!");
            break;
        }
    }
}
