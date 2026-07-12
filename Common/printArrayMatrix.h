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
void matrixPrint(const T *arr, unsigned int row, unsigned int col)
{
    unsigned int i, j, x;

    // top
    cout << "\n   ";
    x = 7;
    fill_n(ostream_iterator<char>(cout), x - 1, '_');
    for (i = 0; i < col; i++)
    {
        x = i > 9 ? 6 : 7;
        cout << i;
        fill_n(ostream_iterator<char>(cout), x, '_');
    }

    cout << "\n  |";
    for (i = 0; i <= col; i++)
        cout << "\t";
    cout << " |\n";

    // middle
    for (i = 0; i < row; i++)
    {
        if (i < 10)
            cout << i << " |\t";
        else
            cout << i << "|\t";

        for (j = 0; j < col; j++)
        {
            if (arr[i * col + j] == INT_MAX)
                cout << "-" << "\t";
            else
                cout << arr[i * col + j] << "\t";
        }
        cout << " |\n";
    }

    // bottom
    cout << "  |";
    fill_n(ostream_iterator<char>(cout), (col + 1) * 8 - 2, '_');
    cout << "|\n\n";
}

template <typename T>
void matrixPrint(const T *arr, unsigned int row, unsigned int col, string str1, string str2)
{
    unsigned int i, j, x;

    // top
    cout << "\n   ";
    x = 7;
    fill_n(ostream_iterator<char>(cout), x - 1, '_');
    for (i = 0; i < col; i++)
    {
        if (i)
            cout << str2[i - 1];
        else
            cout << '_';
        fill_n(ostream_iterator<char>(cout), x, '_');
    }

    cout << "\n  |";
    for (i = 0; i <= col; i++)
        cout << "\t";
    cout << " |\n";

    // middle
    for (i = 0; i < row; i++)
    {
        if (i)
            cout << str1[i - 1] << " |\t";
        else
            cout << "  |\t";

        for (j = 0; j < col; j++)
        {
            if (arr[i * col + j] == INT_MAX)
                cout << "-" << "\t";
            else
                cout << arr[i * col + j] << "\t";
        }
        cout << " |\n";
    }

    // bottom
    cout << "  |";
    fill_n(ostream_iterator<char>(cout), (col + 1) * 8 - 2, '_');
    cout << "|\n\n";
}