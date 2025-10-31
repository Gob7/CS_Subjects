// Shortest Job First scheduling
#include <bits/stdc++.h>
using namespace std;

void shortestJobFirst(const int *arrivalTime, const int *burstTime)
{
    int i, j,
        curTime = arrivalTime[0],
        newArrivalTime[process],
        newBurstTime[process],
        completionTime[process],
        turnAroundTime[process],
        waitingTime[process];

    copy(arrivalTime, arrivalTime + process, newArrivalTime);
    copy(burstTime, burstTime + process, newBurstTime);

    for (i = 0; i < process; i++)
    {
        j = i;
        while (j < process && newArrivalTime[j] <= curTime)
            j++;
        ascending_order(newBurstTime, i, j, 1, newArrivalTime);

        completionTime[i] = newBurstTime[i];
        if (newArrivalTime[i] > curTime)
            completionTime[i] += newArrivalTime[i];
        else
            completionTime[i] += curTime;

        curTime = completionTime[i];
    }

    calcOtherTimes(newArrivalTime, newBurstTime, completionTime, turnAroundTime, waitingTime);
    printSchedule(newArrivalTime, newBurstTime, completionTime, turnAroundTime, waitingTime);
}