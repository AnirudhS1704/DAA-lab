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

void merge(int *a, int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    int *temp = (int *)malloc(sizeof(int) * (high - low + 1));
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while (i <= mid)
    {
        temp[k++] = a[i++];
    }
    while (j <= high)
    {
        temp[k++] = a[j++];
    }
    for (int i = low; i <= high; i++)
    {
        a[i] = temp[i - low];
    }
}

void mergeSort(int *a, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
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
    mergeSort(a, 0, n - 1);
    end = clock();
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    double time = (double)(end - start) / 1000;
    printf("\n%lf\n", time);
}