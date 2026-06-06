// Bubble sort with multiple arrays
#include <bits/stdc++.h>
using namespace std;

template <typename T>
void ascending_order(T *arr, int start, int end, int n, ...)
{
    va_list args;
    for (int i = start + 1; i < end; i++)
    {
        for (int j = start; j < start + end - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);

                va_start(args, n);
                for (int k = 0; k < n; k++)
                {
                    int *ptr = va_arg(args, int *);
                    swap(ptr[j], ptr[j + 1]);
                }
                va_end(args);
            }
        }
    }
}

template <typename T>
void descending_order(T *arr, int start, int end, int n, ...)
{
    va_list args;
    for (int i = start + 1; i < end; i++)
    {
        for (int j = start; j < start + end - i; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);

                va_start(args, n);
                for (int k = 0; k < n; k++)
                {
                    int *ptr = va_arg(args, int *);
                    swap(ptr[j], ptr[j + 1]);
                }
                va_end(args);
            }
        }
    }
}