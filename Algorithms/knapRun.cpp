
#include <bits/stdc++.h>
#include "printing.h"
#include "../Operating System/sortingMultiple.h"
#include "knapsack.h"
#include "knapBinary.h"
using namespace std;

int main(){
    int n, i;
    // float m, result;
    int m, result;
    
    // cout<<"Number of items & capacity: ";
    // cin>>n>>m;
    // float weight[n], profit[n];
    // cout<<"Enter weights: ";
    // for (i=0; i<n; i++)
    //     cin>>weight[i];
    // cout<<"Enter profits: ";
    // for (i=0; i<n; i++)
    //     cin>>profit[i];

    n = 3;
    m = 6;
    // float weight[] = {2,3,5,7,1,4,1}, profit[] = {10,5,15,7,6,18,3}, fraction[n];
    int weight[] = {4,3,2}, profit[] = {5,2,1}, fraction[n];

    // result = fractionalKnapsack(weight, profit, n, m, fraction);
    result = binaryKnapsack(weight, profit, n, m, fraction);

    cout<<"\nWeight\t\t: ";
    arrPrint(weight, 0, n);
    cout<<"Fraction\t: ";
    arrPrint(fraction, 0, n);
    cout<<"Maximum Profit = "<<result<<endl;

    return 0;
}