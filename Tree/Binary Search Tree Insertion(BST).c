// Binary Search Tree operations in C

/*
1.Root left subtree value samll
2.root right subtree value large 
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
struct node *newNode(int item)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;
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
    struct node *current = node;

    // Find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;

    return current;
}


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

    //   printf("\nAfter deleting 10\n");
    //   root = deleteNode(root, 10);
    //   printf("Inorder traversal: ");
    //   inorder(root);
}
