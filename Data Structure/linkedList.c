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
    printf("\nLinked list:\n");
    int x = 0;
    while (ptr)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
        x++;
    }
    return x;
}

void traverse_back(struct node *ptr)
{
    if (!ptr)
        return;
    traverse_back(ptr->next);
    printf("%d\n", ptr->data);
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
        printf("%d present in linked list.\n", x);
    else
        printf("%d absent in linked list.\n", x);
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
        printf("%d\n", ptr->data);
        ptr = ptr->next->next;
    }
    if (ptr)
        printf("%d\n", ptr->data);
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

struct node *insertFirst(int x, struct node *list)
{
    struct node *cur = (struct node *)malloc(sizeof(struct node));
    cur->data = x;
    cur->next = list;
    printf("cur->data = %d\n", cur->data);
    return cur;
}

int convertNumber(struct node *list)
{
    int x = 0;
    while (!list)
    {
        x *= 10;
        x += list->data;
        list = list->next;
    }
    return x;
}

struct node *AddTwoNumbers(struct node *list1, struct node *list2)
{
    struct node *ans = NULL;
    int a, b, i;
    a = convertNumber(list1);
    b = convertNumber(list2);
    a += b;
    while (a)
    {
        i = a % 10;
        ans = insertFirst(i, ans);
        a /= 10;
    }
    return ans;
}

void print(struct node *list)
{
    printf("Num = ");
    while (!list)
    {
        printf("%d", list->data);
        list = list->next;
    }
    printf("\n");
}

void main()
{
    // int x;
    // insert_last(10);
    // insert_first(20);
    // insert_first(30);
    // insert_first(40);
    // insert_last(50);
    // insert_last(60);
    // insert_first(70);

    // x = traverse();
    // printf("Length = %d\n", x);
    // second_last();
    // last_node();
    // alternate();
    // delete_first();
    // delete_last();
    // delete_last();
    // printf("\nReverse of linked list:\n");
    // traverse_back(head);

    // reverse(head);
    // delete_first();
    // x = traverse();
    // printf("Length = %d\n", x);

    // printf("Enter element to search: ");
    // scanf("%d", &x);
    // search(x);

    struct node *list1 = NULL, *list2 = NULL, *list = NULL;
    list1 = insertFirst(3, list1);
    list1 = insertFirst(0, list1);
    list1 = insertFirst(4, list1);
    list2 = insertFirst(1, list2);
    list2 = insertFirst(5, list2);
    list2 = insertFirst(2, list2);
    print(list1);
    print(list2);
    list = AddTwoNumbers(list1, list2);
    print(list);
}