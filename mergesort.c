#include <stdio.h>

void merge(int arr[], int l, int mid, int r)
{
    int x = mid - l + 1;
    int y = r - mid;
    int a[x], b[y];
    for (int i = 0; i < x; i++)
    {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < y; i++)
    {
        b[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = l;
    while (i < x && j < y)
    {
        if (a[i] < b[j])
            arr[k++] = a[i++];
        else
            arr[k++] = b[j++];
    }
    while (i < x)
    {
        arr[k++] = a[i++];
    }
    while (j < y)
    {
        arr[k++] = b[j++];
    }
}

void mergesort(int arr[], int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    mergesort(arr, l, mid);
    mergesort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}
int main()
{
    int arr[] = {10, 28, 24, 6, 34, 18, 38, 44};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergesort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}