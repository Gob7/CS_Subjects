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
    printf("\nDoubly Circular Linked List:\n");
    if (head)
    {
        do
        {
            printf("%d <-> ", ptr->data);
            ptr = ptr->next;
            x++;
        } while (ptr != head);
        printf("head\n");
    }
    else
        printf("NULL\n");
    return x;
}

int traverse_back()
{
    struct node *ptr = tail;
    int x = 0;
    printf("\nReverse of Doubly Circular Linked List:\n");
    if (tail)
    {
        do
        {
            printf("%d <-> ", ptr->data);
            ptr = ptr->prev;
            x++;
        } while (ptr != tail);
        printf("tail\n");
    }
    else
        printf("NULL\n");
    return x;
}

struct node *insert(int x)
{
    struct node *cur;
    cur = (struct node *)malloc(sizeof(struct node));
    if (!cur)
        printf("Space not available.\n");
    else
    {
        cur->data = x;
        if (head)
        {
            cur->prev = tail;
            cur->next = head;
            tail->next = cur;
            head->prev = cur;
        }
        else
        {
            cur->next = cur;
            cur->prev = cur;
            head = cur;
            tail = cur;
        }
    }
    return cur;
}

void insert_first(int x)
{
    struct node *cur;
    cur = insert(x);
    if (cur)
    {
        head = cur;
        printf("%d is inserted at head.\n", head->data);
    }
}

void insert_last(int x)
{
    struct node *cur;
    cur = insert(x);
    if (cur)
    {
        tail = cur;
        printf("%d is inserted at tail.\n", tail->data);
    }
}

void delete_first()
{
    struct node *ptr = head;
    if (!head)
        return;
    if (ptr->next == ptr)
    {
        head = NULL;
        tail = NULL;
    }
    else
    {
        head = ptr->next;
        tail->next = head;
        head->prev = tail;
    }
    printf("%d is deleted from head.\n", ptr->data);
    free(ptr);
}

void delete_last()
{
    struct node *ptr = tail;
    if (!tail)
        return;
    if (ptr->prev == ptr)
    {
        head = NULL;
        tail = NULL;
    }
    else
    {
        tail = ptr->prev;
        tail->next = head;
        head->prev = tail;
    }
    printf("%d is deleted from tail.\n", ptr->data);
    free(ptr);
}

void reverse()
{
    struct node *ptr, *cur = head;
    head = tail;
    tail = cur;
    if (!head)
        return;
    do
    {
        ptr = cur->next;
        cur->next = cur->prev;
        cur->prev = ptr;
        cur = ptr;
    } while (cur != tail);
    printf("Doubly Circular Linked List is reversed.\n");
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
    printf("Length = %d\n\n", x);
}