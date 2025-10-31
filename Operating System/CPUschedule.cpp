/* CPU Scheduling
Assumption: i. Time in clock ticks (time >= 0); else algorithm fails
            ii. Process require only CPU burst time (no I/O BT)
            iii. Non-Preemptive approach: FCFS, SJF, HRRN, PB(NP), JSD
            iv. Preemptive approach: SRTF, LRTF, PB(P), RR
            v. Context switching time is negligible
            vi. Priority number directly proportional to priority (i.e. higher number means higher priority)
*/

#include <bits/stdc++.h>
using namespace std;
#define process 5

#include "sortingMultiple.h"
#include "AdditionalSchedule.h"
#include "FirstComeFirstServe.h"
#include "ShortestJobFirst.h"
#include "ShortestRemainingTimeFirst.h"
#include "LongestRemainingTimeFirst.h"
#include "HighestResponseRatioNext.h"
#include "RoundRobin.h"
#include "PriorityBased.h"
#include "PriorityBasedPreemptive.h"
#include "JobSequencingDeadline.h"

int main()
{

    int arrivalTime[process] = {0, 2, 4, 6, 8},
        burstTime[process] = {3, 6, 4, 5, 2},
        priority[process] = {3, 1, 2, 4},
        timeQuantum = 2;

    ascending_order(arrivalTime, 0, process, 2, burstTime, priority);

    // FCFS
    cout << "\n\nFIRST COME FIRST SERVE:";
    firstComeFirstServe(arrivalTime, burstTime);

    // SJF
    cout << "\n\nSHORTEST JOB FIRST:";
    shortestJobFirst(arrivalTime, burstTime);

    // SRTF
    cout << "\n\nSHORTEST REMAINING TIME FIRST:";
    shortestRemainingTimeFirst(arrivalTime, burstTime);

    // LRTF
    cout << "\n\nLONGEST REMAINING TIME FIRST:";
    longestRemainingTimeFirst(arrivalTime, burstTime);

    // HRRN
    cout << "\n\nHIGHEST RESPONSE RATIO NEXT:";
    highestResponseRatioNext(arrivalTime, burstTime);

    // RR
    cout << "\n\nROUND ROBIN:";
    roundRobin(arrivalTime, burstTime, timeQuantum);

    // PB(NP)
    cout << "\n\nPRIORITY BASED:";
    priorityBased(arrivalTime, burstTime, priority);

    // PB(P)
    cout << "\n\nPRIORITY BASED (PRE-EMPTIVE):";
    priorityBasedPreemptive(arrivalTime, burstTime, priority);

    /*
    int deadline[process] = {7, 2, 5, 3, 4, 5, 2, 7, 3},
        profit[process] = {15, 20, 30, 18, 18, 10, 23, 16, 25};

    descending_order(profit, 0, process, 1, deadline);

    // JSD
    cout << "\n\nJOB SEQUENCING DEADLINE:";
    jobSequencingDeadline(deadline, profit);
    */
    return 0;
}