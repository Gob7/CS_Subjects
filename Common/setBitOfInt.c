#include <stdio.h>
#include <math.h>
#include <limits.h>

int setBit(int number, int index)
{
    int size, indexNumber;
    size = sizeof(number) * 8;

    if (index >= size || index < 0)
        return 0;
    indexNumber = pow(2, index);
    return indexNumber | number;
}

void main()
{
    int number = 1, index, answer;
    // answer = pow(number, index);
    // printf("%d ^ %d = %d", number, index, answer);
    // printf("\n%d", INT_MIN);
    // printf("\n%d", (answer | 100));

    for (index = 30; index < 34; index++)
    {
        printf("\nnumber\t\t= %d\nto set bit\t= %d", number, index);
        answer = setBit(number, index);
        if (!answer)
            printf("\nInvalid index given.\n");
        else
            printf("\nSet number\t= %d\n", answer);
    }
}