#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *head = NULL;

int traverse(){
    struct node *ptr = head;
    printf("\nCircular linked list:\n");
    int x = 0;
    if (head)
        do{
            printf("%d\n", ptr->data);
            ptr = ptr->next;
            x++;
        } while (ptr != head);
    return x;
}

void traverse_back(struct node *ptr){
    if (!head) 
        return;
    if (ptr->next == head){
        printf("%d\n", ptr->data);
        return;
    }
    traverse_back(ptr->next);
    printf("%d\n", ptr->data);
}

void insert_first(int x){
    struct node *cur = (struct node *) malloc(sizeof(struct node));
    if (!cur){
        printf("Space not available.\n");
        return;
    }
    cur->data = x;
    if (!head)
        cur->next = cur;
    else{
        cur->next = head;
        while (head->next != cur->next)
            head = head->next;
        head->next = cur;
    }
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
    if(!head)
        head = cur;
    else{
        while (ptr->next != head)
            ptr = ptr->next;
        ptr->next = cur;
    }
    cur->next = head;
}

void delete_first(){
    struct node *ptr = head, *cur = head;
    if (!head)
        return;
    if (ptr->next == head)
        head = NULL;
    else{
        while (ptr->next != head)
            ptr = ptr->next;
        head = cur->next;
        ptr->next = head;
    }
    free(cur);
}

void delete_last(){
    struct node *ptr = head, *cur = head;
    if (!head)
        return;
    if (ptr->next == head)
        head = NULL;
    else{
        while (ptr->next->next != head)
            ptr = ptr->next;
        cur = ptr->next;
        ptr->next = head;
    }
    free(cur);
}

void reverse(struct node *ptr){
    struct node *cur = ptr;
    if (!head)
        return;
    if (ptr->next != head){
        ptr = ptr->next;
        reverse(ptr);
        ptr->next = cur;
    }
    else{
        head->next = ptr;
        head = ptr;
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
    printf("\nReverse of circular linked list:\n");
    traverse_back(head);
    
    reverse(head);
    delete_first();
    x = traverse();
    printf("Length = %d\n", x);
}