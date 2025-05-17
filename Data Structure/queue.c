// Circular Queue using array
#include <stdio.h>
#define limit 7
int head = -1, tail = -1;
int queue[limit];

int isEmpty()
{
    if (head == -1)
        return 1;
    return 0;
}
int isFull()
{
    if (head == (tail + 1) % limit)
        return 1;
    return 0;
}

void enQueue(int x)
{
    if (isFull())
    {
        printf("\nQueue Overflow.\n");
        return;
    }
    if (head == -1)
        head = 0;
    tail = (tail + 1) % limit;

    queue[tail] = x;
    printf("%d is inserted.\n", queue[tail]);
}

void deQueue()
{
    if (isEmpty())
    {
        printf("\nQueue Underflow.\n");
        return;
    }
    printf("%d is deleted.\n", queue[head]);

    if (head == tail)
        head = tail = -1;
    else
        head = (head + 1) % limit;
}

void peek()
{
    if (isEmpty())
    {
        printf("\nQueue Underflow.\n");
        return;
    }
    printf("%d is peeked.\n", queue[head]);
}

void show()
{
    if (isEmpty())
    {
        printf("\nQueue Underflow.\n");
        return;
    }
    printf("\nQueue contains:\n");
    int i = head;

    do
    {
        printf("%d -> ", queue[i]);
        i = (i + 1) % limit;
    } while (i != (tail + 1) % limit);
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
    enQueue(9);
    enQueue(7);
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