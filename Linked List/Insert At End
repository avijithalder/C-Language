#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;

} node;

node *head;

void InsertAtEnd(int data)
{
    node *Newnode;
    Newnode=(node*)malloc(sizeof(node));
    Newnode->data=data;
    Newnode->next=NULL;

    node*current=head;
    while (current->next!=NULL)
    {
        current=current->next;
    }
    current->next=Newnode;
}

void printData()
{
    printf("New List is  ");
    node *current = head;

    while (current!= NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    head = (node *)malloc(sizeof(node));
    head->data = 10;
    head->next = (node *)malloc(sizeof(node));
    head->next->data = 20;
    head->next->next = (node *)malloc(sizeof(node));
    head->next->next->data = 30;
    head->next->next->next = NULL;
    InsertAtEnd(70);
    printData();
}
