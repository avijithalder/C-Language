#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *top = NULL;

void push(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    if (top == NULL)
    {
        top = newnode;
    }
    else
    {
        node *current = top;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newnode;
    }
}

void pop()
{
    node *current = top;
    node *prev;
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    else
    {
        while (current->next != NULL)
        {
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        free(current);
    }
}

void printData()
{
    node *current = top;
    printf("New node is: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    int i, n, m, j, k, l;
    printf("How many data you insert:");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &k);
        push(k);
        printData();
    }

    return 0;
}
