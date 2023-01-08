#include <stdio.h>
#include <limits.h>

void dijkstra(int Graph[10][10], int n, int s)
{
    int cost[10][10], dis[10], pred[10];
    int visited[10], cnt, mindis, nextnode, i, j;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (Graph[i][j] == 0)
                cost[i][j] = INT_MAX;
            else
                cost[i][j] = Graph[i][j];

    for (i = 0; i < n; i++)
    {
        dis[i] = cost[s][i];
        pred[i] = s;
        visited[i] = 0;
    }

    dis[s] = 0;
    visited[s] = 1;
    cnt = 1;

    while (cnt < n - 1)
    {
        mindis = INT_MAX;
        for (i = 0; i < n; i++)
            if (dis[i] < mindis && !visited[i])
            {
                mindis = dis[i];
                nextnode = i;
            }

        visited[nextnode] = 1;

        for (i = 0; i < n; i++)
            if (!visited[i])
                if (mindis + cost[nextnode][i] < dis[i])
                {
                    dis[i] = mindis + cost[nextnode][i];
                    pred[i] = nextnode;
                }
        cnt++;
    }
    for (i = 0; i < n; i++)
        if (i != s)
        {
            printf("\nDistant of node %d = %d", i, dis[i]);
            printf("\nPath = %d", i);
            j = i;
            do
            {
                j = pred[j];
                printf("<-%d", j);
            } while (j != s);
        }
}

void main()
{
    int Graph[10][10], i, j, n, s;
    printf("Enter number of vertices : ");
    scanf("%d", &n);

    printf("\nEnter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &Graph[i][j]);

    printf("\nEnter start node:");
    scanf("%d", &s);
    dijkstra(Graph, n, s);
}
