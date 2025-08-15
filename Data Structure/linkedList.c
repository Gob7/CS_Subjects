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

void traverseBack(struct node *ptr)
{
    if (!ptr)
        return;
    traverseBack(ptr->next);
    printf("%d, ", ptr->data);
}

void insertStart(int key)
{
    struct node *cur = (struct node *)malloc(sizeof(struct node));
    if (!cur)
    {
        printf("Space not available.\n");
        return;
    }
    cur->data = key;
    cur->next = head;
    head = cur;
    printf("%d is inserted at head.\n", head->data);
}

void insertEnd(int key)
{
    struct node *ptr, *cur;
    ptr = head;
    cur = (struct node *)malloc(sizeof(struct node));
    if (!cur)
    {
        printf("Space not available.\n");
        return;
    }
    cur->data = key;
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

void insertAtStart(int key, int index) {}

void insertAtEnd(int key, int index) {}

void deleteStart()
{
    struct node *ptr = head;
    if (!head)
        return;
    head = ptr->next;
    printf("%d is deleted from head.\n", ptr->data);
    free(ptr);
}

void deleteEnd()
{
    struct node *ptr = head;
    if (!ptr)
        return;
    if (!ptr->next)
    {
        head = NULL;
        printf("%d is deleted from head.\n", ptr->data);
        free(ptr);
        return;
    }
    while (ptr->next->next)
        ptr = ptr->next;
    printf("%d is deleted from tail.\n", ptr->next->data);
    free(ptr->next);
    ptr->next = NULL;
}

void deleteFromStart(int index)
{
    struct node *cur = head, *ptr;
    int length;
    length = traverse();
    if (length == 0 || index <= 0 || index > length)
    {
        printf("Wrong input.\n");
        return;
    }
    if (index == 1)
    {
        head = head->next;
        printf("%d is deleted from head at index 1.\n", cur->data);
        free(cur);
        return;
    }
    for (int i = 1; i < index - 1; i++)
        cur = cur->next;
    ptr = cur->next;
    cur->next = ptr->next;
    printf("%d is deleted from head at index %d.\n", ptr->data, index);
    free(ptr);
}

void deleteFromEnd(int index)
{
    struct node *cur = head, *ptr = head;
    int length, i;
    length = traverse();
    if (length == 0 || index <= 0 || index > length)
    {
        printf("Wrong input.\n");
        return;
    }
    for (i = 0; i < index; i++)
        ptr = ptr->next;
    if (!ptr)
    {
        head = head->next;
        printf("%d is deleted from tail at index 1.\n", cur->data);
        free(cur);
        return;
    }
    while (ptr->next)
    {
        ptr = ptr->next;
        cur = cur->next;
    }
    ptr = cur->next;
    cur->next = ptr->next;
    printf("%d is deleted from tail at index %d.\n", ptr->data, length - index + 1);
    free(ptr);
}

void searchNode(int key)
{
    struct node *ptr = head;
    int index = 1;
    while (ptr && ptr->data != key)
    {
        ptr = ptr->next;
        index++;
    }
    if (ptr)
        printf("%d is present at index %d.\n", key, index);
    else
        printf("%d is absent in linked list.\n", key);
}

void lastNode()
{
    struct node *ptr = head;
    if (!ptr)
    {
        printf("No last element exist.\n");
        return;
    }
    while (ptr->next)
        ptr = ptr->next;
    printf("Last element of linked list\t\t:\t%d\n", ptr->data);
}

void secondLastNode()
{
    struct node *ptr = head;
    if (!ptr || !ptr->next)
    {
        printf("No second last element exist.\n");
        return;
    }
    while (ptr->next->next)
        ptr = ptr->next;
    printf("Second last element of linked list\t:\t%d\n", ptr->data);
}

void alternateNode()
{
    struct node *ptr = head;
    printf("\nAlternate elements\t\t\t:\t");
    while (ptr && ptr->next)
    {
        printf("%d, ", ptr->data);
        ptr = ptr->next->next;
    }
    if (ptr)
        printf("%d, ", ptr->data);
    printf("\n");
}

void reverseList(struct node *ptr)
{
    struct node *cur = ptr;
    if (!head)
        return;
    if (ptr->next)
    {
        ptr = ptr->next;
        reverseList(ptr);
        ptr->next = cur;
    }
    else
    {
        head->next = NULL;
        head = ptr;
    }
}

void checkPalindrome()
{
    struct node *ptr = head, *cur = NULL, *temp;
    int length = traverse();
    while (ptr)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        if (!temp)
            return;
        temp->data = ptr->data;
        temp->next = cur;
        cur = temp;
        ptr = ptr->next;
    }
    ptr = head;
    while (ptr && cur)
    {
        if (ptr->data != cur->data)
        {
            printf("\nLinked List is not a palindrome.\n");
            return;
        }
        ptr = ptr->next;
        cur = cur->next;
    }
    printf("\nLinked List is a palindrome!\n");
}

void main()
{
    int length, key;

    // deleteFromStart(1);
    // deleteFromEnd(1);
    // insertEnd(10);
    // deleteFromStart(0);
    // deleteFromEnd(0);
    // insertStart(20);
    // deleteFromStart(1);
    // deleteFromEnd(2);
    // insertStart(30);
    // insertStart(40);
    // insertEnd(50);
    // insertEnd(60);
    // insertStart(70);

    // length = traverse();
    // printf("Length = %d\n", length);
    // printf("\nEnter element to search\t\t\t:\t");
    // scanf("%d", &key);
    // searchNode(key);

    // deleteFromStart(100);
    // deleteFromEnd(100);
    // secondLastNode();
    // lastNode();
    // alternateNode();
    // deleteStart();
    // deleteEnd();
    // deleteEnd();
    // printf("\nReverse of Linked List\t\t\t:\t");
    // traverseBack(head);

    // reverseList(head);
    // printf("\nLinked List is reversed.\n");
    // deleteStart();
    // deleteFromStart(2);
    // deleteFromStart(5);
    // deleteFromEnd(1);
    // deleteFromEnd(4);

    // insertStart(1);
    // insertEnd(1);
    // insertStart(2);
    // insertEnd(2);
    // insertStart(3);
    // insertEnd(3);
    // insertStart(4);
    // insertEnd(4);
    // checkPalindrome();
}