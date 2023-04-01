#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *head;

void deleteData()
{
    int n;
    node *current = head;
    node *previous;
    printf("Which data you want to delete: ");
    scanf("%d", &n);
    if (head->data == n)
    {
        head = head->next;
        free(current);
    }
    else
    {
        while (current != NULL && current->data != n)
        {
            previous = current;
            current = current->next;
        }
        if (current->data == n)
        {
            previous->next = current->next;
            free(current);
        }
    }
}

void printData()
{
    node *current = head;
    printf("New list is:");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    head = (node *)malloc(sizeof(node));
    head->data = 3;
    head->next = (node *)malloc(sizeof(node));
    head->next->data = 10;
    head->next->next = (node *)malloc(sizeof(node));
    head->next->next->data = 2;
    head->next->next->next = (node *)malloc(sizeof(node));
    head->next->next->next->data = 1;
    head->next->next->next->next = NULL;
    printData();
    deleteData();
    printf("\n");
    printf("Final ");
    printData();
}
