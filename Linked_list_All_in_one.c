#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int ct = 0; // declare ct for counting nodes

struct s_node // declare node for singly linked list
{
    int data;
    struct s_node *next;
};

struct s_node *s_head;

void Create_ll_simple() // create singly linked list
{
    int n; // number of nodes
    printf("Enter The number of nodes which you want : ");
    scanf("%d", &n);

    s_head = NULL;
    struct s_node *new_node, *temp; // temp for traversing

    int i = 1; // int i for give number to node
    while (n--)
    {
        new_node = (struct s_node *)malloc(sizeof(struct s_node));
        printf("Enter the value %d: ", i); // value given by user
        scanf("%d", &new_node->data);
        new_node->next = NULL;
        if (s_head == NULL)
        {
            s_head = temp = new_node;
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

void Insert_beginning_Simple() // function which insert node at begin
{
    struct s_node *new_node, *temp;
    new_node = (struct s_node *)malloc(sizeof(struct s_node));
    printf("Enter the value : ");
    scanf("%d", &new_node->data);
    temp = s_head;
    new_node->next = s_head;
    s_head = new_node;
    ct++;
}

void Insert_end_Simple() // function which insert node at the end
{
    struct s_node *new_node, *temp;
    new_node = (struct s_node *)malloc(sizeof(struct s_node));
    temp = s_head;
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

void Insert_position_Simple() // function which insert node at any specific position
{
    int pos; // position given by user at which user want to insert node
    printf("Enter the position of node for insertion : ");
    scanf("%d", &pos);
    if (pos > ct)
    {
        printf("Please input valid position\n");
    }
    else
    {
        struct s_node *new_node, *temp;
        new_node = (struct s_node *)malloc(sizeof(struct s_node));
        temp = s_head;
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

void Delete_beginning_Simple() // function which Delete node at begin
{
    if (s_head == NULL)
    {
        printf("Linked list is Empty\n");
    }
    else
    {
        struct s_node *temp;
        temp = s_head;
        s_head = s_head->next;
        free(temp);
        ct--;
    }
}

void Delete_end_Simple() // function which Delete node at end
{
    struct s_node *temp;
    temp = s_head;
    while (temp != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    free(temp);
    ct--;
}

void Delete_position_Simple() // function which Delete node at any specific Position
{
    int pos;
    printf("Enter the position for deletion here : ");
    scanf("%d", &pos);
    if (pos > ct)
    {
        printf("Please input valid position\n");
    }
    else
    {
        struct s_node *next_node, *temp;
        temp = s_head;
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

void Reverse_ll_simple() // to Reverse singly linked list
{
    struct s_node *prev_node, *current_node, *next_node;
    prev_node = NULL;
    current_node = next_node = s_head;
    while (next_node != NULL)
    {
        next_node = next_node->next;
        current_node->next = prev_node;
        prev_node = current_node;
        current_node = next_node;
    }
    s_head = prev_node;
}

void Display_ll_Simple() // to Display Singly Linked list
{
    struct s_node *temp;
    temp = s_head;
    printf("Your linked list is : ");
    if (s_head == NULL)
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

struct s_node *s_copy(struct s_node *s_head) // declare s_node for make copy of Linked list
{
    if (s_head == 0)
        return 0;
    else
    {
        struct s_node *newnode;
        newnode = (struct s_node *)malloc(sizeof(struct s_node));
        newnode->data = s_head->data;
        newnode->next = s_copy(s_head->next);
        return newnode;
    }
}

void copy_s_display(struct s_node *temp) // function which display copied linked list
{
    printf("Copied Linked list is : ");
    while (temp != 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct c_node // declare c_node for circular
{
    int data;
    struct c_node *next;
};

struct c_node *c_head, *c_tail;

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
    struct c_node *head, *tail, *oghead; // declare oghead for get access of original head
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

struct d_node // declare d node for doubly linked list
{
    int data;
    struct d_node *prev;
    struct d_node *next;
};

struct d_node *d_head, *d_tail;

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

struct dc_node // declare dc_node for doubly circular linked list
{
    int data;
    struct dc_node *prev;
    struct dc_node *next;
};

struct dc_node *dc_head, *dc_tail;

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
    int k = 1, ch;
    while (k)
    {
        printf("1.Singly\t 2.Circular\t 3.Doubly\t 4.Doubly Circular\t 5.Exit\n");
        printf("In Which Linked list you want perform operations choose number according to that : ");
        scanf("%d", &ch);
        int t = 1, choice;
        while (t)
        {
            printf("\n\n1.Create Linked list\t\t 2.Insert node at beginning\n 3.Insert node at end\t\t 4.Insert at any position\n 5.Delete node from beginning\t 6.Delete node from end\n 7.Delete node at any position\t 8.Reverse linked list\n 9.Display\t\t\t 10.Copy\n 11.Exit");
            printf("\n\nWhich Operation You want to perform : ");
            scanf("%d", &choice);
            printf("\n");
            switch (choice)
            {
            case 1:
            {
                if (ch == 1)
                    Create_ll_simple();
                else if (ch == 2)
                    Create_ll_Circular();
                else if (ch == 3)
                    Create_ll_Doubly();
                else if (ch == 4)
                    Create_ll_DC();
            }
            break;
            case 2:
            {
                if (ch == 1)
                    Insert_beginning_Simple();
                else if (ch == 2)
                    Insert_beginning_Circular();
                else if (ch == 3)
                    Insert_beginning_Doubly();
                else if (ch == 4)
                    Insert_beginning_DC();
            }
            break;
            case 3:
            {
                if (ch == 1)
                    Insert_end_Simple();
                else if (ch == 2)
                    Insert_end_Circular();
                else if (ch == 3)
                    Insert_end_Doubly();
                else if (ch == 4)
                    Insert_end_DC();
            }
            break;
            case 4:
            {
                if (ch == 1)
                    Insert_position_Simple();
                else if (ch == 2)
                    Insert_position_Circular();
                else if (ch == 3)
                    Insert_position_Doubly();
                else if (ch == 4)
                    Insert_position_DC();
            }
            break;
            case 5:
            {
                if (ch == 1)
                    Delete_beginning_Simple();
                else if (ch == 2)
                    Delete_beginning_Circular();
                else if (ch == 3)
                    Delete_beginning_Doubly();
                else if (ch == 4)
                    Delete_beginning_DC();
            }
            break;
            case 6:
            {
                if (ch == 1)
                    Delete_end_Simple();
                else if (ch == 2)
                    Delete_end_Circular();
                else if (ch == 3)
                    Delete_end_Doubly();
                else if (ch == 4)
                    Delete_end_DC();
            }
            break;
            case 7:
            {
                if (ch == 1)
                    Delete_position_Simple();
                else if (ch == 2)
                    Delete_position_Circular();
                else if (ch == 3)
                    Delete_position_Doubly();
                else if (ch == 4)
                    Delete_position_DC();
            }
            break;
            case 8:
            {
                if (ch == 1)
                    Reverse_ll_simple();
                else if (ch == 2)
                    Reverse_ll_Circular();
                else if (ch == 3)
                    Reverse_ll_Doubly();
                else if (ch == 4)
                    Reverse_ll_DC();
            }
            break;
            case 9:
            {
                if (ch == 1)
                    Display_ll_Simple();
                else if (ch == 2)
                    Display_ll_Circular();
                else if (ch == 3)
                    Display_ll_Doubly();
                else if (ch == 4)
                    Display_ll_DC();
            }
            break;
            case 10:
            {
                if (ch == 1)
                {
                    struct s_node *dup = s_copy(s_head);
                    copy_s_display(dup);
                }
                else if (ch == 2)
                {
                    struct c_node *dup = c_copy(c_head);
                    copy_c_display(dup);
                }
                else if (ch == 3)
                {
                    struct d_node *dup = d_copy(d_head);
                    copy_d_display(dup);
                }
                else if (ch == 4)
                {
                    struct dc_node *dup = dc_copy(dc_head);
                    copy_dc_display(dup);
                }
            }
            break;
            case 11:
                t = 0;
                break;
            default:
                printf("Invalid Input!! please give correct Input");
            }
            if (ch == 5)
            {
                k = 0;
                break;
            }
        }
    }
    return 0;
}
