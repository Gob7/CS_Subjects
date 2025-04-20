// Priority Based scheduling
#include <bits/stdc++.h>
using namespace std;

void pbp_algorithm(int *at, int *prio, int *bt, int *BT, int *ct, int index, int job, int cur_time){
    static int flag = 1;
    int i, time=-1;
    if (at[index] > cur_time) 
        cur_time=at[index];

    if (flag){
        i = ready_queue(at, index, job, cur_time);
        if (i == job) 
            flag=0; 

        descending_order(prio, index, i, 3, at, bt, BT);
    }
    
    if (accumulate (bt, bt+job, 0) != 0){
        i = index;
        if (flag) 
            time = next_process_time(at, index, cur_time); 
        if (!(flag) || time>=bt[index]){
            time = bt[index];
            ct[index] = cur_time + time;
            i++;
        }

        bt[index] -= time;
        pbp_algorithm(at, prio, bt, BT, ct, i, job, cur_time+time);
    }
}

void pbp(int *at, int *prio, int *bt, int *ct, int *tat, int *wt, int job){
    int i, BT[job];
    copy(bt, bt+job, BT);
    pbp_algorithm(at, prio, BT, bt, ct, 0, job, at[0]);
    
    for(i=0; i<job; i++){
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
}