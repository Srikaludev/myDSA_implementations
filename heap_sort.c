#include <stdio.h>

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapify(int arr[],int size, int i){
    if (size == 1){
        printf("Single element in the heap\n");
    }
    else {
        int largest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;
        if (l < size && arr[l]>arr[largest])
            largest = l;
        if (r < size && arr[r]>arr[largest])
            largest = r;
        if (largest != i){
            swap(&arr[i], &arr[largest]);
            heapify(arr,size,largest);
        }
    }
}

void insert(int arr[], int key,int size){
    if (size == 0){
        arr[0] = key;
        size+=1;
    }
    else {
        arr[size] = key;
        size++;
        for (int i = size/2 - 1;i >= 0; i--){
            heapify (arr,size,i);
        }
    }
}

void delete(int arr[], int size, int key){
    int i;
    for (i=0;i<size;i++)
        if (key == arr[i]) break;
    swap(&arr[i],&arr[i-1]);
    size-=1;
    for(int i = size/2 -1;i >=0; i--){
        heapify(arr,size,i);
    }
}

void heapsort(int arr[],int size){
    for (int i=size/2 - 1;i>=0;i--){
        heapify(arr,size,i);
    }

    for (int i = size-1; i>=0 ; i--){
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}

int main()
{
    int arr[] = {10, 28, 24, 6, 34, 18, 38, 44};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapsort(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}