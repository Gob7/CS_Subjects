// Array contains all non negative integers and target >= 0
#include <bits/stdc++.h>
using namespace std;

int longestContiguousSubarray(int *arr, int length, int target)
{
    int i, sum, start, answer;
    sum = start = answer = i = 0;
    while (i < length)
    {
        if (arr[i] + sum <= target)
        {
            sum += arr[i];
            if (sum == target && answer < i - start + 1)
                answer = i - start + 1;
            i++;
        }
        else if (start < i)
        {
            sum -= arr[start];
            start++;
        }
        else
            i++;
    }
    return answer;
}

int main()
{
    int arr[] = {1, 1, 1, 2, 2, 1, 1};
    int target = 4;
    int length = sizeof(arr) / sizeof(int);
    cout << "Length of longest contiguous subarray whose sum is " << target << " is "
         << longestContiguousSubarray(arr, length, target) << endl;
    return 0;
}