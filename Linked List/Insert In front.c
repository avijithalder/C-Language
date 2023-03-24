#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;

} node;

node *head;
void InsertInFront(int data)
{
    node *Newnode;
    Newnode=(node*)malloc(sizeof(node));
    Newnode->data=data;
    Newnode->next=NULL;

    Newnode->next=head;
    head=Newnode;
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
    InsertInFront(60);
    printData();
}
