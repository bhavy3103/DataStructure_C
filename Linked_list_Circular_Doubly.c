#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct dc_node
{
    int data;
    struct dc_node *prev;
    struct dc_node *next;
};

struct dc_node *dc_head, *dc_tail;
int ct = 0;

void Create_ll_DC()
{
    dc_head = NULL;
    dc_tail = NULL;
    int n, i = 0;
    printf("Enter the total number of nodes which you want : ");
    scanf("%d", &n);
    while (n--)
    {
        i++;
        struct dc_node *newnode;
        newnode = (struct dc_node *)malloc(sizeof(struct dc_node));
        printf("Enter the Value of element %d : ", i);
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;
        if (dc_head == NULL)
        {
            dc_head = dc_tail = newnode;
            dc_head->prev = newnode;
            dc_head->next = newnode;
        }
        else
        {
            dc_tail->next = newnode;
            newnode->prev = dc_tail;
            newnode->next = dc_head;
            dc_head->prev = newnode;
            dc_tail = newnode;
        }
        ct++;
    }
}
void Insert_beginning_DC()
{
    struct dc_node *newnode;
    newnode = (struct dc_node *)malloc(sizeof(struct dc_node));
    printf("Enter the Value of element : ");
    scanf("%d", &newnode->data);
    if (dc_head == NULL)
    {
        dc_head = dc_tail = newnode;
        dc_head->prev = newnode;
        dc_head->next = newnode;
    }
    else
    {
        newnode->next = dc_head;
        dc_head->prev = newnode;
        newnode->prev = dc_tail;
        dc_tail->next = newnode;
        dc_head = newnode;
    }
    ct++;
}
void Insert_end_DC()
{
    struct dc_node *newnode;
    newnode = (struct dc_node *)malloc(sizeof(struct dc_node));
    printf("Enter the Value of element : ");
    scanf("%d", &newnode->data);
    if (dc_head == NULL)
    {
        dc_head = dc_tail = newnode;
        dc_head->prev = newnode;
        dc_head->next = newnode;
    }
    else
    {
        newnode->prev = dc_tail;
        dc_tail->next = newnode;
        newnode->next = dc_head;
        dc_head->prev = newnode;
        dc_tail = newnode;
    }
    ct++;
}
void Insert_position_DC()
{
    int pos, i = 1;
    printf("Enter the position at which you want to insert :  ");
    scanf("%d", &pos);
    if (pos < 1 || pos > ct)
    {
        printf("Invalid Position\n");
    }
    else if (pos == 1)
    {
        Insert_beginning_DC();
    }
    else if (pos == ct)
    {
        Insert_end_DC();
    }
    else
    {
        struct dc_node *newnode, *temp;
        newnode = (struct dc_node *)malloc(sizeof(struct dc_node));
        printf("Enter the value : ");
        scanf("%d", &newnode->data);
        temp = dc_head;
        while (i < (pos - 1))
        {
            temp = temp->next;
            i++;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next->prev = newnode;
        temp->next = newnode;
    }
    ct++;
}
void Delete_beginning_DC()
{
    struct dc_node *temp;
    temp = dc_head;
    if (dc_head == NULL)
        printf("Linked list Empty\n");
    else if (dc_head == dc_tail)
    {
        dc_head = dc_tail = NULL;
        free(temp);
        ct--;
    }
    else
    {
        dc_head = dc_head->next;
        dc_head->prev = dc_tail;
        dc_tail->next = dc_head;
        free(temp);
        ct--;
    }
}
void Delete_end_DC()
{
    struct dc_node *temp;
    temp = dc_tail;
    if (dc_head == NULL)
    {
        printf("Linked list is empty\n");
    }
    else if (dc_head == dc_tail)
    {
        dc_head = dc_tail = 0;
        free(temp);
        ct--;
    }
    else
    {
        dc_tail = dc_tail->prev;
        dc_tail->next = dc_head;
        dc_head->prev = dc_tail;
        free(temp);
        ct--;
    }
}
void Delete_position_DC()
{
    int pos, i = 1;
    struct dc_node *current, *nextnode;
    printf("Enter the position at which you want to delete : ");
    scanf("%d", &pos);
    current = dc_tail->next;
    if (pos < 1 || pos > ct)
    {
        printf("Invalid Input\n");
    }
    else if (pos == 1)
        Delete_beginning_DC();
    else if (pos == ct)
        Delete_end_DC();
    else
    {
        struct dc_node *temp;
        temp = dc_head;
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
    ct--;
}
void Reverse_ll_DC()
{
    struct dc_node *current, *nextnode, *previous;
    current = nextnode = dc_head;
    while (current != dc_tail)
    {
        nextnode = current->next;
        current->next = current->prev;
        current->prev = nextnode;
        previous = current;
        current = nextnode;
    }
    current->next = previous;
    current->prev = dc_head;
    dc_head = dc_tail;
    dc_tail = current->prev;
}

struct dc_node *dc_copy(struct dc_node *temp)
{
    int i = 0;
    struct dc_node *oghead, *dc_head, *dc_tail;
    oghead = temp;
    while (temp->next != oghead)
    {
        struct dc_node *newnode;
        newnode = (struct dc_node *)malloc(sizeof(struct dc_node));
        newnode->prev = newnode->next = NULL;
        if (i == 0)
        {
            newnode->data = temp->data;
            dc_head = dc_tail = newnode;
            newnode->prev = newnode->next = dc_tail;
            temp = temp->next;
            i++;
        }
        else
        {
            newnode->data = temp->data;
            newnode->prev = dc_tail;
            dc_tail->next = newnode;
            dc_tail = newnode;
            dc_tail->next = dc_head;
            dc_head->prev = newnode;
            temp = temp->next;
        }
    }
    struct dc_node *newnode;
    newnode = (struct dc_node *)malloc(sizeof(struct dc_node));
    newnode->data = temp->data;
    newnode->prev = dc_tail;
    dc_tail->next = newnode;
    dc_tail = newnode;
    dc_tail->next = dc_head;
    dc_head->prev = newnode;

    return dc_head;
}

void copy_dc_display(struct dc_node *temp)
{
    struct dc_node *dc_head;
    dc_head = temp;
    while (temp->next != dc_head)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

void Display_ll_DC()
{
    struct dc_node *temp;
    temp = dc_head;
    while (temp != dc_tail)
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
        printf(" 1.Create Linked list\t\t\t 2.Insert node at beginning\n 3.Insert node at end\t\t 4.Insert at any position\n 5.Delete node from beginning\t 6.Delete node from end\n 7.Delete node at any position\t 8.Reverse linked list\n 9.Display\t\t\t\t 10.Copy \n 11.Exit\n");
        printf("\nWhich Operation You want to perform : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Create_ll_DC();
            break;
        case 2:
            Insert_beginning_DC();
            break;
        case 3:
            Insert_end_DC();
            break;
        case 4:
            Insert_position_DC();
            break;
        case 5:
            Delete_beginning_DC();
            break;
        case 6:
            Delete_end_DC();
            break;
        case 7:
            Delete_position_DC();
            break;
        case 8:
            Reverse_ll_DC();
            break;
        case 9:
            Display_ll_DC();
            break;
        case 10:
        {
            struct dc_node *dup = dc_copy(dc_head);
            copy_dc_display(dup);
            break;
        }
        case 11:
            t = 0;
            break;
        }
    }
    return 0;
}