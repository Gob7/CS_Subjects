#include <bits/stdc++.h>
using namespace std;

#include "../../Common/printArrayMatrix.h"
#include "appearHalfArray.h"
#include "longestSubarray.h"
#include "maxAndMin.h"

int main()
{
    int result[2],
        arr[] = {1, 1, 1, 2, 2, 1, 1};
    // arr[] = {5, 8, -43, 100, 3, -9, 0, 29, 9, 1, -5, -7, -85, 2};

    int length = sizeof(arr) / sizeof(int),
        target = 4;

    cout << "Array :";
    arrPrint(arr, 0, length);

    elementAppearMoreThanHalf(arr, length);

    cout << "\nLength of longest contiguous subarray whose sum " << target << " is "
         << longestContiguousSubarray(arr, length, target) << endl;

    maxMinLoop(arr, length, result);
    printMaxMin(result);
    maxMinDC(arr, 0, length - 1, result);
    printMaxMin(result);

    return 0;
}