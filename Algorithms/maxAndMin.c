// Find maximum and minimum element in an array
#include <stdio.h>

// Using loop
void max_min_loop(int *arr, int n){
    if (n<1)
        return;
    int max, min, i;
    max = min = arr[0];
    for (i=1; i<n; i++){
        if (arr[i] < min)
            min = arr[i];
        else if (arr[i] > max)
            max = arr[i];
    }
    printf("\nUsing LOOP\n");
    printf("Minimum value\t= %d\n", min);
    printf("Maximum value\t= %d\n", max);
}

// Using Divide & Conquer
void max_min_dc(int *arr, int start, int end, int *result){
    if (start<0 || end<0)
        return;
    if (start == end)
        result[0] = result[1] = arr[start];
    else if (start == end-1){
        result[0] = arr[start]<arr[end] ? arr[start] : arr[end];
        result[1] = arr[start]>arr[end] ? arr[start] : arr[end];
    }
    else{
        int res1[2], res2[2], mid;
        mid = (start+end)/2;
        max_min_dc(arr, start, mid, res1);
        max_min_dc(arr, mid+1, end, res2);
        result[0] = res1[0]<res2[0] ? res1[0] : res2[0];
        result[1] = res1[1]>res2[1] ? res1[1] : res2[1];
    }
}

void main(){
    int arr[] = {5,8,-43,100,3,-9,0,29,9,1,-5,-7,-85,2}, result[2];
    int n = sizeof(arr)/sizeof(int);
    // printf("%d", n);
    max_min_loop(arr, n);
    max_min_dc(arr, 0, n-1, result);
    printf("\nUsing D&C\n");
    printf("Minimum value\t= %d\n", result[0]);
    printf("Maximum value\t= %d\n", result[1]);
}