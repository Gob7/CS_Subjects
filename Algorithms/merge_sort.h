// Merge Sort
#include <bits/stdc++.h>
using namespace std;
void merging(int *arr, int low, int mid, int high){
    int n1 = mid-low+1, n2 = high-mid, i, j, k;
    int a1[n1], a2[n2];
    for (i=0; i<n1; i++)
        a1[i] = arr[low+i];
    for (j=0; j<n2; j++)
        a2[j] = arr[mid+1+j];
    
    i=0; j=0; k=low;
    while (i<n1 && j<n2){
        if (a1[i]>a2[j])
            arr[k++] = a2[j++];
        else 
            arr[k++] = a1[i++];
    }
    while (i<n1)
        arr[k++] = a1[i++];
    while (j<n2)
        arr[k++] = a2[j++];
}
void merge(int *arr, int start, int end){
    if (start < end-1){
        int mid = (start+end-1) / 2;
        merge(arr, start, mid+1);
        merge(arr, mid+1, end);
        merging(arr, start, mid, end-1);
    }
}