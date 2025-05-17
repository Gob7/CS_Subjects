// Stack using array
#include <stdio.h>
#include <limits.h>

#define limit 7
int key = -1;
int stack[limit];

int isEmpty()
{
    if (key == -1)
        return 1;
    return 0;
}
int isFull()
{
    if (key == limit - 1)
        return 1;
    return 0;
}

void push(int x)
{
    if (isFull())
    {
        printf("\nStack Overflow.\n");
        return;
    }
    stack[++key] = x;
    printf("%d is pushed.\n", stack[key]);
}

int pop()
{
    if (isEmpty())
    {
        printf("\nStack Underflow.\n");
        return INT_MIN;
    }
    printf("%d is popped.\n", stack[key]);
    return stack[key--];
}

void peek()
{
    if (isEmpty())
    {
        printf("\nStack Underflow.\n");
        return;
    }
    printf("%d is peeked.\n", stack[key]);
}

void show()
{
    if (isEmpty())
    {
        printf("\nStack Underflow.\n");
        return;
    }
    printf("\nStack contains:\n");
    for (int i = key; i > -1; i--)
        printf("%d -> ", stack[i]);
    printf("NULL\n\n");
}

void main()
{
    int x;
    x = pop();
    x = pop();
    peek();
    show();

    push(5);
    push(8);
    push(3);
    push(4);
    push(0);
    push(5);
    push(2);
    push(9);
    push(7);
    show();

    x = pop();
    x = pop();
    peek();
    x = pop();
    x = pop();
    peek();
    push(9);
    push(7);
    show();
}