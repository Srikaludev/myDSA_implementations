#include <stdio.h>
#include <stdlib.h>
#define max 6
int queue[max];
int front = -1,rear = -1;

void enqueue(int c){
    if (front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = c;
    }
    else if((rear+1)%max == front){
        printf("Overflow!!!\v");
    }
    else {
        rear = (rear + 1) % max;
        queue[rear] = c;
    }
}

int dequeue(){
    if(front == -1 && rear == -1){
        printf("Underflow!!!\n");
    }
    else if(front == rear){
        printf("dequeued element is %d",queue[front]);
        front = rear = -1;
    }
    else {
        printf("The dequeued element is %d\n",queue[front]);
        front = (front+1)%max;
    }
}

void display(){
    int i = front;
    if (front == -1 && rear == -1){
        printf("queue is empty!!!\n");
    }
    else {
        printf("Elements are:\n");
        while (i != rear){
            printf("%d ",queue[i]);
            i = (i+1)%max;

        }
    }
}

int main(){
     enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
    dequeue();
    display();
    dequeue();
    dequeue();
    enqueue(7);
    enqueue(8);
    display();
}