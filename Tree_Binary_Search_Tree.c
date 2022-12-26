#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root;

int max(int x, int y)
{
    if (x >= y)
        return x;
    else
        return y;
}

struct node *create(int x)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = x;
    new_node->left = new_node->right = NULL;
    return new_node;
}

struct node *Insert(struct node *root, int x)
{
    if (root == NULL)
        root = create(x);
    else if (root->data >= x)
        root->left = Insert(root->left, x);
    else
        root->right = Insert(root->right, x);
    return root;
}

int Search(struct node *root, int x)
{
    if (root == NULL)
        return 0;
    else if (x == root->data)
        return 1;
    else if (x <= root->data)
        return Search(root->left, x);
    else
        return Search(root->right, x);
}

void Inorder(struct node *root)
{
    if (root == NULL)
        return;
    Inorder(root->left);
    printf("%d ", root->data);
    Inorder(root->right);
}

void Postorder(struct node *root)
{
    if (root == NULL)
        return;
    Postorder(root->left);
    Postorder(root->right);
    printf("%d ", root->data);
}

void Preorder(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    Preorder(root->left);
    Preorder(root->right);
}

void Traverse(struct node *root)
{
    int k = 1, ch;
    while (k)
    {
        printf("1.Inorder\t 2.Postorder\t 3.Preorder\t 4.Exit\n");
        printf("Enter Your Choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Inorder is : ");
            Inorder(root);
            printf("\n");
            break;
        case 2:
            printf("Postorder is : ");
            Postorder(root);
            printf("\n");
            break;
        case 3:
            printf("Preorder is : ");
            Preorder(root);
            printf("\n");
            break;
        case 4:
            k = 0;
            break;
        default:
            printf("Invalid Input !!!!\n");
            break;
        }
    }
}

struct node *pre_max(struct node *root)
{
    while (root->right != NULL)
        root = root->right;
    return root;
}

struct node *acc_min(struct node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct node *Delete(struct node *root, int k)
{
    if (root == NULL)
        return root;
    else if (k < root->data)
        root->left = Delete(root->left, k);
    else if (k > root->data)
        root->right = Delete(root->right, k);
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        else if (root->left == NULL)
        {
            struct node *temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            struct node *temp = root;
            root = root->left;
            free(temp);
        }
        else
        {
            int c;
            printf("From which you want to delete 1.Predeccesor\t 2.Accessor\t 3.Exit\n ");
            printf("Enter your choice : ");
            scanf("%d", &c);
            struct node *temp;
            switch (c)
            {
            case 1:
                temp = pre_max(root->left);
                root->data = temp->data;
                root->left = Delete(root->left, temp->data);
                break;
            case 2:
                temp = acc_min(root->right);
                root->data = temp->data;
                root->right = Delete(root->right, temp->data);
                break;
            default:
                printf("Invalid Input!!!!\n");
                break;
            }
        }
    }
    return root;
}

int height(struct node *root)
{
    int l, r;
    if (root == 0)
        return -1;
    l = height(root->left);
    r = height(root->right);
    return max(l, r) + 1;
}

int total_nodes(struct node *root)
{
    int ct = 0;
    if (root != NULL)
    {
        ct++;
        ct += total_nodes(root->left);
        ct += total_nodes(root->right);
    }
    return ct;
}

int leaf_nodes(struct node *root)
{
    if (root = NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    else
        return leaf_nodes(root->left) + leaf_nodes(root->right);
}

void Count_nodes(struct node *root)
{
    int total, internal, leaf;
    total = total_nodes(root);
    leaf = leaf_nodes(root);
    internal = total - leaf;
    printf("Total number of nodes : %d\n", total);
    printf("Total number of internal nodes : %d\n", internal);
    printf("Total number of leaf nodes : %d\n", leaf);
}
int main()
{
    int t = 1, choice;
    while (t)
    {
        printf("1.Insert\t 2.Search\t 3.Traverse\t 4.Delete\t 5.Height of tree\t 6.Count Node\t 7.Exit\n");
        printf("Enter the Which operation You want to perform: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            int data;
            printf("Enter the Data Value : ");
            scanf("%d", &data);
            root = Insert(root, data);
            break;
        }
        case 2:
        {
            int data, p;
            printf("Enter the data value to search : ");
            scanf("%d", &data);
            p = Search(root, data);
            if (p == 1)
                printf("Data is Found\n");
            else
                printf("Data is not Found\n");
            break;
        }
        case 3:
            Traverse(root);
            break;
        case 4:
        {
            int k;
            printf("Enter the Value which you want to delete : ");
            scanf("%d", &k);
            Delete(root, k);
            break;
        }
        case 5:
        {
            int h;
            h = height(root);
            printf("Height of Tree is : %d \n", h);

            break;
        }
        case 6:
            Count_nodes(root);
            break;
        case 7:
            t = 0;
            break;

        default:
            break;
        }
    }

    return 0;
}