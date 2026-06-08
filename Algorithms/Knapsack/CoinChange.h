#include <bits/stdc++.h>
using namespace std;

// minimum number of coins to reach target
int minimumCoins(const int *coins, const int length, const int target)
{
    int i, j, result[target + 1];

    result[0] = 0;
    for (i = 1; i <= target; i++)
    {
        result[i] = INT_MAX;

        for (j = 0; j < length; j++)
            if (coins[j] <= i && result[i - coins[j]] != INT_MAX && result[i] > result[i - coins[j]] + 1)
                result[i] = result[i - coins[j]] + 1;
    }

    cout << "\nIntermediate: ";
    arrPrint(result, 0, target);
    return result[target];
}

// maximum number of ways to reach target
int waysToCoins(const int *coins, const int length, const int target)
{
    int i, j, result[target + 1] = {1};

    for (j = 0; j < length; j++)
        for (i = 1; i <= target; i++)
            if (coins[j] <= i)
                result[i] += result[i - coins[j]];

    cout << "\nIntermediate: ";
    arrPrint(result, 0, target);
    return result[target];
}