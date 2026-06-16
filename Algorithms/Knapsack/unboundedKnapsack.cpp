#include <bits/stdc++.h>
using namespace std;

#include "../../Common/printArrayMatrix.h"
#include "CoinChange.h"
#include "RodCut.h"
#include "SumOfSubsets.h"

int main()
{
    int k,
        cut[] = {1, 2, 3, 5, 6, 10}, // coin denomination
        price[] = {3, 7, 9, 17, 20, 41};
    int target = 6,
        length = sizeof(cut) / sizeof(int);

    cout << "\nCoins available\t: ";
    arrPrint(cut, 0, length);
    cout << "Target\t\t= " << target << endl;

    k = minimumCoins(cut, length, target);
    cout << "Min coins\t= " << k << endl;
    k = waysToCoins(cut, length, target);
    cout << "Number of ways\t= " << k << endl;

    arrPrint(cut, price, "Cut", "Price", 0, length);
    cout << "Available rod\t= " << target;
    k = rodCut(cut, price, length, target);
    cout << "Max profit\t= " << k << endl;

    k = sumOfSubsets(cut, length, target);
    cout << "\nReach " << target << "\t\t:= " << k << endl;

    return 0;
}