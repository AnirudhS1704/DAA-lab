#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void bubbleSort(int arr[], int n){
        for(int i=0; i<n-2; i++){
                for(int j=0; j<n-i-1; j++){
                        if(arr[j] > arr[j+1])
                        {
                                int temp = arr[j];
                                arr[j] = arr[j+1];
                                arr[j+1] = temp;
                        }
                }
        }
}

void getArray(int arr[], int n){
        for(int i=0; i<n; i++){
                arr[i] = rand() % 100;
        }

}

void main(){
        int n;
        printf("Enter the number of elements\n");
        scanf("%d", &n);

        int* arr = (int*)malloc(sizeof(int) * n);
        getArray(arr, n);
        clock_t start, end;
        for(int i=0; i<n; i++){
                printf("%d\t", arr[i]);
        }

        start = clock();
        bubbleSort(arr, n);
        end = clock();
        double t = (double)(end - start)/1000;

        printf("\n\n%lf\n\n", t);

        printf("\n");
        for(int i=0; i<n; i++){
                printf("%d\t", arr[i]);
        }

}
