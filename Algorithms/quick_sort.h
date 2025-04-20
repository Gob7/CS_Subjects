#include <bits/stdc++.h>
using namespace std;
int divide(int *arr, int low, int high){
    int pivot = arr[low], i = low+1, j = high;
    while (i<=j){
        while (arr[i]<=pivot && i<=high)
            i++;
        while (arr[j]>pivot)
            j--;

        if (i<j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}
void quick(int *arr, int start, int end){
    // arr[end] = INT_MAX;
    if (start<end){
        int key = divide(arr, start, end-1);
        quick(arr, start, key);
        quick(arr, key+1, end);
    }
}