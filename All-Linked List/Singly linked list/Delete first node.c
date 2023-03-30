/**
 * C program to delete first node from Singly Linked List
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
void deleteFirstNode();
void displayList();

int main()
{
    int n, choice;

    /*
     * Create a singly linked list of n nodes
     */
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);

    printf("\nData in the list \n");
    displayList();

    printf("\nPress 1 to delete first node: ");
    scanf("%d", &choice);

    /* Delete first node from list */
    if (choice == 1)
        deleteFirstNode();

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
     * In data of node from the user
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
 * Deletes the first node of the linked list
 */
void deleteFirstNode()
{
    node *toDelete;

    toDelete = head;
    head = head->next;

    printf("\nData deleted = %d\n", toDelete->data);

    /* Clears the memory occupied by first node*/
    free(toDelete);

    printf("SUCCESSFULLY DELETED FIRST NODE FROM LIST\n");
}

/*
 * Displays the entire list
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
