// First Come First Serve scheduling
#include <bits/stdc++.h>
using namespace std;

void fcfs(int *at, int *bt, int *ct, int *tat, int *wt, int job){
    for (int i=0; i<job; i++){
        if (i==0 || at[i]>ct[i-1])
            ct[i] = at[i] + bt[i];
        else 
            ct[i] = ct[i-1] + bt[i];

        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
}