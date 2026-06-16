#include <bits/stdc++.h>
using namespace std;

// Min Heap
void minHeapify(int *arr, const int start, const int end, const int index)
{
    int small = index;
    int left = (index - start) * 2 + 1 + start;
    int right = left + 1;

    if (left < end && arr[left] < arr[small])
        small = left;
    if (right < end && arr[right] < arr[small])
        small = right;
    if (small != index)
    {
        swap(arr[index], arr[small]);
        minHeapify(arr, start, end, small);
    }
}

// Max Heap
void maxHeapify(int *arr, const int start, const int end, const int index)
{
    int large = index;
    int left = (index - start) * 2 + 1 + start;
    int right = left + 1;

    if (left < end && arr[left] > arr[large])
        large = left;
    if (right < end && arr[right] > arr[large])
        large = right;
    if (large != index)
    {
        swap(arr[index], arr[large]);
        maxHeapify(arr, start, end, large);
    }
}

void buildMinHeap(int *arr, const int start, const int end)
{
    for (int i = start + (end - start) / 2 - 1; i >= start; i--)
        minHeapify(arr, start, end, i);
}
void buildMaxHeap(int *arr, const int start, const int end)
{
    for (int i = start + (end - start) / 2 - 1; i >= start; i--)
        maxHeapify(arr, start, end, i);
}

void heapSortDesc(int *arr, const int start, const int end)
{
    buildMinHeap(arr, start, end);
    for (int i = end - 1; i >= start; i--)
    {
        swap(arr[start], arr[i]);
        minHeapify(arr, start, i, start);
    }
}
void heapSort(int *arr, const int start, const int end)
{
    buildMaxHeap(arr, start, end);
    for (int i = end - 1; i >= start; i--)
    {
        swap(arr[start], arr[i]);
        maxHeapify(arr, start, i, start);
    }
}