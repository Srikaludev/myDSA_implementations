#include <stdio.h>
#include <stdlib.h>
struct MaxHeap {
    int* heapArr;
    int capacity;
    int size;
};
struct MaxHeap* createHeap(int capacity) {
    struct MaxHeap* heap = (struct MaxHeap*)malloc(sizeof(struct MaxHeap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->heapArr = (int*)malloc(capacity * sizeof(int));
    return heap;
}
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(struct MaxHeap* heap, int index) {
    int largest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < heap->size && heap->heapArr[leftChild] > heap->heapArr[largest])
        largest = leftChild;

    if (rightChild < heap->size && heap->heapArr[rightChild] > heap->heapArr[largest])
        largest = rightChild;

    if (largest != index) {
        swap(&heap->heapArr[index], &heap->heapArr[largest]);
        heapify(heap, largest);
    }
}
void insert(struct MaxHeap* heap, int value) {
    if (heap->size == heap->capacity) {
        printf("Heap is full. Cannot insert more elements.\n");
        return;
    }
    int index = heap->size;
    heap->heapArr[index] = value;
    heap->size++;
    while (index != 0 && heap->heapArr[(index - 1) / 2] < heap->heapArr[index]) {
        swap(&heap->heapArr[(index - 1) / 2], &heap->heapArr[index]);
        index = (index - 1) / 2;
    }
}
void delete(struct MaxHeap* heap, int index) {
    if (index >= heap->size) {
        printf("Invalid index. Cannot delete element.\n");
        return;
    }
    heap->heapArr[index] = heap->heapArr[heap->size - 1];
    heap->size--;
    heapify(heap, index);
}
void printHeap(struct MaxHeap* heap) {
    printf("Heap elements: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->heapArr[i]);
    }
    printf("\n");
}
int main() {
    struct MaxHeap* heap = createHeap(10);
    insert(heap, 5);
    insert(heap, 10);
    insert(heap, 2);
    insert(heap, 7);
    insert(heap, 1);
    printHeap(heap);
    delete(heap, 2);
    printHeap(heap);
    free(heap->heapArr);
    free(heap);
    return 0;
}
