#include <stdio.h>

int p[10];

int parent(int x)
{
    while (x != p[x])
    {
        x = p[x];
    }
    return x;
}

void kruskal(int graph[10][10], int n)
{
    int u, v, sum = 0;
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
    }

    for (int ne = 0; ne < n - 1;)
    {
        int min = 999;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (graph[i][j] < min)
                {
                    min = graph[i][j];
                    u = i;
                    v = j;
                }
            }
        }
        if (parent(u) != parent(v))
        {
            printf("Connect %d ----> %d = %d\n", u, v, graph[u][v]);
            sum += graph[u][v];
            p[v] = u;
            ne++;
        }
        graph[u][v] = 999;
        graph[v][u] = 999;
    }
    printf("Cost of Minimum spanning tree = %d\n", sum);
}

void main()
{
    int graph[10][10], n, source;
    printf("Enter number of node=");
    scanf("%d", &n);
    printf("\n Enter weighted graph\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("-----------Minimum Spanning Tree-----------\n");
    kruskal(graph, n);
}