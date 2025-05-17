#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev, *next;
} *head = NULL, *tail = NULL;

int traverse()
{
    struct node *ptr = head;
    int x = 0;
    printf("\nDoubly Linked List:\n");
    while (ptr)
    {
        printf("%d <-> ", ptr->data);
        ptr = ptr->next;
        x++;
    }
    printf("NULL\n");
    return x;
}

int traverse_back()
{
    struct node *ptr = tail;
    int x = 0;
    printf("\nReverse of Doubly Linked List:\n");
    while (ptr)
    {
        printf("%d <-> ", ptr->data);
        ptr = ptr->prev;
        x++;
    }
    printf("NULL\n");
    return x;
}

void insert_first(int x)
{
    struct node *cur = (struct node *)malloc(sizeof(struct node));
    if (!cur)
    {
        printf("Space not available.\n");
        return;
    }
    cur->data = x;
    cur->prev = NULL;
    cur->next = head;
    if (head)
        head->prev = cur;
    else
        tail = cur;
    head = cur;
    printf("%d is inserted at head.\n", head->data);
}

void insert_last(int x)
{
    struct node *cur;
    cur = (struct node *)malloc(sizeof(struct node));
    if (!cur)
    {
        printf("Space not available.\n");
        return;
    }
    cur->data = x;
    cur->next = NULL;
    cur->prev = tail;
    if (tail)
        tail->next = cur;
    else
        head = cur;
    tail = cur;
    printf("%d is inserted at tail.\n", tail->data);
}

void delete_first()
{
    struct node *ptr = head;
    if (!head)
        return;
    if (ptr->next)
        ptr->next->prev = NULL;
    else
        tail = NULL;
    printf("%d is deleted from head.\n", ptr->data);
    head = ptr->next;
    free(ptr);
}

void delete_last()
{
    struct node *ptr = tail;
    if (!tail)
        return;
    if (ptr->prev)
        ptr->prev->next = NULL;
    else
        head = NULL;
    printf("%d is deleted from tail.\n", ptr->data);
    tail = ptr->prev;
    free(ptr);
}

void reverse()
{
    struct node *ptr, *cur = head;
    head = tail;
    tail = cur;
    if (!head)
        return;
    while (cur)
    {
        ptr = cur->next;
        cur->next = cur->prev;
        cur->prev = ptr;
        cur = ptr;
    }
    printf("Doubly Linked List is reversed.\n");
}

void main()
{
    int x;
    insert_last(10);
    insert_first(20);
    insert_first(30);
    insert_first(40);
    insert_last(50);
    insert_last(60);
    insert_first(70);

    x = traverse();
    printf("Length = %d\n\n", x);
    delete_first();
    delete_last();
    delete_last();
    x = traverse_back();
    printf("Length = %d\n\n", x);

    reverse();
    delete_first();
    x = traverse();
    printf("Length = %d\n", x);
}