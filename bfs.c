#include <stdio.h>
int visited[10];
int graph[10][10], n;
int q[10];

void bfs(int src)
{
    int u, v, r = -1, f = 0;
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    visited[src] = 1;
    q[++r] = src;
    while (r >= f)
    {
        u = q[f++];
        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] == 1 && visited[v] == 0)
            {
                q[++r] = v;
                visited[v] = 1;
            }
        }
    }
}

int main()
{
    int start_node = 0;
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
    printf("..................BFS Traversal..............\n");
    bfs(start_node);
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", q[i]);
    }

    return 0;
}
