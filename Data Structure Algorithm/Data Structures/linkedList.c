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
    printf("Linked List\t\t:\t");
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

void reverse()
{
    struct node *pre = NULL, *cur = head, *post;
    while (cur)
    {
        post = cur->next;
        cur->next = pre;
        pre = cur;
        cur = post;
    }
    head = pre;
    printf("Reverse of ");
    traverse();
}

void reverseRecursion(struct node *ptr)
{
    struct node *cur = ptr;
    if (!head)
        return;
    if (ptr->next)
    {
        ptr = ptr->next;
        reverseRecursion(ptr);
        ptr->next = cur;
    }
    else
    {
        head->next = NULL;
        head = ptr;
    }
}

void insertAtStart(int key)
{
    struct node *cur = malloc(sizeof *cur);
    if (!cur)
    {
        printf("\t\tSpace unavailable\n");
        return;
    }
    cur->data = key;
    cur->next = head;
    head = cur;
    printf("%d inserted at head.\n", head->data);
}

void insertAtEnd(int key)
{
    struct node *ptr, *cur;
    ptr = head;
    cur = malloc(sizeof *cur);
    if (!cur)
    {
        printf("\t\tSpace unavailable\n");
        return;
    }
    cur->data = key;
    cur->next = NULL;
    if (!head)
    {
        head = cur;
        printf("%d inserted at tail.\n", head->data);
        return;
    }
    while (ptr->next)
        ptr = ptr->next;
    ptr->next = cur;
    printf("%d inserted at tail.\n", ptr->next->data);
}

void insertFromStart(int key, int index)
{
    struct node *cur, *ptr;
    int size, i;
    size = traverse();
    if (index <= 0)
    {
        printf("\t\tWrong input\n");
        return;
    }
    if (index > size)
    {
        printf("index > list size; Inserting at tail.\n");
        insertAtEnd(key);
        return;
    }
    if (index == 1)
    {
        insertAtStart(key);
        return;
    }
    ptr = head;
    cur = malloc(sizeof *cur);
    if (!cur)
    {
        printf("\t\tSpace unavailable\n");
        return;
    }
    cur->data = key;
    for (i = 1; i < index - 1; i++)
        ptr = ptr->next;
    cur->next = ptr->next;
    ptr->next = cur;
    printf("%d inserted at index %d from head.\n", ptr->next->data, index);
}

void insertFromEnd(int key, int index)
{
    struct node *cur, *ptr, *temp;
    int size, i;
    size = traverse();
    if (index <= 0)
    {
        printf("\t\tWrong input\n");
        return;
    }
    if (index > size)
    {
        printf("index > list size; Inserting at head.\n");
        insertAtStart(key);
        return;
    }
    if (index == 1)
    {
        insertAtEnd(key);
        return;
    }
    ptr = temp = head;
    cur = malloc(sizeof *cur);
    if (!cur)
    {
        printf("\t\tSpace unavailable\n");
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
    printf("%d inserted at index %d from tail.\n", ptr->next->data, index);
}

void deleteAtStart()
{
    struct node *ptr = head;
    if (!head)
    {
        printf("\t\tWrong input\n");
        return;
    }
    head = ptr->next;
    printf("%d deleted from head.\n", ptr->data);
    free(ptr);
}

void deleteAtEnd()
{
    struct node *ptr = head;
    if (!ptr)
    {
        printf("\t\tWrong input\n");
        return;
    }
    if (!ptr->next)
    {
        head = NULL;
        printf("%d deleted from tail.\n", ptr->data);
        free(ptr);
        return;
    }
    while (ptr->next->next)
        ptr = ptr->next;
    printf("%d deleted from tail.\n", ptr->next->data);
    free(ptr->next);
    ptr->next = NULL;
}

void deleteFromStart(int index)
{
    struct node *cur = head, *ptr;
    int size;
    size = traverse();
    if (size == 0 || index <= 0 || index > size)
    {
        printf("\t\tWrong input\n");
        return;
    }
    if (index == 1)
    {
        head = head->next;
        printf("%d deleted at index %d from head.\n", cur->data, index);
        free(cur);
        return;
    }
    for (int i = 1; i < index - 1; i++)
        cur = cur->next;
    ptr = cur->next;
    cur->next = ptr->next;
    printf("%d deleted at index %d from head.\n", ptr->data, index);
    free(ptr);
}

void deleteFromEnd(int index)
{
    struct node *cur = head, *ptr = head;
    int size, i;
    size = traverse();
    if (size == 0 || index <= 0 || index > size)
    {
        printf("\t\tWrong input\n");
        return;
    }
    for (i = 0; i < index; i++)
        ptr = ptr->next;
    if (!ptr)
    {
        head = head->next;
        printf("%d deleted at index %d from tail.\n", cur->data, index);
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
    printf("%d deleted at index %d from tail.\n", ptr->data, index);
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
        printf("%d present at index %d from head.\n", key, index);
    else
        printf("%d absent in linked list.\n", key);
}

void lastNode()
{
    struct node *ptr = head;
    if (!ptr)
    {
        printf("Last node doesn't exist.\n");
        return;
    }
    while (ptr->next)
        ptr = ptr->next;
    printf("Last node\t\t:\t%d\n", ptr->data);
}

void secondLastNode()
{
    struct node *ptr = head;
    if (!ptr || !ptr->next)
    {
        printf("Second last node doesn't exist.\n");
        return;
    }
    while (ptr->next->next)
        ptr = ptr->next;
    printf("Second last node\t:\t%d\n", ptr->data);
}

void alternateNode()
{
    struct node *ptr = head;
    printf("Alternate nodes\t\t:\t");
    while (ptr && ptr->next)
    {
        printf("%d, ", ptr->data);
        ptr = ptr->next->next;
    }
    if (ptr)
        printf("%d, ", ptr->data);
    printf("\n");
}

void checkPalindrome()
{
    struct node *ptr = head, *cur = NULL, *temp;
    int size = traverse();
    while (ptr)
    {
        temp = malloc(sizeof(struct node));
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
            printf("Not a palindrome.\n");
            return;
        }
        ptr = ptr->next;
        cur = cur->next;
    }
    printf("Yes, a palindrome!\n");
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
            printf("Cycle exists.\n");
            return 1;
        }
    }
    printf("No cycle.\n");
    return 0;
}

void makeCycle()
{
    struct node *cur, *ptr = head;
    cur = malloc(sizeof *cur);
    if (!cur && !ptr)
    {
        printf("Can't make cycle.\n");
        return;
    }
    cur->data = -1;
    cur->next = head;
    printf("%d inserted at head.\n", cur->data);
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
        deleteAtStart();
}

void main()
{
    int size, key;

    insertFromStart(100, 0);
    insertFromEnd(100, 0);
    deleteFromStart(0);
    deleteFromEnd(0);
    deleteFromStart(1);
    deleteFromEnd(1);

    checkPalindrome();
    secondLastNode();
    lastNode();
    alternateNode();
    reverse();
    reverseRecursion(head);

    size = traverse();
    printf("Size\t\t\t=\t%d\n", size);
    printf("To search\t\t:\t");
    scanf("%d", &key);
    searchNode(key);

    insertFromEnd(15, 1);
    insertFromStart(25, 1);
    insertFromStart(35, 1);
    insertFromEnd(45, 1);
    insertAtEnd(10);
    insertAtStart(20);

    deleteFromStart(1);
    deleteFromEnd(1);
    deleteAtStart();
    deleteAtEnd();

    insertAtStart(30);
    insertAtStart(40);
    insertAtEnd(50);
    insertAtEnd(60);

    insertFromStart(55, 2);
    size = traverse();
    insertFromStart(65, size);
    insertFromStart(70, 100);

    insertFromEnd(75, 2);
    size = traverse();
    insertFromEnd(85, size);
    insertFromEnd(80, 100);

    size = traverse();
    printf("Size\t\t\t=\t%d\n", size);
    printf("To search\t\t:\t");
    scanf("%d", &key);
    searchNode(key);

    deleteFromStart(100);
    deleteFromEnd(100);
    secondLastNode();
    lastNode();
    alternateNode();

    printf("Reverse of Linked List\t\t:\t");
    traverseBack(head);
    printf("NULL\n");
    reverseRecursion(head);

    deleteAtStart();
    deleteAtEnd();
    deleteAtEnd();
    deleteAtStart();

    deleteFromStart(3);
    size = traverse();
    deleteFromStart(size);
    deleteFromEnd(3);
    size = traverse();
    deleteFromEnd(size);
    reverse();

    checkPalindrome();
    makeCycle();
    cleanList();
    size = traverse();
    printf("Size\t\t\t=\t%d\n", size);

    insertAtStart(1);
    insertAtEnd(1);
    insertAtStart(2);
    insertAtEnd(2);
    insertFromStart(3, 3);

    checkPalindrome();
    cleanList();
    makeCycle();
    cleanList();
    size = traverse();
    printf("Size\t\t\t=\t%d\n", size);
}