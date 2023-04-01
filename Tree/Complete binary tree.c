// Checking if a binary tree is a complete binary tree in C

/*
1.Select the first element of the list to be the root node. (no. of elements on level-I: 1)
2.Put the second element as a left child of the root node and the third element as the right child. (no. of elements on level-II: 2)
3.Put the next two elements as children of the left node of the second level. Again, put the next two elements as children of the right node of the second level (no. of elements on level-III: 4) elements).
4.Keep repeating until you reach the last element.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Node creation
struct Node *newNode(int data)
{
    struct Node *node;
    node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->right = NULL;
    node->left = NULL;
    return node;
}

// Count the number of nodes
int countNumNodes(struct Node *root)
{
    if (root == NULL)
        return (0);
    return (1 + countNumNodes(root->left) + countNumNodes(root->right));
}

// Check if the tree is a complete binary tree
bool checkComplete(struct Node *root, int index, int numberNodes)
{
    // Check if the tree is complete
    if (root == NULL)
        return true;

    if (index >= numberNodes)     // in main function index = 0;
        return false;

    return (checkComplete(root->left, 2 * index + 1, numberNodes) && checkComplete(root->right, 2 * index + 2, numberNodes));
}

int main()
{
    struct Node *root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);

    int node_count = countNumNodes(root);
    int index = 0;

    if (checkComplete(root, index, node_count))
        printf("The tree is a complete binary tree\n");
    else
        printf("The tree is not a complete binary tree\n");
}

/*
Let's test it out,

Left child of 1 (index 0)
= element in (2*0+1) index 
= element in 1 index 
= 12


Right child of 1
= element in (2*0+2) index
= element in 2 index 
= 9

Similarly,
Left child of 12 (index 1)
= element in (2*1+1) index
= element in 3 index
= 5

Right child of 12
= element in (2*1+2) index
= element in 4 index
= 6

Let us also confirm that the rules hold for finding parent of any node

Parent of 9 (position 2) 
= (2-1)/2 
= ½ 
= 0.5
~ 0 index 
= 1

Parent of 12 (position 1) 
= (1-1)/2 
= 0 index 
= 1

*/
