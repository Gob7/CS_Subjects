
#include <bits/stdc++.h>
using namespace std;

#include "../printing.h"
#include "../../Operating System/sortingMultiple.h"
#include "BinaryKnapsack.h"
#include "FractionalKnapsack.h"

int main()
{
    int i, length, capacityInt;
    float capacityFloat;

    // weight capacity
    length = 3;
    capacityInt = 6;
    capacityFloat = 6.0;

    // int weightInt[length] = {2, 3, 5, 7, 1, 4, 1},
    //     profitInt[length] = {10, 5, 15, 7, 6, 18, 3};
    // float weightFloat[length] = {2.0, 3.0, 5.0, 7.0, 1.0, 4.0, 1.0},
    //       profitFloat[length] = {10.0, 5.0, 15.0, 7.0, 6.0, 18.0, 3.0};

    int weightInt[length] = {4, 3, 2},
        profitInt[length] = {5, 2, 1};
    float weightFloat[length] = {4, 3, 2},
          profitFloat[length] = {5, 2, 1};

    // cout << "Number of items & capacity: ";
    // cin >> length >> capacityFloat;
    // float weightFloat[length], profitFloat[length];
    // cout << "Enter weights: ";
    // for (i = 0; i < length; i++)
    //     cin >> weightFloat[i];
    // cout << "Enter profits: ";
    // for (i = 0; i < length; i++)
    //     cin >> profitFloat[i];

    cout << "\nBINARY KNAPSACK:" << endl;
    binaryKnapsack(weightInt, profitInt, length, capacityInt);
    cout << "\n\nFRACTIONAL KNAPSACK:";
    fractionalKnapsack(weightFloat, profitFloat, length, capacityFloat);

    return 0;
}