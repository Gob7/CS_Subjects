// Priority Based Pre-emptive scheduling
#include <bits/stdc++.h>
using namespace std;

void pbp(int *arrivalTime,
         int *burstTime,
         int *priority,
         int *zeroBurstTime,
         int *completionTime,
         int index,
         int curTime)
{
    static int flag = 1;
    int i, time = -1;
    if (arrivalTime[index] > curTime)
        curTime = arrivalTime[index];

    if (flag)
    {
        i = readyQueue(arrivalTime, index, curTime);
        if (i == process)
            flag = 0;

        descending_order(priority, index, i, 3, arrivalTime, burstTime, zeroBurstTime);
    }

    if (accumulate(zeroBurstTime, zeroBurstTime + process, 0) != 0)
    {
        i = index;
        if (flag)
            time = nextProcessTime(arrivalTime, index, curTime);
        if (!(flag) || time >= zeroBurstTime[index])
        {
            time = zeroBurstTime[index];
            completionTime[index] = curTime + time;
            i++;
        }

        zeroBurstTime[index] -= time;
        pbp(arrivalTime, burstTime, priority, zeroBurstTime, completionTime, i, curTime + time);
    }
}

void priorityBasedPreemptive(const int *arrivalTime, const int *burstTime, const int *priority)
{
    int newArrivalTime[process],
        newBurstTime[process],
        zeroBurstTime[process],
        newPriority[process],
        completionTime[process],
        turnAroundTime[process],
        waitingTime[process];

    copy(arrivalTime, arrivalTime + process, newArrivalTime);
    copy(burstTime, burstTime + process, newBurstTime);
    copy(burstTime, burstTime + process, zeroBurstTime);
    copy(priority, priority + process, newPriority);

    pbp(newArrivalTime, newBurstTime, newPriority, zeroBurstTime, completionTime, 0, arrivalTime[0]);
    calcOtherTimes(newArrivalTime, newBurstTime, completionTime, turnAroundTime, waitingTime);
    printPriority(newArrivalTime, newPriority);
    printSchedule(newArrivalTime, newBurstTime, completionTime, turnAroundTime, waitingTime);
}