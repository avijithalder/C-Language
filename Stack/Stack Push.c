#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *top = NULL;

void push(int data)
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;

    if (top == NULL)
    {
        top = newnode;
    }
    else
    {
        node *current;
        current = top;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newnode;
    }
}
void printdata()
{
    node *current = top;
    printf("New node is : \n");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;

    }
    
}
int main()
{
    int n, k;
    printf("How many data do you insert ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &k);
        push(k);
    }

    printdata();
}
