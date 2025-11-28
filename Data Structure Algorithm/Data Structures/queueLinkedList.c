// Queue using linked list
// insert at end and delete from front
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
} *head = NULL;

void enQueue(int x)
{
    struct node *ptr, *cur;
    ptr = head;
    cur = (struct node *)malloc(sizeof(struct node));
    if (!cur)
    {
        printf("Space not available.\n");
        return;
    }

    cur->value = x;
    cur->next = NULL;
    if (!head)
        head = cur;
    else
    {
        while (ptr->next)
            ptr = ptr->next;
        ptr->next = cur;
    }
    printf("%d inserted.\n", cur->value);
}

void deQueue()
{
    struct node *ptr = head;
    if (!head)
    {
        printf("\nQueue Underflow.\n");
        return;
    }
    head = ptr->next;
    printf("%d deleted.\n", ptr->value);
    free(ptr);
}

void peek()
{
    if (!head)
    {
        printf("\nQueue Underflow.\n");
        return;
    }
    printf("%d is peeked.\n", head->value);
}

void show()
{
    struct node *ptr = head;
    if (!head)
    {
        printf("\nQueue Underflow.\n");
        return;
    }
    printf("\nQueue Contains:\n");
    while (ptr)
    {
        printf("%d -> ", ptr->value);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void main()
{
    deQueue();
    peek();
    show();

    enQueue(5);
    enQueue(8);
    enQueue(3);
    enQueue(4);
    enQueue(0);
    enQueue(5);
    enQueue(2);
    show();

    deQueue();
    deQueue();
    peek();
    deQueue();
    deQueue();
    enQueue(9);
    peek();
    enQueue(7);
    show();
}