#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int *arr, const int start, const int end)
{
    for (int i = start + 1; i < end; i++)
        for (int j = start; j < start + end - i; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}