#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    int data2;
    struct node *next;

} node;

node *head;

void printdata()
{

    while (head != NULL)
    {
        printf("%d %d\n", head->data, head->data2);
        head = head->next;
    }
}

int main()
{
    head = (node *)malloc(sizeof(node));
    head->data = 10;
    head->data2 = 10;
    head->next = (node *)malloc(sizeof(node));
    head->next->data = 20;
    head->next->data2 = 20;
    head->next->next = (node *)malloc(sizeof(node));
    head->next->next->data = 30;
    head->next->next->data2 = 30;
    head->next->next->next = NULL;

    printdata();
}
