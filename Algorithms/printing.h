#include <bits/stdc++.h>
using namespace std;

struct node
{
    int value;
    struct node *next;
};

template <typename T>
void arrPrint(const T *arr, int start, int end)
{
    for (int i = start; i < end; i++)
        cout << "(" << arr[i] << ") -> ";
    cout << "NULL" << endl;
}

template <typename T>
void arrPrint(const T *arr1, const T *arr2, const string &msg1, const string &msg2, int start, int end)
{
    cout << endl
         << "Index" << '\t' << msg1 << '\t' << msg2
         << endl;
    for (int i = start; i < end; i++)
        cout << i << '\t' << arr1[i] << '\t' << arr2[i] << endl;
}

template <typename T>
void arrPrint(const T *startTime, const T *finishTime, const T *weight, const T *criticalPoint, int start, int end)
{
    cout << "\nIndex\tStart\tFinish\tWeight\tCritical\n";
    for (int i = start; i < end; i++)
        cout << i << '\t' << startTime[i] << '\t' << finishTime[i]
             << '\t' << weight[i] << '\t' << criticalPoint[i + 1] - 1 << endl;
}

void vecPrint(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << "(" << vec[i] << ") -> ";
    cout << "NULL" << endl;
}

template <typename T>
void matrixPrint(T *a, int row, int col)
{
    int i, j, k = (col + 1) * 8 + 1;
    // cout<<"a["<<i<<"]["<<j<<"] = "<<endl;

    for (i = 0; i < k; i++)
        cout << "-";
    cout << endl;

    for (i = 0; i < row; i++)
    {
        cout << "|\t";
        for (j = 0; j < col; j++)
            cout << a[i * col + j] << "\t";
        cout << "|\n";
    }
    for (i = 0; i < k; i++)
        cout << "-";
    cout << "\n\n";
}

void numPrint(vector<int> vec)
{
    for (int i = vec.size() - 1; i >= 0; i--)
        cout << vec[i];
}

void listPrint(node *ptr)
{
    while (ptr)
    {
        cout << ptr->value << "\t-> ";
        ptr = ptr->next;
    }
    cout << "NULL\n";
}