//stack using linked list
#include <stdio.h>
#include <stdlib.h>
struct node {
    int value;
    struct node *next;
} *head = NULL;

void push(int x){
    struct node *cur = (struct node *) malloc(sizeof(struct node));
    if (!cur){
        printf("Space not available.\n");
        return;
    }
    cur->value = x;
    cur->next = head;
    head = cur; 
    printf("%d pushed.\n", head->value);
}
void pop(){
    struct node *ptr = head;
    if (!head){
        printf("\nStack Underflow.\n");
        return;
    }
    head = ptr->next;
    printf("%d popped.\n", ptr->value);
    free(ptr);
}

void peek(){
    if (!head){
        printf("\nStack Underflow.\n");
        return;
    }
    printf("%d is peeked.\n", head->value);
}
void show(){
    struct node *ptr = head;
    if (!head){
        printf("\nStack Underflow.\n");
        return;
    }
    printf("\nStack Contains:\n");
    while (ptr){
        printf("%d\n", ptr->value);
        ptr = ptr->next;
    }
    printf("\n");
}

void main(){
    pop();
    peek();
    show();

    push(5);
    push(8);
    push(3);
    push(4);
    push(0);
    push(5);
    push(2);
    show();

    pop();
    pop(); 
    peek();
    pop();
    pop();
    peek();
    push(9);
    push(7);
    show();
}