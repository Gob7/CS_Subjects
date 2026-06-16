#include <bits/stdc++.h>
using namespace std;

// Binary Knapsack (Dynamic Programming)
int binaryKnapsack(const int *weight, const int *profit, const int length, int capacity)
{
    int i, j, fraction[length],
        result[length + 1][capacity + 1];

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
    fill(fraction, fraction + length, 0);
    j = capacity;

    for (i = length; i > 0; i--)
    {
        if (result[i][j] != result[i - 1][j])
        {
            fraction[i - 1] = 1;
            j -= weight[i - 1];
        }
    }

    cout << "\nWeight\t\t: ";
    arrPrint(weight, 0, length);
    cout << "Fraction\t: ";
    arrPrint(fraction, 0, length);
    cout << "Maximum Profit\t= " << result[length][capacity] << endl;

    return result[length][capacity];
}

// Wannabe Binary Knapsack
float wannabeBK(float *weight, float *profit, int length, float capacity)
{
    float fraction[length];
    int i;

    if (accumulate(weight, weight + length, 0) <= capacity)
    {
        fill(fraction, fraction + length, 1);
        return accumulate(profit, profit + length, 0);
    }

    float m1, m2, m3, m = capacity;
    float ratio[length], f1[length], f2[length];
    m1 = m2 = m3 = 0;

    // Greedy ratio
    for (i = 0; i < length; i++)
        ratio[i] = profit[i] / weight[i];
    descending_order(ratio, 0, length, 2, weight, profit);
    i = 0;
    while (capacity > 0 && i < length)
    {
        f1[i] = capacity < weight[i] ? 0 : 1;
        if (f1[i])
        {
            capacity -= weight[i];
            m1 += profit[i];
        }
        i++;
    }
    fill(f1 + i, f1 + length, 0);

    // Greedy weight
    ascending_order(weight, 0, length, 1, profit);
    capacity = m;
    i = 0;
    while (capacity > 0 && i < length)
    {
        f2[i] = capacity < weight[i] ? 0 : 1;
        if (f2[i])
        {
            capacity -= weight[i];
            m2 += profit[i];
        }
        i++;
    }
    fill(f2 + i, f2 + length, 0);

    // Greedy profit
    descending_order(profit, 0, length, 1, weight);
    capacity = m;
    i = 0;
    while (capacity > 0 && i < length)
    {
        fraction[i] = capacity < weight[i] ? 0 : 1;
        if (fraction[i])
        {
            capacity -= weight[i];
            m3 += profit[i];
        }
        i++;
    }
    fill(fraction + i, fraction + length, 0);

    if (m1 > m2 && m1 > m3)
    {
        descending_order(ratio, 0, length, 2, weight, profit);
        copy(f1, f1 + length, fraction);
        return m1;
    }
    if (m2 > m3)
    {
        ascending_order(weight, 0, length, 1, profit);
        copy(f2, f2 + length, fraction);
        return m2;
    }
    return m3;
}