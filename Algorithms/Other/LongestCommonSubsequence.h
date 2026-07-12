#include <bits/stdc++.h>
using namespace std;

string longestCommonSubsequence(const string str1, const string str2)
{
    unsigned int n1 = str1.size(), n2 = str2.size(), i, j;
    int tableLCS[n1 + 1][n2 + 1];
    string str = "";

    for (i = 0; i <= n1; i++)
    {
        for (j = 0; j <= n2; j++)
        {
            if (i == 0 || j == 0)
                tableLCS[i][j] = 0;
            else if (str1[i - 1] == str2[j - 1])
                tableLCS[i][j] = tableLCS[i - 1][j - 1] + 1;
            else
                tableLCS[i][j] = max(tableLCS[i][j - 1], tableLCS[i - 1][j]);
        }
    }
    i = n1 - 1;
    j = n2 - 1;
    while (i < n1 && j < n2)
    {
        if (str1[i] == str2[j])
        {
            str = str1[i] + str;
            i--;
            j--;
        }
        else if (tableLCS[i + 1][j + 1] == tableLCS[i][j + 1])
            i--;
        else
            j--;
    }

    cout << "\nLongest Common Subsequence Table:";
    matrixPrint(tableLCS[0], n1 + 1, n2 + 1, str1, str2);
    return str;
}