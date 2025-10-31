#include <bits/stdc++.h>
using namespace std;

// Binary Knapsack (Dynamic Programming)
void binaryKnapsack(const int *weight,
                    const int *profit,
                    const int length,
                    const int capacity)
{
    int i, j, curProfit, *ptr,
        newWeight[length],
        newProfit[length],
        fraction[length],
        result[length + 1][capacity + 1];

    copy(weight, weight + length, newWeight);
    copy(profit, profit + length, newProfit);
    ascending_order(newWeight, 0, length, 1, newProfit);

    for (i = 0; i <= length; i++)
    {
        for (j = 0; j <= capacity; j++)
        {
            if (i == 0 || j == 0)
                result[i][j] = 0;
            else if (newWeight[i - 1] > j)
                result[i][j] = result[i - 1][j];
            else
                result[i][j] = max(result[i - 1][j], newProfit[i - 1] + result[i - 1][j - newWeight[i - 1]]);
        }
    }

    matrixPrint(result[0], length + 1, capacity + 1);
    curProfit = result[length][capacity];
    for (i = length - 1; i >= 0; i--)
    {
        cout << curProfit << ", ";
        if (!curProfit)
        {
            fraction[i] = 0;
            continue;
        }
        ptr = find(result[i] + 1, result[i] + capacity + 1, curProfit);
        j = (ptr == result[i] + capacity + 1);
        fraction[i] = j ? 1 : 0;
        curProfit = j ? curProfit - newProfit[i] : curProfit;
    }

    cout << "\nWeight\t\t: ";
    arrPrint(newWeight, 0, length);
    cout << "Fraction\t: ";
    arrPrint(fraction, 0, length);
    cout << "Maximum Profit\t= " << result[length][capacity] << endl;
}