#include <bits/stdc++.h>
using namespace std;

#include "../../Common/printArrayMatrix.h"
#include "../../Common/sortingMultiple.h"
#include "BinaryKnapsack.h"
#include "FractionalKnapsack.h"

int main()
{
    int i, length, capacityInt, profitMax;
    float capacityFloat, maxProfit;

    // weight capacity
    capacityInt = 6;
    capacityFloat = 12.0;

    // int weightInt[] = {2, 3, 5, 7, 1, 4, 1},
    //     profitInt[] = {10, 5, 15, 7, 6, 18, 3};
    float weightFloat[] = {2.0, 3.0, 5.0, 7.0, 1.0, 4.0, 1.0},
          profitFloat[] = {10.0, 5.0, 15.0, 7.0, 6.0, 18.0, 3.0};

    int weightInt[] = {4, 3, 2},
        profitInt[] = {5, 2, 1};
    // float weightFloat[] = {4, 3, 2},
    //       profitFloat[] = {5, 2, 1};

    length = sizeof(weightInt) / sizeof(int);

    /*
    cout << "Number of items & capacity: ";
    cin >> length >> capacityFloat;
    float weightFloat[length], profitFloat[length];
    cout << "Enter weights: ";
    for (i = 0; i < length; i++)
        cin >> weightFloat[i];
    cout << "Enter profits: ";
    for (i = 0; i < length; i++)
        cin >> profitFloat[i];
    */

    cout << "\nBINARY KNAPSACK:" << endl;
    profitMax = binaryKnapsack(weightInt, profitInt, length, capacityInt);
    cout << "\n\nFRACTIONAL KNAPSACK:";
    maxProfit = fractionalKnapsack(weightFloat, profitFloat, length, capacityFloat);

    return 0;
}