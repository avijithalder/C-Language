#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head;

void reverselist()
{
    struct node *a;
    struct node *b;

    if (head != NULL)
    {
        a = head;
        b = head->next;
        head = head->next;

        a->next = NULL; // convert first node as last node

        while (head != NULL)
        {
            head = head->next;
            b->next = a;
            a = b;
            b = head;
        }
        head = a; // convert last node as head
    }
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
    printf("Input data for node 1 : ");
    scanf("%d", &data);

    head->data = data;
    head->next = NULL;
    node *temp;
    temp = head;
    node *newnode;

    for (int i = 2; i <= n; i++)
    {
        newnode = (node *)malloc(sizeof(node));

        printf("Input data for node %d :", i);
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
    printf("Data entered in the list :\n");

    reverselist();
    printf("After Reverse list \n");
    printdata();
}
