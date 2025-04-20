// Shortest Job First scheduling
#include <bits/stdc++.h>
using namespace std;

void sjf(int *at, int *bt, int *ct, int *tat, int *wt, int job){
    int i, j, cur_time = at[0];

    for (i=0; i<job; i++){
        j=i;
        while (j<job && at[j] <= cur_time) 
            j++;
        ascending_order(bt, i, j, 1, at);

        ct[i] = bt[i];
        if (at[i] > cur_time) 
            ct[i] += at[i];
        else 
            ct[i] += cur_time;

        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        cur_time = ct[i];
    }
}