/**
 * C program to create and traverse a Linked List
 */

#include <stdio.h>
#include <stdlib.h>

/* Structure of a node */
typedef struct node
{
    int data;          // Data
    struct node *next; // Address
} node;

// Golbally declerar
node *head;

/*
 * Functions to create and display list
 */
void createList(int n);
void traverseList();

int main()
{
    int n;

    printf("Enter the total number of nodes: ");
    scanf("%d", &n);

    createList(n);

    printf("\nData in the list \n");
    traverseList();

    return 0;
}

/*
 * Create a list of n nodes
 */
void createList(int n)
{
    node *newNode, *temp;
    int data, i;

    head = (node *)malloc(sizeof(node));

    // Input data of node from the user
    printf("Enter the data of node 1: ");
    scanf("%d", &data);

    head->data = data; // Link data field with data
    head->next = NULL; // Link address field to NULL

    // Create n - 1 nodes and add to list
    temp = head;
    for (i = 2; i <= n; i++)
    {
        newNode = (node *)malloc(sizeof(node));

        printf("Enter the data of node %d: ", i);
        scanf("%d", &data);

        newNode->data = data; // Link data field of newNode
        newNode->next = NULL; // Make sure new node points to NULL

        temp->next = newNode; // Link previous node with newNode
        temp = temp->next;    // Make current node as previous node
    }
}

/*
 * Display entire list
 */
void traverseList()
{
    node *temp;

    temp = head;
    while (temp != NULL)
    {
        printf("Data = %d ", temp->data); // Print data of current node
        temp = temp->next;                // Move to next node
    }
}
