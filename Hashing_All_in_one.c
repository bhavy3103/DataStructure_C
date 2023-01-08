#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
int size = 10;
node *si_insert(node *head, int x, int n)
{
    node *temp = head;
    node *t;
    if (n == 1)
    {
        t = (node *)malloc(sizeof(node));
        t->data = x;
        t->next = head;
        return t;
    }
    while (n != 2)
    {
        if (temp == NULL)
        {
            printf("Invalid Position\n");
            return head;
        }
        temp = temp->next;
        n--;
    }
    if (temp)
    {
        t = (node *)malloc(sizeof(node));
        t->data = x;
        t->next = temp->next;
        temp->next = t;
    }
    else
    {
        printf("Invalid Position\n");
    }
    return head;
}
node *si_insertend(node *head, int x)
{
    if (head == NULL)
    {
        head = si_insert(head, x, 1);
    }
    else
    {
        node *t = head;
        while (t->next)
        {
            t = t->next;
        }
        t->next = (node *)malloc(sizeof(node));
        t = t->next;
        t->data = x;
        t->next = NULL;
    }
    return head;
}
int divhash(int key)
{
    return key % size;
}
int mulhash(int key)
{
    int A = 0.5 * key;
    return A % size;
}
int midsquarehash(int key)
{
    int i = key * key;
    int t = i, j = 0, k = i;
    while (t > 0)
    {
        t /= 10;
        j++;
    }
    for (t = 0; t < j / 2; t++)
    {
        k /= 10;
    }
    return k % size;
}
int foldinghash(int key)
{
    int i = 0;
    while (key > size)
    {
        i += key % 10;
        key /= 10;
    }
    if (i > size)
    {
        return foldinghash(i);
    }
    else
    {
        return i;
    }
}
int linearprobing(int key, node **list)
{
    int i = 0;
    while (list[(key + i) % size] != NULL)
    {
        i++;
    }
    return (key + i) % size;
}
int quadraticprobing(int key, node **list)
{
    int i = 0;
    while (list[(key + (i * i)) % size] != NULL)
    {
        i++;
    }
    return (key + (i * i)) % size;
}
int doublehash(int key, node **list)
{
    int i = 0;
    while (list[(divhash(key) + i * (7 - (key % 7))) % size] != NULL)
    {
        i++;
    }
    return (divhash(key) + i * (7 - (key % 7))) % size;
}
void rehash(node **list, int ch, int ch2)
{
    int i, k = 0, key;
    int arr[50];
    node **temp = list;
    for (i = 0; i < size; i++)
    {
        node *temp = list[i];
        while (temp)
        {
            arr[k] = temp->data;
            temp = temp->next;
            k++;
        }
        list[i] = NULL;
    }
    for (int j = 0; j < k; j++)
    {
        switch (ch)
        {
        case 1:
            if (ch2 == 1)
                key = linearprobing(divhash(arr[j]), list);
            else if (ch2 == 2)
                key = quadraticprobing(divhash(arr[j]), list);
            else if (ch2 == 3)
                key = doublehash(arr[j], list);
            list[key] = si_insertend(list[key], arr[j]);
            break;
        case 2:
            if (ch2 == 1)
                key = linearprobing(mulhash(arr[j]), list);
            else if (ch2 == 2)
                key = quadraticprobing(mulhash(arr[j]), list);
            else if (ch2 == 3)
                key = doublehash(arr[j], list);
            list[key] = si_insertend(list[key], arr[j]);
            break;
        case 3:
            if (ch2 == 1)
                key = linearprobing(midsquarehash(arr[j]), list);
            else if (ch2 == 2)
                key = quadraticprobing(midsquarehash(arr[j]), list);
            else if (ch2 == 3)
                key = doublehash(arr[j], list);
            list[key] = si_insertend(list[key], arr[j]);
            break;
        case 4:
            if (ch2 == 1)
                key = linearprobing(foldinghash(arr[j]), list);
            else if (ch2 == 2)
                key = quadraticprobing(foldinghash(arr[j]), list);
            else if (ch2 == 3)
                key = doublehash(arr[j], list);
            list[key] = si_insertend(list[key], arr[j]);
            break;
        }
    }
}
void si_display(node *head)
{
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}
int main()
{
    node **list;
    list = (node **)malloc(size * sizeof(node *));
    int i = 1;
    for (i = 0; i < size; i++)
    {
        list[i] = NULL;
    }
    int ch, ch2, key;
    printf("Enter hashing type\n1 Division\n2 Multiplication\n3 Midsquare\n4 Folding:");
    scanf("%d", &ch);
    printf("Enter collision mechanism technique:\n1 Linear probing\n2 Quadratic probing\n3 Double hashing\n");
    scanf("%d", &ch2);
    while (i)
    {
        printf("Enter element(-1 to exit,0 to rehash):");
        scanf("%d", &i);
        if (i < 0)
            break;
        if (i == 0)
        {
            size += 5;
            list = (node **)realloc(list, sizeof(node *) * size);
            for (i = size - 1; i >= size - 5; i--)
                list[i] = NULL;
            rehash(list, ch, ch2);
            continue;
        }
        switch (ch)
        {
        case 1:
            if (ch2 == 1)
                key = linearprobing(divhash(i), list);
            else if (ch2 == 2)
                key = quadraticprobing(divhash(i), list);
            else if (ch2 == 3)
                key = doublehash(i, list);
            list[key] = si_insertend(list[key], i);
            break;
        case 2:
            if (ch2 == 1)
                key = linearprobing(mulhash(i), list);
            else if (ch2 == 2)
                key = quadraticprobing(mulhash(i), list);
            else if (ch2 == 3)
                key = doublehash(i, list);
            list[key] = si_insertend(list[key], i);
            break;
        case 3:
            if (ch2 == 1)
                key = linearprobing(midsquarehash(i), list);
            else if (ch2 == 2)
                key = quadraticprobing(midsquarehash(i), list);
            else if (ch2 == 3)
                key = doublehash(i, list);
            list[key] = si_insertend(list[key], i);
            break;
        case 4:
            if (ch2 == 1)
                key = linearprobing(foldinghash(i), list);
            else if (ch2 == 2)
                key = quadraticprobing(foldinghash(i), list);
            else if (ch2 == 3)
                key = doublehash(i, list);
            list[key] = si_insertend(list[key], i);
            break;
        }
    }
    printf("The hashtable is:\n");
    for (i = 0; i < size; i++)
    {
        printf("%d:", i);
        si_display(list[i]);
        printf("\n");
    }
}
