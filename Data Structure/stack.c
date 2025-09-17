// Stack using array
#include <stdio.h>
#include <limits.h>

#define limit 7
int top = -1;
int stack[limit];

int isEmpty()
{
    if (top == -1)
        return 1;
    return 0;
}
int isFull()
{
    if (top == limit - 1)
        return 1;
    return 0;
}

void push(int key)
{
    if (isFull())
    {
        printf("\nStack Overflow.\n");
        return;
    }
    stack[++top] = key;
    printf("%d is pushed.\n", stack[top]);
}

int pop()
{
    if (isEmpty())
    {
        printf("\nStack Underflow.\n");
        return INT_MIN;
    }
    printf("%d is popped.\n", stack[top]);
    return stack[top--];
}

void peek()
{
    if (isEmpty())
    {
        printf("\nStack Underflow.\n");
        return;
    }
    printf("%d is peeked.\n", stack[top]);
}

void show()
{
    if (isEmpty())
    {
        printf("\nStack Underflow.\n");
        return;
    }
    printf("\nStack contains:\nTOP -> ");
    for (int i = top; i > -1; i--)
        printf("%d -> ", stack[i]);
    printf("NULL\n\n");
}

void main()
{
    int key;
    key = pop();
    key = pop();
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

    key = pop();
    key = pop();
    peek();
    key = pop();
    key = pop();
    peek();
    push(9);
    push(7);
    show();
}