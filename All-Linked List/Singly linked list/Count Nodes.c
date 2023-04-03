#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head;

int NodeCount()
{
    int count = 0;

    node *current;
    current = head;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

void printdata()
{
    node *current;
    current = head;

    while (current != NULL)
    {
        printf("Data = %d\n", current->data);
        current = current->next;
    }
}

void createlist(int n)
{
    int data;
    head = (node *)malloc(sizeof(node));
    printf("Input data for node 1: ");
    scanf("%d", &data);

    head->data = data;
    head->next = NULL;
    node *temp;
    temp = head;
    node *newnode;

    for (int i = 2; i <= n; i++)
    {
        newnode = (node *)malloc(sizeof(node));

        printf("Input data for node %d: ",i);
        scanf("%d", &data);

        newnode->data = data;
        newnode->next = NULL;

        temp->next = newnode;
        temp = temp->next;
    }
}

int main()
{
    int n, totalnode;

    printf("Input the number of nodes : ");
    scanf("%d", &n);

    createlist(n);
    printf("\nData entered in the list :\n");
    printdata();

    totalnode = NodeCount();
    printf("\nTotal number of nodes = %d \n", totalnode);
}
