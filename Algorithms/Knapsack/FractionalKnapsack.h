#include <bits/stdc++.h>
using namespace std;

// Fractional Knapsack (Greedy Approach)
float fractionalKnapsack(const float *weight, const float *profit, const int length, float capacity)
{
    int i;
    float maxProfit = 0.0, newWeight[length], newProfit[length], fraction[length], ratio[length];

    copy(weight, weight + length, newWeight);
    copy(profit, profit + length, newProfit);
    for (i = 0; i < length; i++)
        ratio[i] = profit[i] / weight[i];
    descending_order(ratio, 0, length, 2, newWeight, newProfit);

    i = 0;
    while (capacity > 0)
    {
        fraction[i] = capacity / newWeight[i] > 1 ? 1 : capacity / newWeight[i];
        capacity -= fraction[i] * newWeight[i];
        maxProfit += fraction[i] * newProfit[i];
        i++;
    }
    fill(fraction + i, fraction + length, 0);

    cout << "\nWeight\t\t: ";
    arrPrint(newWeight, 0, length);
    cout << "Fraction\t: ";
    arrPrint(fraction, 0, length);
    cout << "Maximum Profit\t= " << maxProfit << endl;

    return maxProfit;
}