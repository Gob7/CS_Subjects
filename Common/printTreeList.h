#include <bits/stdc++.h>
using namespace std;

struct listNode
{
    int value;
    struct listNode *next;
};

struct treeNode
{
    int value, height;
    struct treeNode *left, *right;
} *root = NULL;

void listPrint(listNode *ptr)
{
    while (ptr)
    {
        cout << ptr->value << "\t-> ";
        ptr = ptr->next;
    }
    cout << "NULL\n";
}

void preOrder(struct treeNode *ptr)
{
    if (!ptr)
        return;
    printf("%d -> ", ptr->value);
    preOrder(ptr->left);
    preOrder(ptr->right);
}

void inOrder(struct treeNode *ptr)
{
    if (!ptr)
        return;
    inOrder(ptr->left);
    printf("%d -> ", ptr->value);
    inOrder(ptr->right);
}

void postOrder(struct treeNode *ptr)
{
    if (!ptr)
        return;
    postOrder(ptr->left);
    postOrder(ptr->right);
    printf("%d -> ", ptr->value);
}

void treePrint()
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