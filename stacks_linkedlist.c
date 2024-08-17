#include <stdio.h>
#include <stdlib.h>
typedef struct nod{
    int data;
    struct nod* link;
}node;

node *top = NULL;  

void push(int c){
    node *ptr = (node*)malloc (sizeof(node));
    if (ptr == NULL){
        printf("Stack is empty!!");
        exit(1);
    }
    ptr->data = c;
    ptr->link = top;
    top = ptr;
}

int pop(){
    node *ptr = top;
    if (ptr == NULL){
        printf("Stack Underflow!!!\n");
        exit(0);
    }
    int val = ptr -> data;
    top = top->link;
    free (ptr);
    ptr = NULL;
    return val;
}

int peek(){
    if (top == NULL){
        printf("Stack Underflow!!!\n");
        exit(0);
    }
    return top->data;
}
void print(){
    node *ptr = top;
    printf("The stack elements are:\n");
    while (ptr){
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }printf("\n");
}
int main(){
    push (1);
    push (2);
    push (13);
    push (4);
    int data=pop();
    int ksdaf = peek();
    print();
}