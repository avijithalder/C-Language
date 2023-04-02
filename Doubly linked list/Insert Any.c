#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;

} node;

node *head; // global declare

void insertAny(int data) // Insert Any Position !!
{
    int count = 1, n;
    printf("Enter the position: ");
    scanf("%d", &n);

    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    
    if (n == 1)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        node *current = head;
        while (count < n - 1)
        {
            current = current->next;
            count++;
        }
        newnode->next = current->next;
        current->next = newnode;
    }
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

    insertAny(80);
    printData();
}
