#include <stdio.h>

typedef struct
{
    enum
    {
        INT,
        FLOAT
    } type;
    union
    {
        struct
        {
            int a, b, c;
        } i;
        struct
        {
            float a, b, c;
        } f;
    } data;
} NumberPair;

void add(NumberPair np)
{
    if (np.type == INT)
    {
        np.data.i.c = np.data.i.a + np.data.i.b;
        printf("Sum = %d\n", np.data.i.c);
    }
    else if (np.type == FLOAT)
    {
        np.data.f.c = np.data.f.a + np.data.f.b;
        printf("Sum = %.2f\n", np.data.f.c);
    }
    else
    {
        printf("Unknown type\n");
    }
}

int main()
{
    NumberPair n1 = {INT, .data.i = {3, 4}};
    NumberPair n2 = {FLOAT, .data.f = {3.2f, 4.6f}};

    add(n1);
    add(n2);

    return 0;
}