#include <bits/stdc++.h>
using namespace std;

void allPairShortestPath(int input[][nodes], int allPair[][nodes])
{
    int i, j, k, temp[nodes][nodes];
    copyGraph(input, temp);

    for (k = 0; k < nodes; k++)
    {
        for (i = 0; i < nodes; i++)
        {
            for (j = 0; j < nodes; j++)
            {
                if (temp[i][k] == INT_MAX || temp[k][j] == INT_MAX)
                    allPair[i][j] = temp[i][j];
                else
                    allPair[i][j] = min(temp[i][j], temp[i][k] + temp[k][j]);
            }
        }
        // graphPrint(d);
        copyGraph(allPair, temp);
    }
}