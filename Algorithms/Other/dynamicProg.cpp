#include <bits/stdc++.h>
using namespace std;

#include "../../Common/printVector.h"
#include "../../Common/sortingMultiple.h"
#include "../../Common/printArrayMatrix.h"
#include "../../Common/printTreeList.h"

vector<int> memoFib;
vector<int> tableFib;

#include "Fibonacci.h"
#include "HuffmanCoding.h"
#include "MatrixChainMultiply.h"
#include "LongestCommonSubsequence.h"

int main()
{
    int n = 6, result;
    char alphabet[n] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int frequency[n] =
        // {45, 13, 12, 16, 5, 9};
        {2, 2, 1, 3, 4, 1};
    string str1 = "longest", str2 = "stone", str;

    // cout << n << "th fibonacci number:\n\n";
    // cout << "Brute-Force\t= " << fibonacciBruteForce(n - 1) << endl;
    // cout << "Top-Down\t= " << fibonacciTopDown(n - 1) << endl;
    // vecPrint(memoFib);
    // cout << "Bottom-Up\t= " << fibonacciBottomUp(n - 1) << endl;
    // vecPrint(tableFib);

    // huffmanCoding(alphabet, frequency, n);
    str = longestCommonSubsequence(str1, str2);
    cout << "Longest Common Subsequence = " << str << endl;

    return 0;
}