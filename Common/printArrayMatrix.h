#include <bits/stdc++.h>
using namespace std;

template <typename T>
void arrPrint(const T *arr, unsigned int start, unsigned int end)
{
    for (unsigned int i = start; i < end; i++)
        cout << "(" << arr[i] << ") -> ";
    cout << "NULL" << endl;
}

template <typename T>
void arrPrint(const T *arr1, const T *arr2, const string &msg1, const string &msg2,
              unsigned int start, unsigned int end)
{
    cout << endl
         << "Index" << '\t' << msg1 << '\t' << msg2
         << endl;
    for (unsigned int i = start; i < end; i++)
        cout << i << '\t' << arr1[i] << '\t' << arr2[i] << endl;
}

template <typename T>
void arrPrint(const T *startTime, const T *finishTime, const T *weight, const T *criticalPoint,
              unsigned int start, unsigned int end)
{
    cout << "\nIndex\tStart\tFinish\tWeight\tCritical\n";
    for (unsigned int i = start; i < end; i++)
        cout << i << '\t' << startTime[i] << '\t' << finishTime[i]
             << '\t' << weight[i] << '\t' << criticalPoint[i + 1] - 1 << endl;
}

template <typename T>
void matrixPrint(T *arr, unsigned int row, unsigned int col,
                 string str1 = "", string str2 = "")
{
    unsigned int i, j, k = (col + 1) * 8 + 1;
    // cout << "arr[" << i << "][" << j << "] = " << endl;

    cout << "\t";
    for (i = 0; i < str2.size(); i++)
        cout << "\t" << str2[i];
    cout << endl;
    for (i = 0; i < k; i++)
        cout << "-";
    cout << endl;

    for (i = 0; i < row; i++)
    {
        if (str1.size() && i > 0)
            cout << str1[i - 1] << "  ";
        cout << "|\t";
        for (j = 0; j < col; j++)
            cout << arr[i * col + j] << "\t";
        cout << "|\n";
    }
    for (i = 0; i < k; i++)
        cout << "-";
    cout << "\n\n";
}
