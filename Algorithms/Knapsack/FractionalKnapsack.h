#include <bits/stdc++.h>
using namespace std;

// Fractional Knapsack (Greedy Approach)
void fractionalKnapsack(const float *weight,
                        const float *profit,
                        const int length,
                        const float capacity)
{
    int i;
    float maxProfit = 0.0,
          newCapacity = capacity,
          newWeight[length],
          newProfit[length],
          fraction[length],
          ratio[length];

    copy(weight, weight + length, newWeight);
    copy(profit, profit + length, newProfit);
    for (i = 0; i < length; i++)
        ratio[i] = profit[i] / weight[i];

    if (accumulate(weight, weight + length, 0) <= capacity)
    {
        maxProfit = accumulate(profit, profit + length, 0);
        fill(fraction, fraction + length, 1);
    }
    else
    {
        descending_order(ratio, 0, length, 2, newWeight, newProfit);
        i = 0;
        while (newCapacity > 0)
        {
            fraction[i] = newCapacity / newWeight[i] > 1 ? 1 : newCapacity / newWeight[i];
            newCapacity -= fraction[i] * newWeight[i];
            maxProfit += fraction[i] * newProfit[i];
            i++;
        }
        fill(fraction + i, fraction + length, 0);
    }

    cout << "\nWeight\t\t: ";
    arrPrint(newWeight, 0, length);
    cout << "Fraction\t: ";
    arrPrint(fraction, 0, length);
    cout << "Maximum Profit\t= " << maxProfit << endl;
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