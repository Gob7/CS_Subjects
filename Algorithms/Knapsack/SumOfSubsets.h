#include <bits/stdc++.h>
using namespace std;

bool sumOfSubsets(const int *sets, const int length, const int target)
{
    int i, j;
    bool result[length + 1][target + 1];

    for (i = 0; i <= length; i++)
    {
        for (j = 0; j <= target; j++)
        {
            if (j == 0)
                result[i][j] = true;
            else if (i == 0) // j > 0
                result[i][j] = false;
            else if (sets[i - 1] > j)
                result[i][j] = result[i - 1][j];
            else
                result[i][j] = result[i - 1][j] || result[i - 1][j - sets[i - 1]];
        }
    }

    cout << "\nIntermediate:\n";
    for (i = 1; i <= length; i++)
        arrPrint(result[i], 1, target + 1);
    return result[length][target];
}

bool sumOfSubsetsBacktracking(const int *sets, const int length, const int target)
{
}