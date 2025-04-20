/* CPU Scheduling
Assumption:  i. Time in clock ticks (time >= 0); else algorithm fails
            ii. Process require only CPU burst time (no I/O BT)
            iii. Non-Preemptive approach: FCFS, SJF, HRRN, PB(NP), JSD
            iv. Preemptive approach: SRTF, LRTF, PB(P), RR
            v. Context switching time is negligible
            vi. Priority number directly proportional to priority (i.e. higher number means higher priority)
            vii. Run one at a time; else wrong results
*/

#include <bits/stdc++.h>
#include "sortingMultiple.h"
#include "schedule_print.h"
#include "additional_schedule.h"
#include "first_come_first_serve.h"
#include "shortest_job_first.h"
#include "shortest_remaining_time_first.h"
#include "longest_remaining_time_first.h"
#include "highest_response_ratio_next.h"
#include "priority_based_np.h"
#include "priority_based_p.h"
#include "round_robin.h"
#include "job_sequencing_deadline.h"
using namespace std;

int main(){
    int i, n = 5;
    int at[] = {0,2,4,6,8}, bt[] = {3,6,4,5,2};
    int ct[n], tat[n], wt[n];
    ascending_order(at, 0, n, 1, bt);

    // fcfs(at, bt, ct, tat, wt, n);
    // cout<<"\n\nFCFS:";
    // sjf(at, bt, ct, tat, wt, n);
    // cout<<"\n\nSJF:";
    // srtf(at, bt, ct, tat, wt, n);
    // cout<<"\n\nSRTF:";
    // lrtf(at, bt, ct, tat, wt, n);
    // cout<<"\n\nLRTF:";
    hrrn(at, bt, ct, tat, wt, n);
    cout<<"\n\nHRRN:";

    // int tq = 2;
    // rr(at, bt, ct, tat, wt, n, tq);
    // cout<<"\n\nRR:";

    // int prio[] = {3, 1, 2, 4};
    // ascending_order(at, 0, n, 2, bt, prio);
    // pbnp(at, prio, bt, ct, tat, wt, n);
    // cout<<"\n\nPB(NP):";
    // pbp(at, prio, bt, ct, tat, wt, n);
    // cout<<"\n\nPB(P):";
    
    // int dl[] = {7,2,5,3,4,5,2,7,3}, pft[] = {15,20,30,18,18,10,23,16,25};     /* dl: deadline; pft: profit */
    // descending_order(pft, 0, n, 1, dl);
    // int ans = jsd(dl, pft, n);
    // cout<<"\n\nJSD:";
    // cout<<"\nMaximum profit = "<<ans;

    s_print(at, bt, ct, tat, wt, n);
    return 0;
}