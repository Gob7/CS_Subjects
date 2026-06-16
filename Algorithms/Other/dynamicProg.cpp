#include <bits/stdc++.h>
using namespace std;

#include "../../Common/printVector.h"
#include "../../Common/sortingMultiple.h"
#include "../../Common/printArrayMatrix.h"

vector<int> memo;
vector<int> table;

#include "Fibonacci.h"
#include "HuffmanCoding.h"
#include "MatrixChainMultiply.h"
#include "LongestCommonSubsequence.h"

int main()
{
    int n = 11;
    cout << n << "th fibonacci number:\n\n";
    cout << "Brute-Force\t= " << fibonacciBruteForce(n - 1) << endl;
    cout << "Top-Down\t= " << fibonacciTopDown(n - 1) << endl;
    vecPrint(memo);
    cout << "Bottom-Up\t= " << fibonacciBottomUp(n - 1) << endl;
    vecPrint(table);

    return 0;
}