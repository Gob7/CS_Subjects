// Element appearing >= half (n/2)
#include <bits/stdc++.h>
using namespace std;

void elementAppearMoreThanHalf(int *arr, int length)
{
    int i, key = -1, occur = 0, freq = 0;
    for (i = 0; i < length; i++)
    {
        if (!occur)
        {
            key = arr[i];
            occur++;
        }
        else if (key == arr[i])
            occur++;
        else
            occur--;
    }
    for (i = 0; i < length; i++)
        if (key == arr[i])
            freq++;

    if (freq > (length - 1) / 2)
        cout << '\n'
             << key << " present " << freq << " times in array, which is greater or equal to half.\n";
    else
        cout << "\nNo element is present more than half times.\n";
}
