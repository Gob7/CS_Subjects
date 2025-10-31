// Priority Based Non Pre-emptive scheduling
#include <bits/stdc++.h>
using namespace std;

void pbnp(int *arrivalTime, int *burstTime, int *priority, int *completionTime, int index, int curTime)
{
    static int flag = 1;
    if (flag)
    {
        int i = readyQueue(arrivalTime, index, curTime);
        if (i == process)
            flag = 0;

        descending_order(priority, index, i, 2, arrivalTime, burstTime);
    }

    if (index < process)
    {
        curTime += burstTime[index];
        completionTime[index] = curTime;
        if (index + 1 < process && completionTime[index] < arrivalTime[index + 1])
            curTime = arrivalTime[index + 1];

        pbnp(arrivalTime, burstTime, priority, completionTime, index + 1, curTime);
    }
}

void priorityBased(const int *arrivalTime, const int *burstTime, const int *priority)
{
    int newArrivalTime[process],
        newBurstTime[process],
        newPriority[process],
        completionTime[process],
        turnAroundTime[process],
        waitingTime[process];

    copy(arrivalTime, arrivalTime + process, newArrivalTime);
    copy(burstTime, burstTime + process, newBurstTime);
    copy(priority, priority + process, newPriority);

    pbnp(newArrivalTime, newBurstTime, newPriority, completionTime, 0, arrivalTime[0]);
    calcOtherTimes(newArrivalTime, newBurstTime, completionTime, turnAroundTime, waitingTime);
    printPriority(newArrivalTime, newPriority);
    printSchedule(newArrivalTime, newBurstTime, completionTime, turnAroundTime, waitingTime);
}