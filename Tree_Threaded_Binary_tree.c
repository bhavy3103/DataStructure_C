
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
    int l_thread, r_thread;
};
// If l_thread=0 means have child
struct node *insert(struct node *root, int data)
{
    struct node *temp, *current, *node;
    temp = root;
    current = 0;
    while (temp != 0)
    {
        current = temp;
        if (data < temp->data)
        {
            if (temp->l_thread == 0)
                temp = temp->left;
            else
                break;
        }
        else
        {
            if (temp->r_thread == 0)
                temp = temp->right;
            else
                break;
        }
    }
    node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->l_thread = 1;
    node->r_thread = 1;

    if (current == 0)
    {
        root = node;
        node->left = 0;
        node->right = 0;
    }
    else if (data <= current->data)
    {
        node->left = current->left;
        node->right = current;
        current->l_thread = 0;
        current->left = node;
    }
    else
    {
        node->left = current;
        node->right = current->right;
        current->r_thread = 0;
        current->right = node;
    }
    return root;
}

struct node *inordersuccessor(struct node *temp)
{
    if (temp->r_thread == 1)
        return temp->right;

    temp = temp->right;
    while (temp->l_thread == 0)
        temp = temp->left;
    return temp;
}

void inorder(struct node *root)
{
    struct node *temp;
    if (root == 0)
        printf("\nTree is empty...!\n");
    else
    {
        temp = root;
        while (temp->l_thread == 0)
            temp = temp->left;
        printf("\n\nInorder traversal: ");
        while (temp != 0)
        {
            printf("%d ", temp->data);
            temp = inordersuccessor(temp);
        }
    }
}
int main()
{
    int choice, data;
    struct node *root;
    root = 0;
    int t = 1;
    while (t)
    {
        printf("\nWhich operation you want perform : ");
        printf("\n1. Insert");
        printf("\t2. Inorder traversal");
        printf("\t3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter data: ");
            scanf("%d", &data);
            root = insert(root, data);
            printf("Node inserted Successfully...\n");
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            t = 0;
            break;
        }
    }
}
