#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void getArray(int n, int *arr){
    for(int i=0; i<n; i++){
        arr[i] = rand() % 100;
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void selectionSort(int *a, int n){
    for(int i=0; i<n-1; i++){
        int min = i; 
        for(int j=i+1; j<n; j++){
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

void main() {
    int n;
    printf("Enter the value of n\n");
    scanf("%d", &n);
    int *a = (int*)malloc(sizeof(int)*n);
    getArray(n, a);
    clock_t start, end;
    start  = clock();
    selectionSort(a, n);
    end = clock();
    for(int i=0; i<n; i++){
        printf("%d\t", a[i]);
    }
    double time = (double)(end - start) / 1000;
    printf("\n%lf\n", time);
}