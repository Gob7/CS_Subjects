// Fibonacci Series (Indian Series)
#include <bits/stdc++.h>
using namespace std;

// Brute Force Method
// T(n) = O(2^n)
// S(n) = O(1)
int fibonacciBruteForce(int num)
{
    if (num <= 1)
        return num;
    return fibonacciBruteForce(num - 1) + fibonacciBruteForce(num - 2);
}

// Top-Down Method
// T(n) = O(n)
// S(n) = O(n + n) (recursion stack + memoization)
int fibonacciTopDown(int num)
{
    int i = memoFib.size();
    if (num >= i)
        for (; i <= num; i++)
            memoFib.push_back(-1);

    if (memoFib[num] == -1)
    {
        if (num <= 1)
            memoFib[num] = num;
        else
            memoFib[num] = fibonacciTopDown(num - 1) + fibonacciTopDown(num - 2);
    }
    return memoFib[num];
}

// Bottom-Up Method (Efficient)
// T(n) = O(n)
// S(n) = O(n) (tabulation; no recursion)
int fibonacciBottomUp(int num)
{
    int i = tableFib.size();
    if (num >= i)
    {
        for (; i <= num; i++)
        {
            if (i <= 1)
                tableFib.push_back(i);
            else
                tableFib.push_back(tableFib[i - 1] + tableFib[i - 2]);
        }
    }
    return tableFib[num];
}