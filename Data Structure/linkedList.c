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
        printf("\t\t\tSpace not available.\n");
        return;
    }
    cur->data = key;
    cur->next = head;
    head = cur;
    printf("\n%d is inserted at head.\n", head->data);
}

void insertEnd(int key)
{
    struct node *ptr, *cur;
    ptr = head;
    cur = (struct node *)malloc(sizeof(struct node));
    if (!cur)
    {
        printf("\t\t\tSpace not available.\n");
        return;
    }
    cur->data = key;
    cur->next = NULL;
    if (!head)
    {
        head = cur;
        printf("\n%d is inserted at tail.\n", head->data);
        return;
    }
    while (ptr->next)
        ptr = ptr->next;
    ptr->next = cur;
    printf("\n%d is inserted at tail.\n", ptr->next->data);
}

void insertAtStart(int key, int index)
{
    struct node *cur, *ptr;
    int length, i;
    length = traverse();
    if (index <= 0)
    {
        printf("\t\t\tWrong input.\n");
        return;
    }
    if (index > length)
    {
        printf("Index is greater than list length; inserting at tail.\n");
        insertEnd(key);
        return;
    }
    if (index == 1)
    {
        insertStart(key);
        return;
    }
    ptr = head;
    cur = (struct node *)malloc(sizeof(struct node));
    if (!cur)
    {
        printf("\t\t\tSpace not available.\n");
        return;
    }
    cur->data = key;
    for (i = 1; i < index - 1; i++)
        ptr = ptr->next;
    cur->next = ptr->next;
    ptr->next = cur;
    printf("%d is inserted at index %d from head.\n", ptr->next->data, index);
}

void insertAtEnd(int key, int index)
{
    struct node *cur, *ptr, *temp;
    int length, i;
    length = traverse();
    if (index <= 0)
    {
        printf("\t\t\tWrong input.\n");
        return;
    }
    if (index > length)
    {
        printf("Index is greater than list length; inserting at head.\n");
        insertStart(key);
        return;
    }
    if (index == 1)
    {
        insertEnd(key);
        return;
    }
    ptr = temp = head;
    cur = (struct node *)malloc(sizeof(struct node));
    if (!cur)
    {
        printf("\t\t\tSpace not available.\n");
        return;
    }
    cur->data = key;
    for (i = 0; i < index; i++)
        temp = temp->next;
    while (temp)
    {
        temp = temp->next;
        ptr = ptr->next;
    }
    cur->next = ptr->next;
    ptr->next = cur;
    printf("%d is inserted at index %d from tail.\n", ptr->next->data, index);
}

void deleteStart()
{
    struct node *ptr = head;
    if (!head)
    {
        printf("\t\t\tWrong input.\n");
        return;
    }
    head = ptr->next;
    printf("\n%d is deleted from head.\n", ptr->data);
    free(ptr);
}

void deleteEnd()
{
    struct node *ptr = head;
    if (!ptr)
    {
        printf("\t\t\tWrong input.\n");
        return;
    }
    if (!ptr->next)
    {
        head = NULL;
        printf("\n%d is deleted from tail.\n", ptr->data);
        free(ptr);
        return;
    }
    while (ptr->next->next)
        ptr = ptr->next;
    printf("\n%d is deleted from tail.\n", ptr->next->data);
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
        printf("\t\t\tWrong input.\n");
        return;
    }
    if (index == 1)
    {
        head = head->next;
        printf("%d is deleted from head at index %d.\n", cur->data, index);
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
        printf("\t\t\tWrong input.\n");
        return;
    }
    for (i = 0; i < index; i++)
        ptr = ptr->next;
    if (!ptr)
    {
        head = head->next;
        printf("%d is deleted from tail at index %d.\n", cur->data, index);
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
    printf("%d is deleted from tail at index %d.\n", ptr->data, index);
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
        printf("\n%d is present at index %d from head.\n", key, index);
    else
        printf("\n%d is absent in linked list.\n", key);
}

void lastNode()
{
    struct node *ptr = head;
    if (!ptr)
    {
        printf("\nLast node does not exist.\n");
        return;
    }
    while (ptr->next)
        ptr = ptr->next;
    printf("\nLast node of linked list\t\t:\t%d\n", ptr->data);
}

void secondLastNode()
{
    struct node *ptr = head;
    if (!ptr || !ptr->next)
    {
        printf("\nSecond last node does not exist.\n");
        return;
    }
    while (ptr->next->next)
        ptr = ptr->next;
    printf("\nSecond last node of linked list\t:\t%d\n", ptr->data);
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

int checkCycle()
{
    struct node *slow, *fast;
    slow = fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            printf("\nCycle exists in the list.\n");
            return 1;
        }
    }
    printf("\nNo cycle in the list.\n");
    return 0;
}

void makeCycle()
{
    struct node *cur, *ptr = head;
    cur = (struct node *)malloc(sizeof(struct node));
    if (!cur && !ptr)
    {
        printf("\nCannot make cycle.\n");
        return;
    }
    cur->data = -1;
    cur->next = head;
    printf("\n%d inserted at head.\n", cur->data);
    printf("%d -> ", cur->data);
    if (head)
    {
        while (ptr->next)
        {
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        }
        ptr->next = head;
    }
    head = cur;
    if (!head->next)
        head->next = head;
    printf("%d (Cycle)\n", head->next->data);
}

void cleanList()
{
    int cycle = checkCycle();
    if (cycle)
    {
        struct node *ptr = head->next;
        if (ptr == head)
        {
            free(ptr);
            head = NULL;
            return;
        }
        while (ptr->next != head->next)
            ptr = ptr->next;
        ptr->next = NULL;
    }
    while (head)
        deleteStart();
}

void main()
{
    int length, key;

    insertAtStart(100, 0);
    insertAtEnd(100, 0);
    deleteFromStart(0);
    deleteFromEnd(0);
    deleteFromStart(1);
    deleteFromEnd(1);

    checkPalindrome();
    secondLastNode();
    lastNode();
    alternateNode();
    reverseList(head);

    length = traverse();
    printf("Length = %d\n", length);
    printf("\nEnter element to search\t\t\t:\t");
    scanf("%d", &key);
    searchNode(key);

    insertAtEnd(15, 1);
    insertAtStart(25, 1);
    insertAtStart(35, 1);
    insertAtEnd(45, 1);
    insertEnd(10);
    insertStart(20);

    deleteFromStart(1);
    deleteFromEnd(1);
    deleteStart();
    deleteEnd();

    insertStart(30);
    insertStart(40);
    insertEnd(50);
    insertEnd(60);

    insertAtStart(55, 2);
    length = traverse();
    insertAtStart(65, length);
    insertAtStart(70, 100);

    insertAtEnd(75, 2);
    length = traverse();
    insertAtEnd(85, length);
    insertAtEnd(80, 100);

    length = traverse();
    printf("Length = %d\n", length);
    printf("\nEnter element to search\t\t\t:\t");
    scanf("%d", &key);
    searchNode(key);

    deleteFromStart(100);
    deleteFromEnd(100);
    secondLastNode();
    lastNode();
    alternateNode();

    printf("\nReverse of Linked List\t\t\t:\t");
    traverseBack(head);
    reverseList(head);
    printf("\nLinked List is reversed.\n");

    deleteStart();
    deleteEnd();
    deleteEnd();
    deleteStart();

    deleteFromStart(3);
    length = traverse();
    deleteFromStart(length);
    deleteFromEnd(3);
    length = traverse();
    deleteFromEnd(length);
    printf("\nReverse of Linked List\t\t\t:\t");
    traverseBack(head);

    checkPalindrome();
    makeCycle();
    cleanList();
    length = traverse();
    printf("Length = %d\n", length);

    insertStart(1);
    insertEnd(1);
    insertStart(2);
    insertEnd(2);
    insertAtStart(3, 3);

    checkPalindrome();
    cleanList();
    makeCycle();
    cleanList();
    length = traverse();
    printf("Length = %d\n", length);
}