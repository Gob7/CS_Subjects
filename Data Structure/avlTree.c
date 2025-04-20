// AVL tree
// duplicate value not allowed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "treePrint.h"

int max(int a, int b){
    return (a>b) ? a : b;
}
int height(struct node *ptr){
    if (!ptr) 
        return 0;
    return ptr->height;
}
void updateHeight(struct node *ptr){
    ptr->height = 1 + max(height(ptr->left), height(ptr->right));
}
int balanceFactor(struct node *ptr){
    if (!ptr) 
        return 0;
    return height(ptr->left) - height(ptr->right);
}

struct node* create(int x){
    struct node *cur = (struct node *) malloc(sizeof(struct node));;
    cur->height = 1; 
    cur->value = x;
    cur->left = cur->right = NULL;
    return cur;
}
struct node* rightRotate(struct node *cur){
    struct node *ptr, *temp;
    ptr = cur->left;
    temp = ptr->right;
    ptr->right = cur;
    cur->left = temp;

    updateHeight(cur);
    updateHeight(ptr);
    return ptr;
}
struct node* leftRotate(struct node *cur){
    struct node *ptr, *temp;
    ptr = cur->right;
    temp = ptr->left;
    ptr->left = cur;
    cur->right = temp;

    updateHeight(cur);
    updateHeight(ptr);
    return ptr;
}

struct node* insert(struct node *ptr, int x){
    if (!ptr)
        return create(x);
    else if (ptr->value > x) 
        ptr->left = insert(ptr->left, x);
    else if (ptr->value < x) 
        ptr->right = insert(ptr->right, x);
    else 
        return ptr;

    updateHeight(ptr);
    int balance = balanceFactor(ptr);

    if (balance > 1 && ptr->left->value > x)
        return rightRotate(ptr);

    if (balance > 1 && ptr->left->value < x){
        ptr->left = leftRotate(ptr->left);
        return rightRotate(ptr);
    }
    if (balance < -1 && ptr->right->value<x)
        return leftRotate(ptr);

    if (balance < -1 && ptr->right->value>x){
        ptr->right = rightRotate(ptr->right);
        return leftRotate(ptr);
    }
    return ptr;
}

void main(){
    // print();
    root = insert(root, 50);
    root = insert(root, 20);
    root = insert(root, 60);
    root = insert(root, 10);
    // print();
    root = insert(root, 8);
    root = insert(root, 15);
    print();
    root = insert(root, 32);
    root = insert(root, 46);
    root = insert(root, 11);
    root = insert(root, 38);
    print();
}