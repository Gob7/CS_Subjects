#include <bits/stdc++.h>
using namespace std;

// maximize profit
int rodCut(const int *cut, const int *price, const int length, const int target)
{
    int i, j, result[target + 1];

    result[0] = 0;
    for (i = 1; i <= target; i++)
    {
        result[i] = INT_MIN;

        for (j = 0; j < length; j++)
            if (cut[j] <= i && result[i - cut[j]] != INT_MIN && result[i] < price[j] + result[i - cut[j]])
                result[i] = price[j] + result[i - cut[j]];
    }

    cout << "\nIntermediate: ";
    arrPrint(result, 0, target);
    return result[target];
}