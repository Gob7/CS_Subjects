#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL;

struct node *insertStart(int x, struct node *list)
{
    struct node *cur = malloc(sizeof *cur);
    cur->data = x;
    cur->next = list;
    return cur;
}

struct node *insertEnd(int x, struct node *list)
{
    struct node *ptr = list, *cur = malloc(sizeof *cur);
    cur->data = x;
    cur->next = NULL;

    if (!list)
        return cur;

    while (ptr->next)
        ptr = ptr->next;
    ptr->next = cur;
    return list;
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

struct node *sumLists(struct node *list1, struct node *list2)
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
        ans = insertEnd(sum % 10, ans);
    }
    return ans;
}

int listToInt(struct node *list)
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

struct node *sumListInts(struct node *list1, struct node *list2)
{
    struct node *ans = NULL;
    int a, b, i;
    a = listToInt(list1);
    b = listToInt(list2);
    a += b;
    // printf("sum = %d\n", a);
    while (a)
    {
        i = a % 10;
        ans = insertStart(i, ans);
        a /= 10;
    }
    return ans;
}

void main()
{
    struct node *list1 = NULL, *list2 = NULL, *listOld = NULL, *listNew = NULL;

    list1 = insertStart(1, list1);
    list1 = insertStart(7, list1);
    list1 = insertStart(6, list1);
    list2 = insertStart(8, list2);
    list2 = insertStart(0, list2);
    list2 = insertStart(9, list2);

    printStart("a", list1);
    printStart("b", list2);
    listOld = sumListInts(list1, list2);
    printStart("a + b", listOld);

    printf("\n\na = ");
    printEnd(list1);
    printf("\nb = ");
    printEnd(list2);
    listNew = sumLists(list1, list2);
    printf("\na + b = ");
    printEnd(listNew);
}