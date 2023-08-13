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

int swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high)
{
    int i = low, j = high, pivot = arr[low];
    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }
        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }

        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[j];
    arr[j] = arr[low];
    arr[low] = temp;

    return j;
}

void quickSort(int *a, int low, int high)
{
    if (low < high)
    {
        int j = partition(a, low, high);
        quickSort(a, low, j - 1);
        quickSort(a, j + 1, high);
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
    quickSort(a, 0, n - 1);
    end = clock();
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    double time = (double)(end - start) / 1000;
    printf("\n%lf\n", time);
}