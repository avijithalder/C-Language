#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;

} node;

int main()
{
    node *head; //Local Declear
    head = (node *)malloc(sizeof(node));

    head->data = 10;
    head->next = (node *)malloc(sizeof(node));

    head->next->data = 20;
    head->next->next = (node *)malloc(sizeof(node));

    head->next->next->data = 30;
    head->next->next->next = NULL;

    while (head != NULL)
    {
        printf("%d ", head->data);
        head= head->next;
    }
}
