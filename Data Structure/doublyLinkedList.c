#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
} *head = NULL;

int traverse(){
    struct node *ptr = head;
    int x = 0;
    printf("\nDoubly linked list:\n");
    while (ptr){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
        x++;
    }
    return x;
}

int traverse_back(){
    struct node *ptr = head;
    int x = 0;
    printf("\nReverse of doubly linked list:\n");
    while (ptr && ptr->next) 
        ptr = ptr->next;
    while (ptr){
        printf("%d\n", ptr->data);
        ptr = ptr->prev;
        x++;
    }
    return x;
}

void insert_first(int x){
    struct node *cur = (struct node *) malloc(sizeof(struct node));
    if (!cur){
        printf("Space not available.\n");
        return;
    }
    cur->data = x;
    cur->prev = NULL;
    cur->next = head;
    if (head) head->prev = cur;
    head = cur;
}

void insert_last(int x){
    struct node *cur, *ptr;
    cur = (struct node *) malloc(sizeof(struct node));
    ptr = head;
    if (!cur){
        printf("Space not available.\n");
        return;
    }
    cur->data = x;
    cur->next = NULL;
    if (!head){
        cur->prev = NULL;
        head = cur;
        return;
    }
    while (ptr->next) 
        ptr = ptr->next;
    ptr->next = cur;
    cur->prev = ptr;
}

void delete_first(){
    struct node *ptr = head;
    if (!head) 
        return;
    if (ptr->next)
        ptr->next->prev = NULL;
    head = ptr->next;
    free(ptr);
}

void delete_last(){
    struct node *ptr = head;
    if (!head) 
        return;
    while (ptr->next)
        ptr = ptr->next;
    if (ptr->prev)
        ptr->prev->next = NULL;
    else
        head = NULL;
    free(ptr);
}

void reverse(){
    struct node *ptr, *cur = head;
    if (!head) return;
    while (cur->next)
        cur = cur->next;
    head = cur;
    while (cur){
        ptr = cur->next;
        cur->next = cur->prev;
        cur->prev = ptr;
        cur = cur->next;
    }
}

void main(){
    int x;
    insert_last(10);
    insert_first(20);
    insert_first(30);
    insert_first(40);
    insert_last(50);
    insert_last(60);
    insert_first(70);

    x = traverse();
    printf("Length = %d\n", x);
    delete_first();
    delete_last();
    delete_last();
    x = traverse_back();
    printf("Length = %d\n", x);
    
    reverse();
    delete_first();
    x = traverse();
    printf("Length = %d\n", x);
}