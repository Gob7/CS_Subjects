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
    int i = memo.size();
    if (num >= i)
        for (; i <= num; i++)
            memo.push_back(-1);

    if (memo[num] == -1)
    {
        if (num <= 1)
            memo[num] = num;
        else
            memo[num] = fibonacciTopDown(num - 1) + fibonacciTopDown(num - 2);
    }
    return memo[num];
}

// Bottom-Up Method (Efficient)
// T(n) = O(n)
// S(n) = O(n) (tabulation; no recursion)
int fibonacciBottomUp(int num)
{
    int i = table.size();
    if (num >= i)
    {
        for (; i <= num; i++)
        {
            if (i <= 1)
                table.push_back(i);
            else
                table.push_back(table[i - 1] + table[i - 2]);
        }
    }
    return table[num];
}