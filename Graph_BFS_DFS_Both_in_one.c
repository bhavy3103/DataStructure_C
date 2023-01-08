#include <stdio.h>

int queue[20], front = -1, rear = -1;
int stack[20], top = -1;
int arr[20][20], visit[20];

// For BFS
void insert(int x)
{
    if (rear == 19)
        printf("QUEUE FULL"); // Because BFS work on queue data structure
    else
    {
        if (rear == -1)
        {
            queue[++rear] = x;
            front++;
        }
        else
            queue[++rear] = x;
    }
}

int delete() // For deleting vertex which are already traverse
{
    int k;
    if ((front > rear) || (front == -1))
        return 0;
    else
    {
        k = queue[front++];
        return k;
    }
}

void bfs(int s, int n) // BFS algorithm
{
    int p, i;
    insert(s);    // call insert function to insert vertex into stack
    visit[s] = 1; // if node is visited then its indicated as 1 for our understanding
    p = delete ();
    if (p != 0)
        printf(" %d", p);
    while (p != 0)
    {
        for (i = 1; i <= n; i++)
            if ((arr[p][i] != 0) && (visit[i] == 0))
            {
                insert(i);
                visit[i] = 1;
            }
        p = delete ();
        if (p != 0)
            printf(" %d ", p);
    }
    for (i = 1; i <= n; i++)
        if (visit[i] == 0)
            bfs(i, n);
}

// For DFS
void push(int x) // push vertex into stack
{
    if (top == 19)
        printf("Stack overflow ");
    else
        stack[++top] = x;
}

int pop() // pop vertex from stack
{
    int k;
    if (top == -1)
        return 0;
    else
    {
        k = stack[top--];
        return k;
    }
}

void dfs(int s, int n) // dfs algorithm
{
    int i, k;
    push(s);
    visit[s] = 1;
    k = pop();
    if (k != 0)
        printf(" %d ", k);
    while (k != 0)
    {
        for (i = 1; i <= n; i++)
            if ((arr[k][i] != 0) && (visit[i] == 0))
            {
                push(i);
                visit[i] = 1;
            }
        k = pop();
        if (k != 0)
            printf(" %d ", k);
    }
    for (i = 1; i <= n; i++)
        if (visit[i] == 0)
            dfs(i, n);
}

void main()
{
    int n, i, j, choice, source, temp = 1;

    printf("Enter the number of vertices : ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("Enter '1' if arr[%d][%d] have node, else '0' : ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    printf("The Adjancency Matrix : \n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            printf(" %d", arr[i][j]);
        printf("\n");
    }

    while (temp)
    {
        for (i = 1; i <= n; i++)
            visit[i] = 0;

        printf("\n1. BFS    2. DFS");
        printf("\nEnter your Choice : ");
        scanf("%d", &choice);
        printf("Enter the source vertex : ");
        scanf("%d", &source);

        switch (choice)
        {
        case 1:
            bfs(source, n);
            break;
        case 2:
            dfs(source, n);
            break;
        }
        printf("\nFor Continue Enter '1' else '0' : ");
        scanf("%d", &temp);
    }
}
