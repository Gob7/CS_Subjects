#include <bits/stdc++.h>
using namespace std;

void printMCM(const unsigned int *S, const unsigned int i, const unsigned int j, const unsigned int n)
{
    if (i == j)
    {
        cout << " A" << i + 1;
        if (i != n - 1)
            cout << " * ";
    }
    else
    {
        cout << "(";
        printMCM(S, i, S[i * n + j], n);
        printMCM(S, S[i * n + j] + 1, j, n);
        cout << ")";
    }
}

unsigned int matrixChainMultiply(const unsigned int *P, const unsigned int n)
{
    unsigned int M[n][n], S[n][n], i, j, k, l, temp;
    for (i = 0; i < n; i++)
    {
        fill(M[i], M[i] + n, INT_MAX);
        fill(S[i], S[i] + n, INT_MAX);
        M[i][i] = 0;
        S[i][i] = 0;
    }
    for (l = 1; l < n; l++)
    {
        for (i = 0; i < n - l; i++)
        {
            j = i + l;
            for (k = i; k < j; k++)
            {
                temp = M[i][k] + M[k + 1][j] + P[i] * P[k + 1] * P[j + 1];
                if (temp < M[i][j])
                {
                    M[i][j] = temp;
                    S[i][j] = k;
                }
            }
        }
    }
    /*
    n = 4; M[0...3][0...3]; S[0...3][0...3];
    i,j ->  0, 1;
            1, 2;
            2, 3;
        ->  0, 2;
            1, 3;
        ->  0, 3;
    l   ->  1, 2, 3;
    */

    cout << "\nMatrix Chain Multiply Table: ";
    matrixPrint(M[0], n, n);
    cout << "Bracket Table: ";
    matrixPrint(S[0], n, n);
    cout << "Optimal bracket = ";
    printMCM(S[0], 0, n - 1, n);
    return M[0][n - 1];
}