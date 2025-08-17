#include <bits/stdc++.h>
using namespace std;

// Add two linked lists and store sum in another linked list
// Assume each node contains a digit; 0 <= node value <= 9
struct node
{
    int data;
    struct node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

struct node *addNumber(struct node *a, struct node *b)
{
    int x, y, sum, car = 0;
    struct node *c = NULL, *tail = NULL, *ptr;
    while (a || b)
    {
        x = a ? a->data : 0;
        y = b ? b->data : 0;
        sum = x + y + car;
        ptr = new node(sum % 10);
        car = sum / 10;

        if (!c)
            c = ptr;
        else
            tail->next = ptr;
        tail = ptr;
        if (a)
            a = a->next;
        if (b)
            b = b->next;
    }
    if (car > 0)
    {
        ptr = new node(car);
        tail->next = ptr;
    }
    return c;
}

// Add two arrays of size n and store sum in another array of size n+1
// Assume each index contains a digit; 0 <= value <= 9
int *addNumber(int *a, int *b, int size)
{
    int *c = new int[size + 1], i = 0, car = 0, sum;
    for (; i < size; i++)
    {
        sum = a[i] + b[i] + car;
        c[i] = sum % 10;
        car = sum / 10;
    }
    c[size] = car;
    return c;
}

// Add two binary arrays of size n and store sum in another binary array of size n+1
// Assume each index contains a digit; 0 <= value <= 1
int *addBinaryNumber(int *a, int *b, int size)
{
    int *c = new int[size + 1], i = 0, car = 0, sum;
    for (; i < size; i++)
    {
        sum = a[i] + b[i] + car;
        c[i] = sum % 2;
        car = sum / 2;
    }
    c[size] = car;
    return c;
}

void printNumber(struct node *head)
{
    if (!head)
        return;
    printNumber(head->next);
    cout << head->data;
}

void printNumber(int *head, int size)
{
    for (int i = size - 1; i >= 0; i--)
        cout << head[i];
    cout << endl;
}

int main()
{
    struct node *a, *b, *c;
    // a = 916
    a = new node(6);
    a->next = new node(1);
    a->next->next = new node(9);
    // b = 87
    b = new node(7);
    b->next = new node(8);
    // c = a + b = 1003
    c = addNumber(a, b);
    // printing
    cout << "Linked List Addition:";
    cout << "\na\t=\t";
    printNumber(a);
    cout << "\nb\t=\t";
    printNumber(b);
    cout << "\nc\t=\t";
    printNumber(c);

    int size = 3;
    // p = 987
    int p[size] = {7, 8, 9};
    // q = 25
    int q[size] = {5, 2};
    // r = p + q = 1012
    int *r = addNumber(p, q, size);
    // printing
    cout << "\n\nArray Addition:\n";
    cout << "p\t=\t";
    printNumber(p, size);
    cout << "q\t=\t";
    printNumber(q, size);
    cout << "r\t=\t";
    printNumber(r, size + 1);
    // delete[] r;

    // x = 110 (6)
    int x[size] = {0, 1, 1};
    // y = 10 (2)
    int y[size] = {0, 1};
    // z = x + y = 1000 (8)
    int *z = addBinaryNumber(x, y, size);
    // printing
    cout << "\nBinary Array Addition:\n";
    cout << "x\t=\t";
    printNumber(x, size);
    cout << "y\t=\t";
    printNumber(y, size);
    cout << "z\t=\t";
    printNumber(z, size + 1);
    // delete[] z;

    return 0;
}