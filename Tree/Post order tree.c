#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(char data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void print_In_Order(struct Node *node)
{
    if (node == NULL)
        return;
    print_In_Order(node->left);
    print_In_Order(node->right);
     printf("%c ", node->data);
}

int main()
{
    struct Node *root = newNode('a');
    root->left = newNode('b');
    root->right = newNode('c');
    root->left->left = newNode('d');
    root->left->right = newNode('e');
    root->right->left = newNode('f');
    printf("Traversal of a binary tree: \n");
    print_In_Order(root);
    return 0;
}
