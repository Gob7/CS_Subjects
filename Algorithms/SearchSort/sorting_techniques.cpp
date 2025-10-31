#include <bits/stdc++.h>
using namespace std;

#include "../printing.h"
#include "binary_search.h"
#include "bubble_sort.h"
#include "selection_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "bup_mergesort.h"
#include "quick_sort.h"
#include "heap_sort.h"

int main()
{
    int n, i;

    // cout<<"Enter length of array: ";
    // cin>>n;
    // int arr[n];
    // cout<<"Enter array: ";
    // for (i=0;i<n;i++)
    //     cin>>arr[i];

    int arr[] = {5, 2, 9, 3, 0, 7, 6, -5, -8, -1};
    // int arr[] = {0,-1,-2,-3,-4,-5,-6,-7,-8,-9};
    n = sizeof(arr) / sizeof(int);

    cout << "\nArray:\t\t";
    arrPrint(arr, 0, n);

    bubble(arr, 0, n);
    // selection(arr, 0, n);
    // insertion(arr, 0, n);
    // merge(arr, 0, n);
    // bupMerge(arr, 0, n);
    // quick(arr, 0, n);
    // heap(arr, 0, n);

    cout << "\nSorted array:\t";
    arrPrint(arr, 0, n);

    // int key, index;
    // cout<<"Element to search: ";
    // cin>>key;
    // index = binarySearch(arr, 0, n-1, key);
    // if (index != -1)
    //     cout<<"Key at index "<<index+1<<endl;

    return 0;
}