// Bottom-Up Merge Sort
#include <bits/stdc++.h>
using namespace std;

void combine(int *arr, int low, int mid, int high)
{
    int n = high - low + 1, i = 0, j = low, k = mid + 1;
    int a[n];
    while (j <= mid && k <= high)
    {
        if (arr[j] < arr[k])
            a[i++] = arr[j++];
        else
            a[i++] = arr[k++];
    }
    while (j <= mid)
        a[i++] = arr[j++];
    while (k <= high)
        a[i++] = arr[k++];

    for (i = 0; i < n; i++)
        arr[low + i] = a[i];
}

void bupMerge(int *arr, int start, int end)
{
    int item = 1, n = end - start, low, mid, high;
    while (item <= n)
    {
        low = start;
        while (low < end)
        {
            mid = low + item - 1;
            mid = mid < end ? mid : end - 1;
            high = low + 2 * item - 1;
            high = high < end ? high : end - 1;

            combine(arr, low, mid, high);
            low += 2 * item;
        }
        item *= 2;
    }
}