#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct d_node
{
    int data;
    struct d_node *prev;
    struct d_node *next;
};

struct d_node *d_head, *d_tail;
int ct = 0;

void Create_ll_Doubly()
{
    d_head = NULL;
    d_tail = NULL;
    int n, i = 0;
    printf("Enter the total number of nodes which you want : ");
    scanf("%d", &n);
    while (n--)
    {
        i++;
        struct d_node *newnode;
        newnode = (struct d_node *)malloc(sizeof(struct d_node));
        printf("Enter the Value of element %d : ", i);
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;
        if (d_head == NULL)
        {
            d_head = d_tail = newnode;
        }
        else
        {
            d_tail->next = newnode;
            newnode->prev = d_tail;
            d_tail = newnode;
        }
        ct++;
    }
}

void Insert_beginning_Doubly()
{
    struct d_node *newnode;
    newnode = (struct d_node *)malloc(sizeof(struct d_node));
    printf("Enter the value : ");
    scanf("%d", &newnode->data);
    newnode->prev = newnode->next = NULL;
    if (d_head == NULL)
    {
        d_head = newnode;
    }
    else
    {
        d_head->prev = newnode;
        newnode->next = d_head;
        d_head = newnode;
    }
    ct++;
}

void Insert_end_Doubly()
{
    struct d_node *newnode, *temp;
    newnode = (struct d_node *)malloc(sizeof(struct d_node));
    printf("Enter the value : ");
    scanf("%d", &newnode->data);
    newnode->prev = newnode->next = NULL;
    d_tail->next = newnode;
    newnode->prev = d_tail;
    d_tail = newnode;
    ct++;
}

void Insert_position_Doubly()
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
        Insert_beginning_Doubly();
    }
    else
    {
        struct d_node *newnode, *temp;
        newnode = (struct d_node *)malloc(sizeof(struct d_node));
        printf("Enter the value : ");
        scanf("%d", &newnode->data);
        temp = d_head;
        while (i < (pos - 1))
        {
            temp = temp->next;
            i++;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;
        newnode->next->prev = newnode;
        ct++;
    }
}
void Delete_beginning_Doubly()
{
    struct d_node *temp;
    if (d_head == NULL)
        printf("Linked list is Empty\n ");
    else
    {
        temp = d_head;
        d_head = d_head->next;
        d_head->prev = NULL;
        free(temp);
    }
    ct--;
}
void Delete_end_Doubly()
{
    struct d_node *temp;
    if (d_tail == NULL)
        printf("Linked list is Empty \n");
    else
    {
        temp = d_tail;
        d_tail->prev->next = 0;
        d_tail = d_tail->prev;
        free(temp);
    }
    ct--;
}
void Delete_position_Doubly()
{
    int pos, i = 1;
    struct d_node *temp;
    printf("Enter the position at which you want to Delete :  ");
    scanf("%d", &pos);
    temp = d_head;
    while (i < pos)
    {
        temp = temp->next;
        i++;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    ct--;
}

void Display_ll_Doubly()
{
    struct d_node *temp;
    if (d_head == NULL)
    {
        printf("Linked list is Empty!!!");
    }
    else
    {
        temp = d_head;
        printf("Your linked list is : ");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void Reverse_ll_Doubly()
{
    struct d_node *currentnode, *nextnode;
    currentnode = d_head;
    while (currentnode != NULL)
    {
        nextnode = currentnode->next;
        currentnode->next = currentnode->prev;
        currentnode->prev = nextnode;
        currentnode = nextnode;
    }
    currentnode = d_head;
    d_head = d_tail;
    d_tail = currentnode;
}
struct d_node *d_copy(struct d_node *temp)
{
    int i = 0;
    struct d_node *head, *tail;
    while (temp->next != 0)
    {
        struct d_node *newnode;
        newnode = (struct d_node *)malloc(sizeof(struct d_node));
        newnode->next = newnode->prev = 0;
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
            newnode->prev = tail;
            tail = newnode;
            temp = temp->next;
        }
    }
    struct d_node *newnode;
    newnode = (struct d_node *)malloc(sizeof(struct d_node));
    newnode->next = newnode->prev = 0;
    newnode->data = temp->data;
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;

    return head;
}
void copy_d_display(struct d_node *temp)
{
    printf("Copied Linked List is : ");
    while (temp->next != 0)
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
        printf(" 1.Create Linked list\t\t 2.Insert node at beginning\n 3.Insert node at end\t\t 4.Insert at any position\n 5.Delete node from beginning\t 6.Delete node from end\n 7.Delete node at any position\t 8.Reverse linked list\n 9.Display\t\t\t 10.Copy\n 11.Exit");
        printf("\nWhich Operation You want to perform : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Create_ll_Doubly();
            break;
        case 2:
            Insert_beginning_Doubly();
            break;
        case 3:
            Insert_end_Doubly();
            break;
        case 4:
            Insert_position_Doubly();
        case 5:
            Delete_beginning_Doubly();
            break;
        case 6:
            Delete_end_Doubly();
            break;
        case 7:
            Delete_position_Doubly();
            break;
        case 8:
            Reverse_ll_Doubly();
            break;
        case 9:
            Display_ll_Doubly();
            break;
        case 10:
        {
            struct d_node *dup = d_copy(d_head);
            copy_d_display(dup);
            break;
        }
        case 11:
            t = 0;
            break;
        }
    }

    return 0;
}