#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 15
 
int parent(int i) {
    return (i - 1) / 2;
}

int left_child(int i) {
    return 2*i + 1;
}
int right_child(int i) {
    return 2*i + 2;
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void insert(int a[], int data, int *n) {
    if (*n >= MAX_SIZE) {
        printf("%s\n", "The heap is full. Cannot insert");
        return;
    }

    a[*n] = data;
    *n = *n + 1;
    int i = *n - 1;
    while (i != 0 && a[parent(i)] < a[i]) {
        swap(&a[parent(i)], &a[i]);
        i = parent(i);
    }
}

void max_heapify(int a[], int i, int n){
    int left = left_child(i);
    int right = right_child(i);
    int largest = i;
    if (left <= n && a[left] > a[largest]) {
        largest = left;
    }

    if (right <= n && a[right] > a[largest]) {
        largest = right;
    }

    if (largest != i) {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        max_heapify(a, largest, n);
    }

}

void build_max_heap(int a[], int n) {
    int i;
    for (i = n/2; i >= 0; i--) {
        max_heapify(a, i, n);
    } 
}

int get_max(int a[]) {
    return a[0];
}

int extract_max(int a[], int *n) {
    int max_item = a[0];
    a[0] = a[*n - 1];
    *n = *n - 1;
    max_heapify(a, 0, *n);
    return max_item;
}


void print_heap(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
    printf("\n");
}


int main() {
    int n = 10;
    int a[MAX_SIZE];
    a[1] = 10; a[2] = 12; a[3] = 9; a[4] = 78; a[5] = 33; a[6] = 21; a[7] = 35; a[8] = 29; a[9] = 5; a[10] = 66;
    build_max_heap(a, n);
    insert(a, 55, &n);
    insert(a, 56, &n);
    insert(a, 57, &n);
    insert(a, 58, &n);
    insert(a, 100, &n);
    print_heap(a, n);
    return 0;
}