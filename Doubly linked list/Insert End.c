#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;

} node;

node *head; // global declare

void InsertAtEnd(int data)
{
    node *Newnode;
    Newnode = (node *)malloc(sizeof(node));
    Newnode->data = data;
    Newnode->next = NULL;
    Newnode->prev = NULL;

    node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = Newnode;
}

void printData()
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    head = (node *)malloc(sizeof(node));
    head->prev = NULL;
    head->data = 10;
    head->next = (node *)malloc(sizeof(node));
    head->next->data = 20;
    head->next->prev = head->next;
    head->next->next = (node *)malloc(sizeof(node));
    head->next->next->data = 30;
    head->next->next->prev = head->next->next;
    head->next->next->next = NULL;
    InsertAtEnd(80);
    printData();
}
