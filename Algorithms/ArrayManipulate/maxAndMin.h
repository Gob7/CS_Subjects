// Find maximum and minimum element in an array
#include <bits/stdc++.h>
using namespace std;

void printMaxMin(int *result)
{
    cout << "\nMin = " << result[0] << ";\tMax = " << result[1] << endl;
}

// Using loop
void maxMinLoop(const int *arr, const int n, int *result)
{
    if (n < 1)
        return;

    result[1] = result[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < result[0])
            result[0] = arr[i];
        else if (arr[i] > result[1])
            result[1] = arr[i];
    }
}

// Using Divide & Conquer
void maxMinDC(const int *arr, const int start, const int end, int *result)
{
    if (start < 0 || end < 0)
        return;
    if (start == end)
        result[0] = result[1] = arr[start];
    else if (start == end - 1)
    {
        result[0] = arr[start] < arr[end] ? arr[start] : arr[end];
        result[1] = arr[start] > arr[end] ? arr[start] : arr[end];
    }
    else
    {
        int res1[2], res2[2], mid;
        mid = (start + end) / 2;
        maxMinDC(arr, start, mid, res1);
        maxMinDC(arr, mid + 1, end, res2);
        result[0] = res1[0] < res2[0] ? res1[0] : res2[0];
        result[1] = res1[1] > res2[1] ? res1[1] : res2[1];
    }
}