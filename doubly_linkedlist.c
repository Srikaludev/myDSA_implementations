#include<stdio.h>
#include<stdlib.h>

typedef struct nod{
    struct nod *prev;
    int data;
    struct nod *next;
}node;

node *head = NULL;

void createlist(int c){
    node *ptr = (node*)malloc(sizeof(node));
    ptr -> prev = NULL;
    ptr -> data = c;
    ptr -> next = NULL;
    head = ptr;
}
void addatbeg(int c){
    node *ptr = (node *)malloc(sizeof(node));
    ptr -> prev = NULL;
    ptr -> data = c;
    ptr -> next = head;
    head -> prev = ptr;
    head = ptr; 
}
void addatend(int c){
    node *ptr =(node *)malloc (sizeof(node));
    ptr ->data = c;
    ptr -> next = NULL;
    node *p = head;
    while (p->next != NULL){
        p=p->next;
    }
    p->next = ptr;
    ptr->prev = p;
}
void PrintLL(){
    node *ptr =head;
    while (ptr!=NULL){
        printf("%d " ,ptr ->data);
        ptr = ptr->next;
    }
    printf("\n");
}
void addinmid(int c,int pos){
    node *ptr =(node *)malloc (sizeof(node));
    ptr ->data = c;
    node *ptr1 = head;
    node *ptr2 = NULL;
    while (pos != 1){
        ptr1 = ptr1->next;
        pos--;
    }
    if (ptr1->next == NULL){
        ptr1 -> next = ptr;
        ptr -> prev = ptr1;
    }
    else {
    ptr2 = ptr1->next;
    ptr1 -> next = ptr;
    ptr2 -> prev = ptr;
    ptr ->prev = ptr1;
    ptr -> next = ptr2;
    }
}
void del_first(){
    head = head -> next;
    free (head->prev);
}
void del_last (){
    node *temp = head;
    while (temp->next!=NULL){
        temp = temp -> next; 
    }
    node *temp2 = temp->prev;
    temp2->next = NULL;
    free (temp);
}
void del_middle(int pos){
    node *temp=head;
    node *temp2=NULL;
    if (pos == 1){
        del_first();
    }
    else {
        while (pos > 1){
            temp = temp->next;
            pos--;
        }
        if (temp->next == NULL){
            del_last();
        }
        else {
            temp2 = temp->prev;
            temp2 -> next =temp->next;
            temp->next->prev=temp2;
            free (temp);
            temp = NULL;
        }
    }
}

int main(){
    createlist(45);
    addatbeg(25);
    addatend(15);
    addinmid(20,2);
    del_first();
    del_last();
    del_middle(2);
    PrintLL();
    return 0;
}