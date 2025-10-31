// Longest Remaining Time First scheduling
#include <bits/stdc++.h>
using namespace std;

void lrtf(int *arrivalTime, int *burstTime, int *zeroBurstTime, int *completionTime, int index, int curTime)
{
    static int flag = 1;
    int i = process, time = -1, readyQueueLength;
    if (arrivalTime[index] > curTime)
        curTime = arrivalTime[index];

    if (flag)
    {
        i = readyQueue(arrivalTime, index, curTime);
        if (i == process)
            flag = 0;
    }
    readyQueueLength = i - index - 1;
    descending_order(zeroBurstTime, index, i, 2, arrivalTime, burstTime);

    if (accumulate(zeroBurstTime, zeroBurstTime + process, 0) != 0)
    {
        i = index;

        if (i + 1 == process)
            time = zeroBurstTime[index];
        else if (!readyQueueLength)
        {
            time = nextProcessTime(arrivalTime, index, curTime);
            time = time < zeroBurstTime[index] ? time : zeroBurstTime[index];
        }
        else
            time = 1;

        zeroBurstTime[index] -= time;
        if (!zeroBurstTime[index])
        {
            completionTime[index] = curTime + time;
            i++;
        }
        lrtf(arrivalTime, burstTime, zeroBurstTime, completionTime, i, curTime + time);
    }
}

void longestRemainingTimeFirst(const int *arrivalTime, const int *burstTime)
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

    lrtf(newArrivalTime, newBurstTime, zeroBurstTime, completionTime, 0, newArrivalTime[0]);
    calcOtherTimes(newArrivalTime, newBurstTime, completionTime, turnAroundTime, waitingTime);
    printSchedule(newArrivalTime, newBurstTime, completionTime, turnAroundTime, waitingTime);
}