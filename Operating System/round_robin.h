/*Round Robin scheduling
Note: 
If time quantum of current running process (P_cur) finishes at time 't';
Let at time 't' a new process (P_new) comes [i.e. AT(P_new) = t];
Then in RQ, P_cur comes before P_new [i.e RQ = (..., P_cur, P_new)]
*/
#include <bits/stdc++.h>
using namespace std;

void rr_algorithm(int *at, int *AT, int *bt, int *BT, int *ct, int index, int job, int cur_time, int tq){
    ascending_order(at, index, job, 3, AT, bt, BT);
    if (at[index] > cur_time) 
        cur_time=at[index];
    int time;

    if (accumulate(bt, bt+job, 0) != 0){
        if (bt[index] < tq) 
            time = bt[index];
        else 
            time = tq;

        bt[index] -= time;
        cur_time += time;

        if (!bt[index]) 
            ct[index++] = cur_time;
        else 
            at[index] = cur_time;
        rr_algorithm(at, AT, bt, BT, ct, index, job, cur_time, tq);
    }
}
void rr(int *at, int *bt, int *ct, int *tat, int *wt, int job, int tq){
    int AT[job], BT[job], i;
    copy(at, at+job, AT);
    copy(bt, bt+job, BT);

    rr_algorithm(AT, at, BT, bt, ct, 0, job, at[0], tq);
    for (i=0; i<job; i++){
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
}