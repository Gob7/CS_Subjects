// Shortest Remaining Time First scheduling
#include <bits/stdc++.h>
using namespace std;

void srtf(int *arrivalTime, int *burstTime, int *zeroBurstTime, int *completionTime, int index, int curTime)
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
        ascending_order(zeroBurstTime, index, i, 2, arrivalTime, burstTime);
    }

    if (accumulate(zeroBurstTime, zeroBurstTime + process, 0) != 0)
    {
        i = index;
        if (flag)
            time = nextProcessTime(arrivalTime, index, curTime);

        if (!flag || time >= zeroBurstTime[index])
        {
            time = zeroBurstTime[index];
            completionTime[index] = curTime + time;
            i++;
        }

        zeroBurstTime[index] -= time;
        srtf(arrivalTime, burstTime, zeroBurstTime, completionTime, i, curTime + time);
    }
}

void shortestRemainingTimeFirst(const int *arrivalTime, const int *burstTime)
{
    int newArrivalTime[process],
        newBurstTime[process],
        zeroBurstTime[process],
        completionTime[process],
        turnAroundTime[process],
        waitingTime[process];

    copy(arrivalTime, arrivalTime + process, newArrivalTime);
    copy(burstTime, burstTime + process, newBurstTime);
    copy(burstTime, burstTime + process, zeroBurstTime);

    srtf(newArrivalTime, newBurstTime, zeroBurstTime, completionTime, 0, newArrivalTime[0]);
    calcOtherTimes(newArrivalTime, newBurstTime, completionTime, turnAroundTime, waitingTime);
    printSchedule(newArrivalTime, newBurstTime, completionTime, turnAroundTime, waitingTime);
}