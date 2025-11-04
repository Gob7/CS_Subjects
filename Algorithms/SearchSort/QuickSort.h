#include <bits/stdc++.h>
using namespace std;

int quickDivide(int *arr, const int low, const int high)
{
    int pivot = arr[low], i = low + 1, j = high;
    while (i <= j)
    {
        while (i <= high && arr[i] <= pivot)
            i++;
        while (arr[j] > pivot)
            j--;

        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(int *arr, const int start, const int end)
{
    if (start < end)
    {
        int key = quickDivide(arr, start, end - 1);
        quickSort(arr, start, key);
        quickSort(arr, key + 1, end);
    }
}