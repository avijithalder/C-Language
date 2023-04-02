// Binary Search Tree operations in C
/*
Case I
1.In the first case, the node to be deleted is the leaf node. In such a case, simply delete the node from the tree.

Case II
In the second case, the node to be deleted lies has a single child node. In such a case follow the steps below:
1.Replace that node with its child node.
2.Remove the child node from its original position.

Case III
In the third case, the node to be deleted has two children. In such a case follow the steps below:
1.Get the inorder successor of that node.
2.Replace the node with the inorder successor.
3.Remove the inorder successor from its original position.

*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// Create a node
struct node *newNode(int data)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Inorder Traversal
void travarsal(struct node *root)
{
    if (root != NULL)
    {
        // Traverse left
        travarsal(root->left);

        // Traverse root
        printf("%d -> ", root->data);

        // Traverse right
        travarsal(root->right);
    }
}

// Insert a node
struct node *insert(struct node *node, int data)
{
    // Return a new node if the tree is empty
    if (node == NULL)
        return newNode(data);

    // Traverse to the right place and insert the node
    if (data < node->data)
        node->left = insert(node->left, data);
    else
        node->right = insert(node->right, data);

    return node;
}

// Find the inorder successor
struct node *minValueNode(struct node *node)
{
    struct node *current;
    current = node;

    // Find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// Deleting a node
struct node *deleteNode(struct node *root, int data)
{
    // Return if the tree is empty
    if (root == NULL)
        return root;

    // Find the node to be deleted
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);

    else
    {
        // If the node is with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // If the node has two children
        struct node *temp;
        temp = minValueNode(root->right);

        // Place the inorder successor in position of the node to be deleted
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Driver code
int main()
{
    struct node *root;
    root = NULL;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 4);

    printf("Inorder traversal: ");
    travarsal(root);

    printf("\nAfter deleting 10\n");
    root = deleteNode(root, 10);
    printf("Inorder traversal: ");
    travarsal(root);
}
