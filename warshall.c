#include <stdio.h>
#include <stdlib.h>

void warshall(int graph[10][10], int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
            }
        }
    }
}

void main()
{
    int graph[10][10], n;
    printf("Enter the number of vertices\n");
    scanf("%d", &n);
    printf("Enter the adjacency matrix\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    warshall(graph, n);
    printf("Transitive closure is\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }
}