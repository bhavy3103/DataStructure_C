#include <stdio.h>
#include <stdlib.h>

struct node // create structure of node for AVL tree
{
    int data;
    struct node *left, *right;
    int height;
};

struct node *create(int data) //  create every node and give memory to newnode through DMA
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = newnode->right = 0;
    newnode->height = 1;
    return newnode;
}

int max(int a, int b) // find maximum value between two element
{
    if (a > b)
        return a;
    else
        return b;
}

int height(struct node *temp) // for finding height of tree using recursion and max function.
{
    if (temp == 0)
        return 0;
    return temp->height;
}

int balancefactore(struct node *temp) // calculate balance factor (height of left sub_tree- right sub_tree)
{
    if (temp == 0)
        return 0;
    else
        return height(temp->left) - height(temp->right);
}

struct node *rightrotate(struct node *root) // when L-L condition occur we use right rotation
{
    struct node *t1, *t2;
    t1 = root->left;
    t2 = t1->right;

    // Rotation
    t1->right = root;
    root->left = t2;

    // Updating Height
    root->height = max(height(root->left), height(root->right)) + 1;
    t1->height = max(height(t1->left), height(t1->right)) + 1;
    return t1;
}

struct node *leftrotate(struct node *root) // when R-R Condition occur we use left rotation
{
    struct node *t1, *t2;
    t1 = root->right;
    t2 = t1->left;

    // Rotation
    t1->left = root;
    root->right = t2;

    // Updating Height
    root->height = max(height(root->left), height(root->right)) + 1;
    t1->height = max(height(t1->left), height(t1->right)) + 1;
    return t1;
}

struct node *insert(struct node *root, int data) // insert node into tree
{
    if (root == 0)
        return create(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int BF = balancefactore(root);

    // Left Left case (ll)
    if (BF > 1 && data < root->left->data)
        return rightrotate(root);

    // Right Right case (rr)
    if (BF < -1 && data > root->right->data)
        return leftrotate(root);

    // Left Right case (lr)
    if (BF > 1 && data > root->left->data)
    {
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }

    // Right Left case (rl)
    if (BF < -1 && data < root->right->data)
    {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }
    return root;
}

void inorder(struct node *root) // inorder traversal
{
    if (root == 0)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct node *root) // preorder traversal
{
    if (root == 0)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void main()
{
    int choice, data;
    struct node *root = 0;

    while (1)
    {
        printf("\n1.Insert    2.In-order Traversal    3.Pre-order Traversal    4.Exit\n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            printf("Enter the Data : ");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        }
        case 2:
        {
            printf("\nIn-order Traversal : ");
            inorder(root);
            printf("\n");
            break;
        }
        case 3:
        {
            printf("\nPre-order Traversal : ");
            preorder(root);
            printf("\n");
            break;
        }
        case 4:
            exit(0);
        default:
            printf("Input invalid!!!!!");
        }
    }
}