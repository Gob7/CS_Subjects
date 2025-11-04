#include <bits/stdc++.h>
using namespace std;

void selectionSort(int *arr, const int start, const int end)
{
    int i, j, key;
    for (i = start; i < end - 1; i++)
    {
        key = i;
        for (j = i + 1; j < end; j++)
        {
            if (arr[j] < arr[key])
                key = j;
        }
        swap(arr[i], arr[key]);
    }
}