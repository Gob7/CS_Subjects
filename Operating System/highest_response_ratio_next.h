// Highest Response Ratio Next scheduling
#include <bits/stdc++.h>
using namespace std;

void hrrn_algorithm(int *at, int *bt, int *ct, float *res, int index, int job, int cur_time){
    if (index == job)
        return;

    int i, j = job;
    static int flag = 1;
    if (at[index] > cur_time) 
        cur_time = at[index];

    if (flag){
        j = ready_queue(at, index, job, cur_time);
        if (j == job)
            flag = 0;
    }
    for (i=index; i<j; i++)
        res[i] = (float) (cur_time - at[i] + bt[i]) / bt[i]; 
    descending_order(res, index, j, 2, at, bt);

    cur_time += bt[index];
    ct[index] = cur_time;
    hrrn_algorithm(at, bt, ct, res, index+1, job, cur_time);
}

void hrrn(int *at, int *bt, int *ct, int *tat, int *wt, int job){
    float res[job];
    hrrn_algorithm(at, bt, ct, res, 0, job, at[0]);

    for (int i=0; i<job; i++){
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
}