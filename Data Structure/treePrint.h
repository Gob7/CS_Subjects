#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value, height;
    struct node *left, *right;
} *root = NULL;

void preOrder(struct node *ptr)
{
    if (!ptr)
        return;
    printf("%d -> ", ptr->value);
    preOrder(ptr->left);
    preOrder(ptr->right);
}

void inOrder(struct node *ptr)
{
    if (!ptr)
        return;
    inOrder(ptr->left);
    printf("%d -> ", ptr->value);
    inOrder(ptr->right);
}

void postOrder(struct node *ptr)
{
    if (!ptr)
        return;
    postOrder(ptr->left);
    postOrder(ptr->right);
    printf("%d -> ", ptr->value);
}

void print()
{
    printf("\nPreOrder:\t");
    preOrder(root);
    printf("NULL\n");
    printf("InOrder:\t");
    inOrder(root);
    printf("NULL\n");
    printf("PostOrder:\t");
    postOrder(root);
    printf("NULL\n");
}