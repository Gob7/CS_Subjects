// Binary Search
#include <bits/stdc++.h>
using namespace std;

int binarySearch(int *arr, int start, int end, int key)
{
    int mid = (start + end) / 2;
    // cout<<"\t\t"<<start<<" , "<<mid<<" , "<<end<<endl;
    if (start > end || start < 0 || end < 0)
        return -1;
    else if (arr[mid] == key)
        return mid;
    else if (arr[mid] < key)
        return binarySearch(arr, mid + 1, end, key);
    else
        return binarySearch(arr, start, mid - 1, key);
}