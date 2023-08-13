#include <stdio.h>

int isSafe(int row, int col, int board[10][10], int n)
{
    int dupRow = row;
    int dupCol = col;

    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 1)
            return 0;
        row--;
        col--;
    }

    col = dupCol;
    row = dupRow;
    while (col >= 0)
    {
        if (board[row][col] == 1)
            return 0;
        col--;
    }

    col = dupCol;
    row = dupRow;
    while (row < n && col >= 0)
    {
        if (board[row][col] == 1)
            return 0;
        row++;
        col--;
    }

    return 1;
}

void solve(int col, int board[10][10], int n)
{
    if (col == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 1)
                    printf("Q\t");
                else
                    printf("_\t");
            }
            printf("\n");
        }
        printf("\n\n");
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n) == 1)
        {
            board[row][col] = 1;
            solve(col + 1, board, n);
            board[row][col] = 0;
        }
    }
}

void main()
{
    int n;
    printf("Enter the value of n\n");
    scanf("%d", &n);
    int board[10][10];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }
    solve(0, board, n);
}