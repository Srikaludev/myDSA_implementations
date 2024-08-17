#include <stdio.h>
#include <stdlib.h>

#define max 10
int arr[max];
int top = -1;

int isFull(){
    if (top == max - 1) return 1;
    return 0;
}

int isEmpty(){
    if (top == -1) return 1;
    return 0;
}

void push(int c){
    if (!isFull()){
        top = top +1;
        arr[top] = c;
    }
    else printf("Could not insert the element.The stack is full!!!!\n");
}

int pop(){
    if (isEmpty()){
        printf("There is no element to return\n");
        exit(0);
    }
    int x = arr[top];
    top = top - 1;
    return x;
}

int peek(){
    if (top == -1){
        printf("Underflow!!\n"); 
        return 0;
    }
    else 
        return arr[top];
}

