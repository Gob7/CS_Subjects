#include <bits/stdc++.h>
using namespace std;

#include "../printing.h"
#include "BinarySearch.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "BottomUpMergeSort.h"
#include "QuickSort.h"
#include "HeapSort.h"
#include "RadixSort.h"

int main()
{
    int n, i;
    /*
    cout << "Enter length of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter array: ";
    for (i = 0; i < n; i++)
        cin >> arr[i];
    */

    // int arr[] = {5, 2, 9, 3, 0, 7, 6, -5, -8, -1};
    int arr[] = {15, -21, 456, -0, 2, 7, 93, -1000, 214, -965, 73, 20, 500};
    n = sizeof(arr) / sizeof(int);

    cout << "\nArray:\t\t";
    arrPrint(arr, 0, n);

    // bubbleSort(arr, 0, n);
    // selectionSort(arr, 0, n);
    // insertionSort(arr, 0, n);
    // mergeSort(arr, 0, n);
    // bottomUpMergeSort(arr, 0, n);
    // quickSort(arr, 0, n);
    // heapSort(arr, 0, n);
    radixSort(arr, 0, n);

    cout << "\nSorted array:\t";
    arrPrint(arr, 0, n);

    /*
    int key, index;
    cout << "Element to search: ";
    cin >> key;
    index = binarySearch(arr, 0, n - 1, key);
    if (index != -1)
        cout << "Key at index " << index + 1 << endl;
    */

    return 0;
}