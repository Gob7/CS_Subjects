#include <bits/stdc++.h>
using namespace std;

void mergeAlgo(int *arr, const int low, const int mid, const int high)
{
    int i, j, k,
        n1 = mid - low + 1,
        n2 = high - mid;
    int a1[n1], a2[n2];

    for (i = 0; i < n1; i++)
        a1[i] = arr[low + i];
    for (j = 0; j < n2; j++)
        a2[j] = arr[mid + 1 + j];

    i = j = 0;
    k = low;
    while (i < n1 && j < n2)
    {
        if (a1[i] > a2[j])
            arr[k++] = a2[j++];
        else
            arr[k++] = a1[i++];
    }

    while (i < n1)
        arr[k++] = a1[i++];
    while (j < n2)
        arr[k++] = a2[j++];
}

void mergeSort(int *arr, const int start, const int end)
{
    if (start < end - 1)
    {
        int mid = (start + end - 1) / 2;
        mergeSort(arr, start, mid + 1);
        mergeSort(arr, mid + 1, end);
        mergeAlgo(arr, start, mid, end - 1);
    }
}