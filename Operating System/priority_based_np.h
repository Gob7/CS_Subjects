// Priority Based scheduling
#include <bits/stdc++.h>
using namespace std;

void pbnp_algorithm(int *at, int *prio, int *bt, int *ct, int index, int job, int cur_time){
    static int flag = 1;
    if (flag){
        int i = ready_queue(at, index, job, cur_time);
        if (i == job) 
            flag=0;
            
        descending_order(prio, index, i, 2, at, bt);
    }

    if (index < job){
        cur_time += bt[index];
        ct[index] = cur_time;
        if (index+1 < job && ct[index] < at[index+1])
            cur_time = at[index+1];

        pbnp_algorithm(at, prio, bt, ct, index+1, job, cur_time);
    }
}

void pbnp(int *at, int *prio, int *bt, int *ct, int *tat, int *wt, int job){
    pbnp_algorithm(at, prio, bt, ct, 0, job, at[0]);

    for (int i=0; i<job; i++){
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
}