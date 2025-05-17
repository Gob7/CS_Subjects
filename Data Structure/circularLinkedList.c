#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL;

int traverse()
{
    struct node *ptr = head;
    printf("\nCircular Linked List:\n");
    int x = 0;
    if (head)
    {
        do
        {
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
            x++;
        } while (ptr != head);
        printf("head\n");
    }
    else
        printf("NULL\n");
    return x;
}

void traverse_back(struct node *ptr)
{
    if (!head)
        return;
    if (ptr->next == head)
    {
        printf("%d, ", ptr->data);
        return;
    }
    traverse_back(ptr->next);
    printf("%d, ", ptr->data);
}

void insert_first(int x)
{
    struct node *cur, *ptr;
    cur = (struct node *)malloc(sizeof(struct node));
    ptr = head;
    if (!cur)
    {
        printf("Space not available.\n");
        return;
    }
    cur->data = x;
    if (!head)
        cur->next = cur;
    else
    {
        cur->next = head;
        while (ptr->next != head)
            ptr = ptr->next;
        ptr->next = cur;
    }
    head = cur;
    printf("%d is inserted at head.\n", head->data);
}

void insert_last(int x)
{
    struct node *cur, *ptr;
    cur = (struct node *)malloc(sizeof(struct node));
    ptr = head;
    if (!cur)
    {
        printf("Space not available.\n");
        return;
    }
    cur->data = x;
    if (!head)
        head = cur;
    else
    {
        while (ptr->next != head)
            ptr = ptr->next;
        ptr->next = cur;
    }
    cur->next = head;
    printf("%d is inserted at tail.\n", cur->data);
}

void delete_first()
{
    struct node *ptr = head, *cur = head;
    if (!head)
        return;
    if (ptr->next == head)
        head = NULL;
    else
    {
        while (ptr->next != head)
            ptr = ptr->next;
        head = cur->next;
        ptr->next = head;
    }
    printf("%d is deleted from head.\n", cur->data);
    free(cur);
}

void delete_last()
{
    struct node *ptr = head, *cur = head;
    if (!head)
        return;
    if (ptr->next == head)
        head = NULL;
    else
    {
        while (ptr->next->next != head)
            ptr = ptr->next;
        cur = ptr->next;
        ptr->next = head;
    }
    printf("%d is deleted from tail.\n", cur->data);
    free(cur);
}

void reverse(struct node *ptr)
{
    struct node *cur = ptr;
    if (!head)
        return;
    if (ptr->next != head)
    {
        ptr = ptr->next;
        reverse(ptr);
        ptr->next = cur;
    }
    else
    {
        head->next = ptr;
        head = ptr;
    }
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
    printf("\nReverse of Circular Linked List:\n");
    traverse_back(head);

    reverse(head);
    printf("\nCircular Linked List is reversed.\n");
    delete_first();
    x = traverse();
    printf("Length = %d\n", x);
}