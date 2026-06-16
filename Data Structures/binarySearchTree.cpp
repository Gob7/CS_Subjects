// binary search tree
#include <bits/stdc++.h>
using namespace std;
#include "../Common/printTreeList.h"

void insert(int x)
{
    treeNode *ptr = root, *cur = new treeNode;
    cur->value = x;
    cur->left = cur->right = nullptr;

    if (!ptr)
    {
        root = cur;
        return;
    }

    // duplicate value not allowed.
    while (ptr->value != cur->value)
    {
        if (ptr->value > cur->value)
        {
            if (!ptr->left)
                ptr->left = cur;
            ptr = ptr->left;
        }
        else if (ptr->value < cur->value)
        {
            if (!ptr->right)
                ptr->right = cur;
            ptr = ptr->right;
        }
    }
    // printf("%d added.\n", ptr->value);
}

void zeroDelete(treeNode *ptr, treeNode *cur)
{
    if (root == cur)
        root = nullptr;
    else if (ptr->left == cur)
        ptr->left = nullptr;
    else
        ptr->right = nullptr;
    delete cur;
}

// can be optimized; but better to keep it simple for understanding.
void oneDelete(treeNode *ptr, treeNode *cur)
{
    if (root == cur && cur->left)
        root = cur->left;

    else if (root == cur && cur->right)
        root = cur->right;

    else if (ptr->left == cur && cur->left)
        ptr->left = cur->left;

    else if (ptr->left == cur && cur->right)
        ptr->left = cur->right;

    else if (ptr->right == cur && cur->left)
        ptr->right = cur->left;

    else if (ptr->right == cur && cur->right)
        ptr->right = cur->right;

    delete cur;
}

void twoDelete(treeNode *cur)
{
    // find the largest value in the left subtree;
    // swap it with the current treeNode; then delete the largest treeNode.
    treeNode *ptr = cur, *next;
    next = cur->left;
    while (next->right)
    {
        ptr = next;
        next = next->right;
    }

    int temp = next->value;
    next->value = cur->value;
    cur->value = temp;

    if (next->left)
        oneDelete(ptr, next);
    else
        zeroDelete(ptr, next);
}

void deleteNode(treeNode *ptr, treeNode *cur, int x)
{
    if (!cur)
        return;
    if (cur->value > x)
        deleteNode(cur, cur->left, x);
    else if (cur->value < x)
        deleteNode(cur, cur->right, x);

    else
    {
        if (cur->left && cur->right)
            twoDelete(cur);
        else if (!cur->left && !cur->right)
            zeroDelete(ptr, cur);
        else
            oneDelete(ptr, cur);
    }
}

bool search(int x, treeNode *ptr)
{
    if (!ptr)
        return false;
    if (ptr->value == x)
        return true;

    if (ptr->value > x)
        search(x, ptr->left);
    else
        search(x, ptr->right);
}

int main()
{
    deleteNode(nullptr, root, 0);
    printf("\n\tDeleted 0");
    treePrint();

    insert(100);
    insert(50);
    insert(150);
    insert(30);
    insert(70);
    insert(20);
    insert(90);
    insert(200);
    insert(120);
    insert(10);
    insert(40);
    insert(35);

    // duplicate entry
    insert(100);
    insert(40);
    insert(35);
    treePrint();

    // zero = 90; one = 20
    deleteNode(nullptr, root, 90);
    deleteNode(nullptr, root, 20);
    printf("\n\t\t\t\t\tDeleted 20, 90");
    treePrint();

    // two = 50, 150
    deleteNode(nullptr, root, 50);
    deleteNode(nullptr, root, 150);
    printf("\n\t\t\t\tDeleted 50, 150");
    treePrint();

    // root = 100
    deleteNode(nullptr, root, 100);
    printf("\n\t\t\tDeleted 100 (root)");
    treePrint();

    return 0;
}