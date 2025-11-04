// works for non-negative integers
#include <bits/stdc++.h>
using namespace std;

void radixSortAlgo(int *arr, const int start, const int end)
{
    int i, digit, bit,
        base = 10,
        maxBit = floor(log10(*max_element(arr + start, arr + end - 1))) + 1;
    node *cur, *ptr;

    for (bit = 1; bit <= maxBit; bit++)
    {
        node *bucket[base] = {nullptr};
        node *tail[base] = {nullptr};

        // Distribute into buckets
        for (i = start; i < end; i++)
        {
            cur = new node{arr[i], nullptr};
            digit = (arr[i] / (int)pow(base, bit - 1)) % base;
            ptr = bucket[digit];

            if (!ptr)
                bucket[digit] = tail[digit] = cur;
            else
            {
                tail[digit]->next = cur;
                tail[digit] = cur; // tail[digit]->next
            }
        }

        cout << "\nBuckets contain:\n";
        for (i = 0; i < base; i++)
        {
            cout << i << "\t: ";
            listPrint(bucket[i]);
        }

        // Collect from buckets
        i = start;
        for (digit = 0; digit < base; digit++)
        {
            ptr = bucket[digit];
            while (ptr)
            {
                arr[i++] = ptr->value;
                cur = ptr;
                ptr = ptr->next;
                delete cur;
            }
        }
    }
}

void radixSort(int *arr, const int start, const int end)
{
    int i, pos = 0, neg = 0,
           posArr[end - start], negArr[end - start];

    for (i = start; i < end; i++)
        arr[i] < 0 ? negArr[neg++] = abs(arr[i]) : posArr[pos++] = arr[i];

    radixSortAlgo(posArr, 0, pos);
    radixSortAlgo(negArr, 0, neg);

    reverse(negArr, negArr + neg);
    for (i = 0; i < neg; i++)
        negArr[i] = -negArr[i];

    merge(posArr, posArr + pos, negArr, negArr + neg, arr);
}