#include <bits/stdc++.h>
using namespace std;

// Fractional Knapsack (Greedy Approach)
float fractionalKnapsack(float *weight, float *profit, int length, float capacity, float *fraction){
    int i;
    float maxPro = 0;

    if (accumulate(weight, weight+length, 0) <= capacity){
        maxPro = accumulate(profit, profit+length, 0);
        fill(fraction, fraction+length, 1);
    }
    else{    
        float ratio[length];
        for (i=0; i<length; i++)
            ratio[i] = profit[i]/weight[i];
        
        descending_order(ratio, 0, length, 2, weight, profit);
        i = 0;
        while (capacity > 0){
            fraction[i] = capacity/weight[i]>1 ? 1 : capacity/weight[i];
            capacity -= fraction[i]*weight[i];
            maxPro += fraction[i]*profit[i];
            i++;
        }
        fill(fraction+i, fraction+length, 0);
    }
    return maxPro;
}

// Wannabe Binary Knapsack
float wannabeBK(float *weight, float *profit, int length, float capacity, float *fraction){
    int i;

    if (accumulate(weight, weight+length, 0) <= capacity){
        fill(fraction, fraction+length, 1);
        return accumulate(profit, profit+length, 0);
    }
   
    float m1, m2, m3, m = capacity;
    float ratio[length], f1[length], f2[length];
    m1 = m2 = m3 = 0;

    // Greedy ratio
    for (i=0; i<length; i++)
        ratio[i] = profit[i]/weight[i];
    descending_order(ratio, 0, length, 2, weight, profit);
    i = 0;
    while (capacity>0 && i<length){
        f1[i] = capacity < weight[i] ? 0 : 1;
        if (f1[i]){
            capacity -= weight[i];
            m1 += profit[i];
        }
        i++;
    }
    fill(f1+i, f1+length, 0);

    // Greedy weight
    ascending_order(weight, 0, length, 1, profit);
    capacity = m;
    i = 0;
    while (capacity>0 && i<length){
        f2[i] = capacity < weight[i] ? 0 : 1;
        if (f2[i]){
            capacity -= weight[i];
            m2 += profit[i];
        }
        i++;
    }
    fill(f2+i, f2+length, 0);

    // Greedy profit
    descending_order(profit, 0, length, 1, weight);
    capacity = m;
    i = 0;
    while (capacity>0 && i<length){
        fraction[i] = capacity < weight[i] ? 0 : 1;
        if (fraction[i]){
            capacity -= weight[i];
            m3 += profit[i];
        }
        i++;
    }
    fill(fraction+i, fraction+length, 0);
    
    if (m1>m2 && m1>m3){
        descending_order(ratio, 0, length, 2, weight, profit);
        copy(f1, f1+length, fraction);
        return m1;
    }
    if (m2>m3){
        ascending_order(weight, 0, length, 1, profit);
        copy(f2, f2+length, fraction);
        return m2;
    }
        return m3;
}