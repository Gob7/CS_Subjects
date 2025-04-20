#include <bits/stdc++.h>
using namespace std;

void heapify(int *arr, int start, int end, int index){
    int lar = index;
    int left = (index-start)*2 + 1 + start;
    int right = (index-start)*2 + 2 + start;
    if (left < end && arr[left] > arr[lar]) 
        lar=left;
    if (right < end && arr[right] > arr[lar]) 
        lar=right;

    if (lar != index){
        swap(arr[index], arr[lar]);
        heapify(arr, start, end, lar);
    }
}

void heap(int *arr, int start, int end){
    int i, x = start + (end-start)/2 - 1;
    // Build Heap
    for(i = x; i >= start; i--) 
        heapify(arr, start, end, i);
    // Heap Sort
    for(i = end-1; i >= start; i--){
        swap(arr[start], arr[i]);
        heapify(arr, start, i, start);
    }
}