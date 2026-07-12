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
    unsigned int result, n = 6;
    char alphabet[n] = {'A', 'B', 'C', 'D', 'E', 'F'};
    unsigned int frequency[n] =
        {45, 13, 12, 16, 5, 9};
    // {2, 2, 1, 3, 4, 1};
    string str1 = "longest", str2 = "stone", str;
    unsigned int dimension[n + 1] =
        {30, 35, 15, 5, 10, 20, 25};
    // {10, 100, 5, 50};
    // {2, 1, 3, 4, 5};

    cout << n << "th fibonacci number:\n";
    cout << "Brute-Force\t= " << fibonacciBruteForce(n - 1) << endl;
    cout << "Top-Down\t= " << fibonacciTopDown(n - 1) << endl;
    vecPrint(memoFib);
    cout << "Bottom-Up\t= " << fibonacciBottomUp(n - 1) << endl;
    vecPrint(tableFib);

    result = huffmanCoding(alphabet, frequency, n);
    cout << "Total\t=  " << result << endl;
    str = longestCommonSubsequence(str1, str2);
    cout << "Longest Common Subsequence = '" << str << "'\t(length: " << str.size() << ")" << endl;
    result = matrixChainMultiply(dimension, n);
    cout << "\nOptimal Multiplications = " << result << endl;

    return 0;
}