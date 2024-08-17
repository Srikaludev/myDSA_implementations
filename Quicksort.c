#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l - 1;
    int j = l;
    for (; j < r; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[r]);
    return i + 1;
}

void quickSort(int arr[], int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int pi = partition(arr, l, r);
    quickSort(arr, l, pi - 1);
    quickSort(arr, pi + 1, r);
}
int main()
{
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int n = 10;
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}