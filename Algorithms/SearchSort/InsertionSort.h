#include <bits/stdc++.h>
using namespace std;

void insertionSort(int *arr, const int start, const int end)
{
    int i, j, key;
    for (i = start + 1; i < end; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j > start - 1 && arr[j] > key)
            arr[j + 1] = arr[j--];
        arr[++j] = key;
    }
}