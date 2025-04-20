// Longest Remaining Time First scheduling
#include <bits/stdc++.h>
using namespace std;

void lrtf_algorithm(int *at, int *bt, int *BT, int *ct, int index, int job, int cur_time){
    static int flag = 1;
    int i = job, time = -1, rqLength;
    if (at[index] > cur_time) 
        cur_time = at[index];
    
    if (flag){
        i = ready_queue(at, index, job, cur_time);
        if (i == job) 
            flag = 0;
    }
    rqLength = i - index - 1;
    descending_order(bt, index, i, 2, at, BT);

    if (accumulate (bt, bt+job, 0) != 0){
        i = index;
        
        if (i+1 == job)
            time = bt[index];
        else if (!rqLength){ 
            time = next_process_time(at, index, cur_time); 
            time = time<bt[index] ? time : bt[index];
        }
        else
            time = 1;

        bt[index] -= time;
        if (!bt[index]){
            ct[index] = cur_time + time;
            i++;
        }
        lrtf_algorithm(at, bt, BT, ct, i, job, cur_time+time);
    }
}

void lrtf(int *at, int *bt, int *ct, int *tat, int *wt, int job){
    int BT[job], i;
    copy(bt, bt+job, BT);
    lrtf_algorithm(at, BT, bt, ct, 0, job, at[0]);

    for(i=0; i<job; i++){
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
}