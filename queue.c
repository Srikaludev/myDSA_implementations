#include <stdio.h>
#include <stdlib.h>

typedef struct nod{
    int data;
    struct nod *link;
}node;
#define max 10
int queue[max];
int front = -1;
int rear = -1;

int isFull(){
    if (rear == max - 1)
        return 1;
    else return 0;
}
int isEmpty(){
    if (front == -1 || front > rear) return 1;
    else return 0;
}
int enqueue(int data){
    if(isFull()) return 0;
    if (rear == -1){
        front = 0;
    }
    rear = rear + 1;
    
    queue[rear] = data;
    printf("Inserted-> %d\n",data);
    return 1;
}
int dequeue(){
    front++;
    if (isEmpty()){
        return 0;
    }
    int data = queue[front];
    if (front > rear)
        front = rear -1;
    return data;
}

void display(){
    if (rear == -1){
        printf("The queue is empty!!\n");
    }
    else {
        printf("Elements are:%d\n",front);
        for (int i = front; i<=rear;i++){
            printf("%d ",queue[i]);
        }
        printf("\n");
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
}