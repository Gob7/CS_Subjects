// stack using linked list
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
    int value;
    struct node *next;
} *head = NULL;

void push(int x)
{
    struct node *cur = (struct node *)malloc(sizeof(struct node));
    if (!cur)
    {
        printf("\nStack Overflow.\n");
        return;
    }
    cur->value = x;
    cur->next = head;
    head = cur;
    printf("%d pushed.\n", head->value);
}

int pop()
{
    struct node *ptr = head;
    if (!head)
    {
        printf("\nStack Underflow.\n");
        return INT_MIN;
    }
    head = ptr->next;
    printf("%d popped.\n", ptr->value);
    int x = ptr->value;
    free(ptr);
    return x;
}

void peek()
{
    if (!head)
    {
        printf("\nStack Underflow.\n");
        return;
    }
    printf("%d is peeked.\n", head->value);
}

void show()
{
    struct node *ptr = head;
    if (!head)
    {
        printf("\nStack Underflow.\n");
        return;
    }
    printf("\nStack Contains:\n");
    while (ptr)
    {
        printf("%d -> ", ptr->value);
        ptr = ptr->next;
    }
    printf("NULL\n\n");
}

void main()
{
    int x;
    x = pop();
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

    x = pop();
    x = pop();
    peek();
    x = pop();
    x = pop();
    peek();
    push(9);
    push(7);
    show();
}