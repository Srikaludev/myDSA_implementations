#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int front;
    int rear;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isEmpty(Queue* queue) {
    return queue->front == -1;
}

int isFull(Queue* queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

void enqueue(Queue* queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue element.\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->arr[queue->rear] = data;
    printf("Element %d enqueued.\n", data);
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue element.\n");
        return -1;
    }
    int data = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    printf("Element %d dequeued.\n", data);
    return data;
}

int front(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. No front element.\n");
        return -1;
    }
    return queue->arr[queue->front];
}

void printQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    int i = queue->front;
    while (i != queue->rear) {
        printf("%d ", queue->arr[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", queue->arr[i]);
}

void freeQueue(Queue* queue) {
    free(queue);
}

int main() {
    Queue* queue = createQueue();
    int choice, element;

    do {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue element\n");
        printf("2. Dequeue element\n");
        printf("3. Get front element\n");
        printf("4. Print queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &element);
                enqueue(queue, element);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                printf("Front element: %d\n", front(queue));
                break;
            case 4:
                printQueue(queue);
                break;
            case 5:
                freeQueue(queue);
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
