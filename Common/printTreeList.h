#include <bits/stdc++.h>
using namespace std;

struct listNode
{
    int value;
    struct listNode *next;
} *head = nullptr;

struct treeNode
{
    char height;
    int value;
    struct treeNode *left, *right;
} *root = nullptr;

void listPrint(listNode *ptr)
{
    while (ptr)
    {
        cout << ptr->value << "\t-> ";
        ptr = ptr->next;
    }
    cout << "NULL\n";
}

void preOrder(treeNode *ptr)
{
    if (!ptr)
        return;
    cout << ptr->value << " -> ";
    preOrder(ptr->left);
    preOrder(ptr->right);
}

void inOrder(treeNode *ptr)
{
    if (!ptr)
        return;
    inOrder(ptr->left);
    cout << ptr->value << " -> ";
    inOrder(ptr->right);
}

void postOrder(treeNode *ptr)
{
    if (!ptr)
        return;
    postOrder(ptr->left);
    postOrder(ptr->right);
    cout << ptr->value << " -> ";
}

void treePrint()
{
    cout << "\nPreOrder:\t";
    preOrder(root);
    cout << "NULL\n";

    cout << "InOrder:\t";
    inOrder(root);
    cout << "NULL\n";

    cout << "PostOrder:\t";
    postOrder(root);
    cout << "NULL\n";
}