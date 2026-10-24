#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &t, int l, int m, int h, long long int *ptr)
{
    int n1 = m - l + 1, n2 = h - m, i, j, k;
    vector<int> a1(n1), a2(n2);

    k = 0;
    for (i = l; i <= m; i++)
        a1[k++] = t[i];

    k = 0;
    for (j = m + 1; j <= h; j++)
        a2[k++] = t[j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (a1[i] <= a2[j])
            t[k++] = a1[i++];
        else
        {
            t[k++] = a2[j++];
            *ptr += n1 - i;
        }
    }
    while (i < n1)
        t[k++] = a1[i++];
    while (j < n2)
        t[k++] = a2[j++];
}
void mergeSort(vector<int> &t, int l, int h, long long int *ptr)
{
    if (l >= h)
        return;

    int m = (l + h) / 2;
    mergeSort(t, l, m, ptr);
    mergeSort(t, m + 1, h, ptr);
    merge(t, l, m, h, ptr);
}

void numberOfInversions(vector<int> nums)
{
    vector<int> t = nums;
    long long int inv = 0;
    mergeSort(t, 0, t.size() - 1, &inv);

    cout << "\nNumber of inversions in the array are " << inv << endl;
}