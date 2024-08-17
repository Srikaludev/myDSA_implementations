#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = *head;
    }
    printf("Element %d inserted at the end.\n", data);
}

void deleteElement(Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete element.\n");
        return;
    }
    Node* current = *head;
    Node* prev;

    // If head node contains the key to be deleted
    if (current->data == key) {
        Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        last->next = (*head)->next;
        *head = (*head)->next;
        free(current);
        printf("Element %d deleted.\n", key);
        return;
    }

    // Search for the key to be deleted, keeping track of the previous node
    do {
        prev = current;
        current = current->next;
    } while (current != *head && current->data != key);

    if (current == *head) {
        printf("Element %d not found in the list.\n", key);
        return;
    }

    prev->next = current->next;
    free(current);
    printf("Element %d deleted.\n", key);
}

void printList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* current = head;
    printf("Circular Linked List: ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

void freeList(Node* head) {
    if (head == NULL) {
        return;
    }
    Node* current = head;
    Node* nextNode;
    do {
        nextNode = current->next;
        free(current);
        current = nextNode;
    } while (current != head);
}

int main() {
    Node* head = NULL;
    int choice, element;

    do {
        printf("\nCircular Linked List Operations:\n");
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Print list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insertAtEnd(&head, element);
                break;
            case 2:
                printf("Enter the element to delete: ");
                scanf("%d", &element);
                deleteElement(&head, element);
                break;
            case 3:
                printList(head);
                break;
            case 4:
                freeList(head);
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
