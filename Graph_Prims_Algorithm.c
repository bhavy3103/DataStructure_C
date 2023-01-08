#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void connect(int **arr, int n, int c1, int c2, int cost)
{
    arr[c1][c2] = cost;
    arr[c2][c1] = cost;
}

void prims(int **arr, int n, int **primspan)
{
    int i, j, k, l, cnt = 1;
    int min = INT_MAX, minx, miny;
    int visted[n + 1];
    for (i = 0; i <= n; i++)
        visted[i] = -1;
    for (i = 1; i <= n; i++)
    {
        for (j = i; j <= n; j++)
        {
            if (arr[i][j] < min)
            {
                miny = i;
                minx = j;
                min = arr[i][j];
            }
        }
    }
    primspan[0][0] = minx;
    primspan[1][0] = miny;
    visted[minx] = 0;
    visted[miny] = 0;

    while (cnt < n - 1)
    {
        min = INT_MAX;
        for (i = 1; i <= n; i++)
        {
            if (visted[i] == 0)
                continue;
            if (arr[i][minx] > arr[i][miny])
                visted[i] = miny;
            else
                visted[i] = minx;
            if (min > arr[i][visted[i]])
            {
                min = arr[i][visted[i]];
                l = i;
            }
        }
        primspan[0][cnt] = l;
        primspan[1][cnt] = visted[l];
        cnt++;
        if (visted[l] == minx)
            minx = l;
        else
            miny = l;

        visted[l] = 0;
    }
}
int main()
{
    int n, **arr, i, j, e, c1, c2, *vis, cost, **prispan;
    printf("Enter number of vertices : ");
    scanf("%d", &n);

    arr = (int **)malloc((n + 1) * sizeof(int *));
    for (i = 0; i <= n; i++)
        arr[i] = (int *)malloc((n + 1) * sizeof(int));

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= n; j++)
            arr[i][j] = INT_MAX;
    }

    prispan = (int **)malloc(2 * sizeof(int *));
    prispan[0] = (int *)malloc(n * sizeof(int));
    prispan[1] = (int *)malloc(n * sizeof(int));

    printf("Enter number of edges : ");
    scanf("%d", &e);
    printf("Enter the tow vertices and their cost :\n");
    for (i = 0; i < e; i++)
    {
        scanf("%d %d %d", &c1, &c2, &cost);
        connect(arr, n, c1, c2, cost);
    }

    prims(arr, n, prispan);
    printf("\n");
    printf("Edges :\n");
    for (i = 0; i < n - 1; i++)
        printf("%d %d\n", prispan[0][i], prispan[1][i]);
}
