// Fibonacci Series (Indian Series)
#include <bits/stdc++.h>
#include "../Algorithms/printing.h"
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

// Top-Down Memoized Method
// T(n) = O(n)
// S(n) = O(n + n) (recursion stack + array)
struct array
{
    vector<int> vec;
    int comp;
} fib;

int fibonacciTopDown(int num)
{
    int i = fib.vec.size();
    if (num >= i)
        for (; i <= num; i++)
            fib.vec.push_back(-1);

    if (num > fib.comp)
    {
        if (num <= 1)
            fib.vec[num] = num;
        else
            fib.vec[num] = fibonacciTopDown(num - 1) + fibonacciTopDown(num - 2);
    }
    return fib.vec[num];
}

// Bottom-UP Memoized Method (Efficient)
// T(n) = O(n)
// S(n) = O(n) (array; no recursion)
vector<int> arr;

int fibonacciBottomUp(int num)
{
    int i = arr.size();
    if (num >= i)
    {
        for (; i <= num; i++)
        {
            if (i <= 1)
                arr.push_back(i);
            else
                arr.push_back(arr[i - 1] + arr[i - 2]);
        }
    }
    return arr[num];
}

int main()
{
    fib.comp = -1;
    int i, n;
    vector<int> v;
    n = 11;

    cout << n << "th fibonacci number:\n\n";
    cout << "Brute-Force\t= " << fibonacciBruteForce(n - 1) << endl;
    cout << "Top-Down\t= " << fibonacciTopDown(n - 1) << endl;
    vecPrint(fib.vec);
    cout << "Bottom-Up\t= " << fibonacciBottomUp(n - 1) << endl;
    vecPrint(arr);

    return 0;
}