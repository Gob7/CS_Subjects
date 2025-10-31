#include <bits/stdc++.h>
using namespace std;

// Binary Knapsack (Dynamic Programming)
int binaryKnapsack(int *weight, int *profit, int length, int capacity, int *fraction)
{
    int i, j, k, result[length + 1][capacity + 1];
    int *ptr;
    ascending_order(weight, 0, length, 1, profit);

    for (i = 0; i <= length; i++)
    {
        for (j = 0; j <= capacity; j++)
        {
            if (i == 0 || j == 0)
                result[i][j] = 0;
            else if (weight[i - 1] > j)
                result[i][j] = result[i - 1][j];
            else
                result[i][j] = max(result[i - 1][j], profit[i - 1] + result[i - 1][j - weight[i - 1]]);
        }
    }

    matrixPrint(result[0], length + 1, capacity + 1);
    k = result[length][capacity];
    i = length - 1;
    for (; i >= 0; i--)
    {
        cout << k << ",";
        if (!k)
        {
            fraction[i] = 0;
            continue;
        }
        ptr = find(result[i] + 1, result[i] + capacity + 1, k);
        j = ptr == result[i] + capacity + 1;
        fraction[i] = j ? 1 : 0;
        k = j ? k - profit[i] : k;
    }
    return result[length][capacity];
}