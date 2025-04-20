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
    printf("\nDoubly circular linked list:\n");
    if (head){
        do{
            printf("%d\n", ptr->data);
            ptr = ptr->next;
            x++;
        } while (ptr != head);
    }
    return x;
}

int traverse_back(){
    struct node *ptr = head;
    int x = 0;
    printf("\nReverse of doubly circular linked list:\n");
    if (head){
        ptr = ptr->prev;
        do{
            printf("%d\n", ptr->data);
            ptr = ptr->prev;
            x++;
        } while (ptr->next != head);
    }
    return x;
}

void insert_last(int x){
    struct node *cur;
    cur = (struct node *) malloc(sizeof(struct node));
    if (!cur){
        printf("Space not available.\n");
        return;
    }
    cur->data = x;
    if (head){
        cur->prev = head->prev;
        cur->next = head;
        head->prev->next = cur;
        head->prev = cur;
    }
    else{
        cur->next = cur;
        cur->prev = cur;
        head = cur;
    }
}

void insert_first(int x){
    insert_last(x);
    if (head->prev != head)
        head = head->prev;
}

void delete_first(){
    struct node *ptr = head;
    if (!head) 
        return;
    if (ptr->next == ptr)
        head = NULL;
    else{
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        head = ptr->next;
    }
    free(ptr);
}

void delete_last(){
    struct node *ptr = head;
    if (!head) 
        return;
    if (ptr->prev == ptr)
        head = NULL;
    else{
        ptr = ptr->prev;
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
    }
    free(ptr);
}

void reverse(){
    struct node *ptr, *cur = head;
    if (!head) return;
    // printf("\nhead = %d\n", head->data);
    cur = cur->prev;
    while (cur != head){
        // printf("\n%d->%d->%d\n", cur->prev->data, cur->data, cur->next->data);
        ptr = cur->next;
        cur->next = cur->prev;
        cur->prev = ptr;
        // printf("%d->%d->%d\n", cur->prev->data, cur->data, cur->next->data);
        cur = cur->next;
    }
    ptr = head->next;
    head->next = head->prev;
    head->prev = ptr;
    head = head->next;
    // printf("\nhead = %d\n", head->data);
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