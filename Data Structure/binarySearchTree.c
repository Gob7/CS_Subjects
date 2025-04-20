// binary search tree
// duplicate value not allowed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "treePrint.h"

void insert(int x){
    struct node *ptr, *cur;
    cur = (struct node *) malloc(sizeof(struct node));
    ptr = root;
    cur->value = x;
    cur->left = NULL;
    cur->right = NULL;

    if (!ptr){
        root = cur;
        return;
    }
    while (ptr->value != cur->value){

        if (ptr->value > cur->value){
            if (!ptr->left)
                ptr->left = cur;
            ptr = ptr->left;
        }
        
        else{
            if (!ptr->right)
                ptr->right = cur;            
            ptr = ptr->right;  
        }
    }
    // printf("%d added.\n", ptr->value);
}

void zeroDelete(struct node *ptr, struct node *cur){
    if (root == cur)
        root = NULL;
    else if (ptr->left == cur)
        ptr->left = NULL;
    else
        ptr->right = NULL;
    free(cur);
}
void oneDelete(struct node *ptr, struct node *cur){
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

    free(cur);
}
void twoDelete(struct node *cur){
    struct node *next, *ptr;
    ptr = cur;
    next = cur->left;
    while (next->right){
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
void delete(struct node *ptr, struct node *cur, int x){
    if (!cur)
        return;
    if (cur->value == x){
        if (cur->left && cur->right)
            twoDelete(cur);
        else if (!cur->left && !cur->right)
            zeroDelete(ptr, cur);
        else
            oneDelete(ptr, cur);
    }
    else if (cur->value > x)
        delete(cur, cur->left, x);
    else
        delete(cur, cur->right, x);
}

bool search(int x, struct node *ptr){
    if (!ptr)
        return false;
    if (ptr->value == x)
        return true;
    if (ptr->value > x)
        search(x, ptr->left);
    else
        search(x, ptr->right);
}

void main(){
    delete(NULL, root, 0);
    printf("\nDelete 0");
    print();

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
    print();

    //zero = 90; one = 20
    delete(NULL, root, 90);
    delete(NULL, root, 20);
    printf("\nDelete 20, 90");
    print();

    //two = 50, 150
    delete(NULL, root, 50);
    delete(NULL, root, 150);
    printf("\nDelete 50, 150");
    print();

    //root = 100
    delete(NULL, root, 100);
    printf("\nDelete 100");
    print();
}