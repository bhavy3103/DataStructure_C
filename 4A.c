#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;
int ct = 0;

void Create_ll_simple()
{
    int n; // number of nodes
    printf("Enter The number of nodes which you want : ");
    scanf("%d", &n);

    head = NULL;
    struct node *new_node, *temp;

    int i = 1;
    while (n--)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        printf("Enter the value %d: ", i); // value given by user
        scanf("%d", &new_node->data);
        new_node->next = NULL;
        if (head == NULL)
        {
            head = temp = new_node;
            ct++;
        }
        else
        {
            temp->next = new_node;
            temp = new_node;
            ct++;
        }
        i++;
    }
}

void Insert_at_beginning()
{
    struct node *new_node, *temp;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value : ");
    scanf("%d", &new_node->data);
    temp = head;
    new_node->next = head;
    head = new_node;
    ct++;
}

void Insert_at_end()
{
    struct node *new_node, *temp;
    new_node = (struct node *)malloc(sizeof(struct node));
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    printf("Enter the value : ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    temp->next = new_node;
    ct++;
}

void Insert_any_position()
{
    int pos; // position given by user at which user want to insert node
    printf("Enter the position of node for insertion : ");
    scanf("%d", &pos);
    if (pos > ct)
    {
        printf("Please input valid position");
    }
    else
    {
        struct node *new_node, *temp;
        new_node = (struct node *)malloc(sizeof(struct node));
        temp = head;
        pos = pos - 1;
        while (pos--)
        {
            temp = temp->next;
        }
        printf("Enter the value: ");
        scanf("%d", &new_node->data);
        new_node->next = NULL;
        new_node->next = temp->next;
        temp->next = new_node;
        ct++;
    }
}

void Delete_at_beginning()
{
    if (head == NULL)
    {
        printf("Linked list is Empty");
    }
    else
    {
        struct node *temp;
        temp = head;
        head = head->next;
        free(temp);
        ct--;
    }
}

void Delete_at_end()
{
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    free(temp);
    ct--;
}

void Delete_any_position()
{
    int pos;
    printf("Enter the position for deletion here : ");
    scanf("%d", &pos);
    if (pos > ct)
    {
        printf("Please input valid position");
    }
    else
    {
        struct node *next_node, *temp;
        temp = head;
        int i = 1;
        while (i < (pos - 1))
        {
            temp = temp->next;
            i++;
        }
        next_node = temp->next;
        temp->next = next_node->next;
        free(next_node);
        ct--;
    }
}

void Reverse_ll_simple()
{
    struct node *prev_node, *current_node, *next_node;
    prev_node = NULL;
    current_node = next_node = head;
    while (next_node != NULL)
    {
        next_node = next_node->next;
        current_node->next = prev_node;
        prev_node = current_node;
        current_node = next_node;
    }
    head = prev_node;
}

void display_ll_simple()
{
    struct node *temp;
    temp = head;
    printf("Your linked list is : ");
    if (head == NULL)
    {
        printf("Linked list is empty\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main()
{

    int t = 1, choice;
    while (t)
    {
        printf(" 1.Create Linked list\t\t 2.Insert node at beginning\n 3.Insert node at end\t\t 4.Insert at any position\n 5.Delete node from beginning\t 6.Delete node from end\n 7.Delete node at any position\t 8.Reverse linked list\n 9.Display\t\t\t 10.Exit \n");
        printf("\nWhich Operation You want to perform : ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            Create_ll_simple();
            break;
        case 2:
            Insert_at_beginning();
            break;
        case 3:
            Insert_at_end();
            break;
        case 4:
            Insert_any_position();
            break;
        case 5:
            Delete_at_beginning();
            break;
        case 6:
            Delete_at_end();
            break;
        case 7:
            Delete_any_position();
            break;
        case 8:
            Reverse_ll_simple();
            break;
        case 9:
            display_ll_simple();
            break;
        case 10:
            t = 0;
            break;
        default:
            printf("Enter valid input!!!");
            break;
        }
    }
    return 0;
}