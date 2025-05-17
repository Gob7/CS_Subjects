#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL;

struct node *insertLast(int x, struct node *list)
{
    struct node *ptr, *cur;
    ptr = list;
    cur = (struct node *)malloc(sizeof(struct node));
    cur->data = x;
    cur->next = NULL;
    if (!list)
        return cur;
    while (ptr->next)
        ptr = ptr->next;
    ptr->next = cur;
    return list;
}

struct node *sumNumbers(struct node *list1, struct node *list2)
{
    struct node *ans = NULL;
    int carry = 0, sum = 0;
    while (list1 || list2 || carry)
    {
        sum = carry;
        if (list1)
        {
            sum += list1->data;
            list1 = list1->next;
        }
        if (list2)
        {
            sum += list2->data;
            list2 = list2->next;
        }
        carry = sum / 10;
        ans = insertLast(sum % 10, ans);
    }
    return ans;
}

void printEnd(struct node *list)
{
    if (!list)
        return;
    else
    {
        printEnd(list->next);
        printf("%d", list->data);
    }
}

struct node *insertFirst(int x, struct node *list)
{
    struct node *cur = (struct node *)malloc(sizeof(struct node));
    cur->data = x;
    cur->next = list;
    return cur;
}

int convertNumber(struct node *list)
{
    int x = 0;
    while (list)
    {
        x *= 10;
        x += list->data;
        list = list->next;
    }
    // printf("x = %d\n", x);
    return x;
}

struct node *AddTwoNumbers(struct node *list1, struct node *list2)
{
    struct node *ans = NULL;
    int a, b, i;
    a = convertNumber(list1);
    b = convertNumber(list2);
    a += b;
    // printf("sum = %d\n", a);
    while (a)
    {
        i = a % 10;
        ans = insertFirst(i, ans);
        a /= 10;
    }
    return ans;
}

void printStart(char *name, struct node *list)
{
    printf("\n%s = ", name);
    while (list)
    {
        printf("%d", list->data);
        list = list->next;
    }
}

void main()
{
    struct node *list1 = NULL, *list2 = NULL, *listOld = NULL, *listNew = NULL;
    list1 = insertFirst(1, list1);
    list1 = insertFirst(7, list1);
    list1 = insertFirst(6, list1);
    list2 = insertFirst(8, list2);
    list2 = insertFirst(0, list2);
    list2 = insertFirst(9, list2);
    printStart("a", list1);
    printStart("b", list2);
    listOld = AddTwoNumbers(list1, list2);
    printStart("a + b", listOld);

    printf("\n\na = ");
    printEnd(list1);
    printf("\nb = ");
    printEnd(list2);
    listNew = sumNumbers(list1, list2);
    printf("\na + b = ");
    printEnd(listNew);
}