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
    printf("\nLinked List:\n");
    int x = 0;
    while (ptr)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
        x++;
    }
    printf("NULL\n");
    return x;
}

void traverse_back(struct node *ptr)
{
    if (!ptr)
        return;
    traverse_back(ptr->next);
    printf("%d, ", ptr->data);
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
    cur->next = head;
    head = cur;
    printf("%d is inserted at head.\n", head->data);
}

void insert_last(int x)
{
    struct node *ptr, *cur;
    ptr = head;
    cur = (struct node *)malloc(sizeof(struct node));
    if (!cur)
    {
        printf("Space not available.\n");
        return;
    }
    cur->data = x;
    cur->next = NULL;
    if (!head)
    {
        head = cur;
        printf("%d is inserted at head.\n", head->data);
        return;
    }
    while (ptr->next)
        ptr = ptr->next;
    ptr->next = cur;
    printf("%d is inserted at tail.\n", ptr->next->data);
}

void delete_first()
{
    struct node *ptr = head;
    if (!head)
        return;
    head = ptr->next;
    printf("%d is deleted from head.\n", ptr->data);
    free(ptr);
}

void delete_last()
{
    struct node *ptr = head;
    if (!ptr)
        return;
    if (!ptr->next)
    {
        head = NULL;
        printf("%d is deleted from head.\n", ptr->data);
        free(ptr);
    }
    while (ptr->next->next)
        ptr = ptr->next;
    printf("%d is deleted from tail.\n", ptr->next->data);
    free(ptr->next);
    ptr->next = NULL;
}

void search(int x)
{
    struct node *ptr = head;
    while (ptr && ptr->data != x)
        ptr = ptr->next;
    if (ptr)
        printf("%d is present in linked list.\n", x);
    else
        printf("%d is absent in linked list.\n", x);
}

void last_node()
{
    struct node *ptr = head;
    if (!ptr)
    {
        printf("No last element exist.\n");
        return;
    }
    while (ptr->next)
        ptr = ptr->next;
    printf("Last element of linked list = %d\n", ptr->data);
}

void second_last()
{
    struct node *ptr = head;
    if (!ptr || !ptr->next)
    {
        printf("No second last element exist.\n");
        return;
    }
    while (ptr->next->next)
        ptr = ptr->next;
    printf("Second last element of linked list = %d\n", ptr->data);
}

void alternate()
{
    struct node *ptr = head;
    printf("\nAlternate elements:\n");
    while (ptr && ptr->next)
    {
        printf("%d, ", ptr->data);
        ptr = ptr->next->next;
    }
    if (ptr)
        printf("%d, ", ptr->data);
    printf("\n");
}

void reverse(struct node *ptr)
{
    struct node *cur = ptr;
    if (!head)
        return;
    if (ptr->next)
    {
        ptr = ptr->next;
        reverse(ptr);
        ptr->next = cur;
    }
    else
    {
        head->next = NULL;
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
    second_last();
    last_node();
    alternate();
    delete_first();
    delete_last();
    delete_last();
    printf("\nReverse of Linked List:\n");
    traverse_back(head);

    reverse(head);
    printf("\nLinked List is reversed.\n");
    delete_first();
    x = traverse();
    printf("Length = %d\n\n", x);

    printf("Enter element to search: ");
    scanf("%d", &x);
    search(x);
}