#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct c_node
{
    int data;
    struct c_node *next;
};

struct c_node *c_head, *c_tail;
int ct = 0;

void Create_ll_Circular()
{
    struct c_node *newnode;
    c_head = NULL;
    c_tail = NULL;
    int n, i = 0;
    printf("Enter the total number of nodes which you want : ");
    scanf("%d", &n);
    while (n--)
    {
        i++;
        struct c_node *newnode;
        newnode = (struct c_node *)malloc(sizeof(struct c_node));
        printf("Enter the Value of element %d : ", i);
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (c_tail == NULL)
        {
            c_tail = newnode;
            c_tail->next = newnode;
        }
        else
        {
            newnode->next = c_tail->next;
            c_tail->next = newnode;
            c_tail = newnode;
        }
        ct++;
    }
}
void Insert_beginning_Circular()
{
    struct c_node *newnode;
    newnode = (struct c_node *)malloc(sizeof(struct c_node));
    printf("Enter the Value of element  : ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (c_tail == NULL)
    {
        c_tail = newnode;
        c_tail->next = newnode;
    }
    else
    {
        newnode->next = c_tail->next;
        c_tail->next = newnode;
    }
    ct++;
}
void Insert_end_Circular()
{
    struct c_node *newnode;
    newnode = (struct c_node *)malloc(sizeof(struct c_node));
    printf("Enter the Value of element : ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (c_tail == NULL)
    {
        c_tail = newnode;
        c_tail->next = newnode;
    }
    else
    {
        newnode->next = c_tail->next;
        c_tail->next = newnode;
        c_tail = newnode;
    }
    ct++;
}
void Insert_position_Circular()
{
    int pos, i = 1;
    printf("Enter the position at which you want to insert :  ");
    scanf("%d", &pos);
    if (pos < 0 || pos > ct)
    {
        printf("Invalid Position");
    }
    else if (pos == 1)
    {
        Insert_beginning_Circular();
    }
    else
    {
        struct c_node *newnode, *temp;
        newnode = (struct c_node *)malloc(sizeof(struct c_node));
        printf("Enter the value : ");
        scanf("%d", &newnode->data);
        temp = c_tail->next;
        while (i < (pos - 1))
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    ct++;
}
void Delete_beginning_Circular()
{
    struct c_node *temp;
    temp = c_tail->next;
    if (c_tail == NULL)
    {
        printf("Linked list is Empty\n");
    }
    else if (temp == c_tail)
    {
        c_tail = NULL;
        free(temp);
        ct--;
    }
    else
    {
        c_tail->next = temp->next;
        free(temp);
        ct--;
    }
}
void Delete_end_Circular()
{
    struct c_node *current, *previous;
    current = c_tail->next;
    if (c_tail == NULL)
    {
        printf("Linked list is Empty\n");
    }
    else if (current->next == current)
    {
        c_tail = NULL;
        free(current);
        ct--;
    }
    else
    {
        while (current->next != c_tail->next)
        {
            previous = current;
            current = current->next;
        }
        previous->next = c_tail->next;
        c_tail = previous;
        free(current);
        ct--;
    }
}
void Delete_position_Circular()
{
    int pos, i = 1;
    struct c_node *current, *nextnode;
    printf("Enter the position at which you want to delete : ");
    scanf("%d", &pos);
    current = c_tail->next;
    if (pos < 1 || pos > ct)
    {
        printf("Invalid Input\n");
    }
    else
    {
        while (i < (pos - 1))
        {
            current = current->next;
            i++;
        }
        nextnode = current->next;
        current->next = nextnode->next;
        free(nextnode);
    }
    ct--;
}
void Reverse_ll_Circular()
{
    struct c_node *previous, *current, *nextnode;
    current = c_tail->next;
    nextnode = current->next;
    while (current != c_tail)
    {
        previous = current;
        current = nextnode;
        nextnode = current->next;
        current->next = previous;
    }
    nextnode->next = c_tail;
    c_tail = nextnode;
}
void Display_ll_Circular()
{
    struct c_node *temp;
    temp = c_tail->next;
    while (temp->next != c_tail->next)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}
struct c_node *c_copy(struct c_node *temp)
{
    int i = 0;
    struct c_node *head, *tail, *oghead;
    oghead = temp;
    while (temp->next != oghead)
    {
        struct c_node *newnode;
        newnode = (struct c_node *)malloc(sizeof(struct c_node));
        newnode->next = 0;
        if (i == 0)
        {
            newnode->data = temp->data;
            head = tail = newnode;
            temp = temp->next;
            i++;
        }
        else
        {
            newnode->data = temp->data;
            tail->next = newnode;
            tail = newnode;
            temp = temp->next;
        }
    }
    struct c_node *newnode;
    newnode = (struct c_node *)malloc(sizeof(struct c_node));
    newnode->data = temp->data;
    tail->next = newnode;
    tail = newnode;
    newnode->next = head;

    return head;
}
void copy_c_display(struct c_node *temp)
{
    struct c_node *head;
    head = temp;
    while (temp->next != head)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

int main()
{
    int t = 1, choice;
    while (t)
    {
        printf(" 1.Create Linked list\t\t 2.Insert node at beginning\n 3.Insert node at end\t\t 4.Insert at any position\n 5.Delete node from beginning\t 6.Delete node from end\n 7.Delete node at any position\t 8.Reverse linked list\n 9.Display\t\t\t 10.Copy\n11.Exit");
        printf("\nWhich Operation You want to perform : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Create_ll_Circular();
            break;
        case 2:
            Insert_beginning_Circular();
            break;
        case 3:
            Insert_end_Circular();
            break;
        case 4:
            Insert_position_Circular();
            break;
        case 5:
            Delete_beginning_Circular();
            break;
        case 6:
            Delete_end_Circular();
            break;
        case 7:
            Delete_position_Circular();
            break;
        case 8:
            Reverse_ll_Circular();
            break;
        case 9:
            Display_ll_Circular();
            break;
        case 10:
        {
            struct c_node *dup = c_copy(c_head);
            copy_c_display(dup);
            break;
        }
        case 11:
            t = 0;
            break;
        }
    }
    return 0;
}