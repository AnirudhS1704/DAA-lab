#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}
void knapsack(int w[], int p[], int n, int m)
{
    int dp[10][10];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (j < w[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], p[i] + dp[i - 1][j - w[i]]);
        }
    }
    printf("Maximum profit = %d\n", dp[n][m]);
    int profit = dp[n][m];
    for (int i = n; i > 0 && profit > 0; i--)
    {
        if (dp[i][m] != dp[i - 1][m])
        {
            printf("Item taken with weight = %d, profit = %d\n", w[i], p[i]);
            m -= w[i];
            profit -= p[i];
        }
    }
}

void main()
{
    int w[] = {0, 2, 1, 3, 2};
    int p[] = {0, 12, 10, 20, 15};
    knapsack(w, p, 4, 5);
}