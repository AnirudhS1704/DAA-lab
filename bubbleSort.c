#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void getArray(int n, int *arr)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void main()
{
    int n;
    printf("Enter the value of n\n");
    scanf("%d", &n);
    int *a = (int *)malloc(sizeof(int) * n);
    getArray(n, a);
    clock_t start, end;
    start = clock();
    bubbleSort(a, n);
    end = clock();
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    double time = (double)(end - start) / 1000;
    printf("\n%lf\n", time);
}