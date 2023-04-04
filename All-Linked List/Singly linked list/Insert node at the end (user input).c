#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head;

void printdata()
{
    node *current;
    current = head;

    while (current != NULL)
    {
        printf(" Data = %d\n", current->data);
        current = current->next;
    }
}

void insertatend(int n)
{
    node *newnode, *current;

    newnode = (node *)malloc(sizeof(node));

    newnode->data = n;
    newnode->next = NULL;

    current = head;

    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newnode;
}

void createlist(int n)
{
    node *temp, *newnode;
    int data;

    head = (node *)malloc(sizeof(node));
    printf("Input data for node 1: ");
    scanf("%d", &data);

    head->data = data;
    head->next = NULL;

    temp = head;

    for (int i = 2; i <= n; i++)
    {
        newnode = (node *)malloc(sizeof(node));

        printf("Input data for node %d: ", i);
        scanf("%d", &data);

        newnode->data = data;
        newnode->next = NULL;

        temp->next = newnode;
        temp = temp->next;
    }
}

int main()
{
    int n;
    printf("Input the number of nodes : ");
    scanf("%d", &n);

    createlist(n);

    printf("\n Input data to insert at the end of the list : ");
    scanf("%d", &n);

    insertatend(n);
    printf("\nData entered in the list :\n");
    printdata();
}
