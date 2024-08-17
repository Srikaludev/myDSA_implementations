#include <stdio.h>
#include <stdlib.h>

typedef struct nod
{
    int data;
    struct nod *link;
} node;

node *head = NULL;
node *head1 = NULL;

void createNode(int c)
{
    node *new = (node *)malloc(sizeof(node));
    if (head == NULL)
    {
        head = new;
        head1 = head;
    }
    else
    {
        head->link = new;
        head = new;
    }

    new->data = c;
    new->link = NULL;
}

node *Addatbeg(int c)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = c;
    ptr->link = head1;
    head1 = ptr;
    return head1;
}
void Addatend(int c)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->link = NULL;
    ptr->data = c;
    head->link = ptr;
}
void Addinthemiddle(int c, int pos)
{
    node *ptr = head1;
    node *ptr2 = (node *)malloc(sizeof(node));
    ptr2->data = c;
    ptr2->link = NULL;
    pos--;
    while (pos != 1)
    {
        ptr = ptr->link;
        pos--;
    }
    ptr2->link = ptr->link;
    ptr->link = ptr2;
}

void PrintLL()
{
    node *s = head1;
    printf("Data:\n");
    while (s != NULL)
    {
        printf("%d\n", s->data);
        s = s->link;
    }
}
void del_first()
{
    if (head1 == NULL)
        printf("The list is already empty!!!");
    else
    {
        node *temp = head1;
        head1 = head1->link;
        free(temp);
        temp = NULL;
    }
}
void del_last()
{
    node *temp = head1;
    while (temp->link->link != NULL)
    {
        temp = temp->link;
    }
    free(temp->link);
    temp->link = NULL;
}
void del_atpos(int pos)
{
    node *temp = head1;
    node *temp1 = head1;
    if (pos == 1)
    {
        head1 = temp->link;
        free(temp);
        temp = NULL;
    }
    else
    {
        while (pos != 1)
        {
            temp1 = temp;
            temp = temp->link;
            pos--;
        }
        temp1->link = temp->link;
        free(temp);
        temp = NULL;
    }
}
void del_entirelist()
{
    node *temp = head1;
    while (temp != NULL)
    {
        temp = temp->link;
        free(head1);
        head1 = temp;
    }
}
void reverse_list()
{
    node *prev = NULL;
    node *next = NULL;
    while (head1 != NULL)
    {
        next = head1->link;
        head1->link = prev;
        prev = head1;
        head1 = next;
    }
    head1 = prev;
}
int main()
{
    createNode(1);
    createNode(2);
    createNode(3);
    createNode(4);
    head1 = Addatbeg(0);
    Addatend(5);
    Addinthemiddle(7, 3);
    del_first();
    del_last();
    del_atpos(3);
    reverse_list();
    PrintLL();
}