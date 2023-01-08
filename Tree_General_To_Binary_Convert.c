#include <stdio.h>
#include <stdlib.h>

struct node // create structure of node ... Doubly linkedlist
{
    int data;
    struct node *left, *right;
};

struct info // structure information like level and value of data
{
    int level;
    struct node *loc;
};

struct info stack[100]; // create stack globally for storing value
int top = -1;

struct info push(struct info c) // push int into stack and return stack's top value
{
    top++;
    stack[top] = c;
    return stack[top];
}

void pop() // delete top value
{
    top--;
}

struct info peek() // give stack's top value
{
    return stack[top];
}

void preorder(struct node *root) // preorder traversal
{
    if (root == 0)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node *root) // inorder traversal
{
    if (root == 0)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(struct node *root) // postorder traversal
{
    if (root == 0)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void main()
{
    int n, i, level;
    char data;
    struct node *root, *newnode;
    struct info pred, a;
    printf("\nEnter Data in Pre-Order Sequence\n");
    printf("Enter Total no. of nodes : ");
    scanf("%d", &n);

    root = (struct node *)malloc(sizeof(struct node));
    root->left = 0;
    root->right = 0;
    a.level = -1;
    a.loc = root;
    push(a);

    for (i = 0; i < n; i++)
    {
        printf("Enter the Level & Data : ");
        fflush(stdin);
        scanf("%d %d", &level, &data);
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->left = 0, newnode->right = 0;
        newnode->data = data;

        pred = peek();
        if (pred.level < level) // Child node
            pred.loc->left = newnode;
        else
        {
            while (pred.level > level)
            {
                pop(); // Pop until we get sibling
                pred = peek();
            }
            if (pred.level < level)
            {
                printf("\nError in Input !!\n");
                return;
            }
            pred.loc->right = newnode; // Adding sibling to right
            pop();
        }
        a.level = level;
        a.loc = newnode;
        push(a);
    }
    printf("\nPre-order of Binary Tree : ");
    preorder(root);
    printf("\nInorder of Binary Tree : ");
    inorder(root);
    printf("\nPost-order of Binary Tree : ");
    postorder(root);
}