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

void heapify(int arr[], int n, int i)
{
    int largestIndex = i;
    int leftIndex = 2 * i + 1;
    int rightIndex = 2 * i + 2;

    if (leftIndex < n && arr[leftIndex] > arr[largestIndex])
        largestIndex = leftIndex;
    if (rightIndex < n && arr[rightIndex] > arr[largestIndex])
        largestIndex = rightIndex;

    if (largestIndex != i)
    {
        swap(&arr[largestIndex], &arr[i]);
        heapify(arr, n, largestIndex);
    }
}

void maxHeap(int arr[], int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    printf("Max heap\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void heapSort(int arr[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void main()
{
    int n;
    printf("Enter the value of n\n");
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);
    getArray(n, arr);
    clock_t start, end;
    start = clock();
    maxHeap(arr, n);
    heapSort(arr, n);
    end = clock();
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    double time = (double)(end - start) / 1000;
    printf("\n%lf\n", time);
}