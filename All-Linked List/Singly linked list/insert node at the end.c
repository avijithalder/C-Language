/**
 * C program to insert new node at the end of a Singly Linked List
 */

#include <stdio.h>
#include <stdlib.h>

/* Structure of a node */
typedef struct node
{
    int data;          // Data
    struct node *next; // Address
} node;

node *head;

void createList(int n);
void insertNodeAtEnd(int data);
void displayList();

int main()
{
    int n, data;

    /*
     * Create a singly linked list of n nodes
     */
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);

    printf("\nData in the list \n");
    displayList();

    /*
     * Insert data at the end of the singly linked list
     */
    printf("\nEnter data to insert at end of the list: ");
    scanf("%d", &data);
    insertNodeAtEnd(data);

    printf("\nData in the list \n");
    displayList();

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

    /*
     * Reads data of node from the user
     */
    printf("Enter the data of node 1: ");
    scanf("%d", &data);

    head->data = data; // Link the data field with data
    head->next = NULL; // Link the address field to NULL

    temp = head;

    /*
     * Create n nodes and adds to linked list
     */
    for (i = 2; i <= n; i++)
    {
        newNode = (node *)malloc(sizeof(node));

        printf("Enter the data of node %d: ", i);
        scanf("%d", &data);

        newNode->data = data; // Link the data field of newNode with data
        newNode->next = NULL; // Link the address field of newNode with NULL

        temp->next = newNode; // Link previous node i.e. temp to the newNode
        temp = temp->next;
    }

    printf("SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
}

/*
 * Create a new node and inserts at the end of the linked list.
 */
void insertNodeAtEnd(int data)
{
    node *newNode, *temp;

    newNode = (node *)malloc(sizeof(node));

    newNode->data = data; // Link the data part
    newNode->next = NULL;

    temp = head;

    // Traverse to the last node
    while (temp != NULL && temp->next != NULL)
        temp = temp->next;

    temp->next = newNode; // Link address part

    printf("DATA INSERTED SUCCESSFULLY\n");
}

/*
 * Display entire list
 */
void displayList()
{
    node *temp;

    temp = head;
    while (temp != NULL)
    {
        printf("Data = %d\n", temp->data); // Print data of current node
        temp = temp->next;                 // Move to next node
    }
}
