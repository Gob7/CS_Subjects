#include <bits/stdc++.h>
using namespace std;

// Max Heap
void heapify(int *arr, int start, int end, int index)
{
    int large = index;
    int left = (index - start) * 2 + 1 + start;
    int right = (index - start) * 2 + 2 + start;

    if (left < end && arr[left] > arr[large])
        large = left;
    if (right < end && arr[right] > arr[large])
        large = right;
    if (large != index)
    {
        swap(arr[index], arr[large]);
        heapify(arr, start, end, large);
    }
}

void heap(int *arr, int start, int end)
{
    int i, x = start + (end - start) / 2 - 1;
    // Build Heap
    for (i = x; i >= start; i--)
        heapify(arr, start, end, i);

    // Heap Sort
    for (i = end - 1; i >= start; i--)
    {
        swap(arr[start], arr[i]);
        heapify(arr, start, i, start);
    }
}