// Highest Response Ratio Next scheduling
#include <bits/stdc++.h>
using namespace std;

void hrrn(int *arrivalTime, int *burstTime, int *completionTime, float *responseRatio, int index, int curTime)
{
    if (index == process)
        return;

    int i, j = process;
    static int flag = 1;
    if (arrivalTime[index] > curTime)
        curTime = arrivalTime[index];

    if (flag)
    {
        j = readyQueue(arrivalTime, index, curTime);
        if (j == process)
            flag = 0;
    }
    for (i = index; i < j; i++)
        responseRatio[i] = (float)(curTime - arrivalTime[i]) / burstTime[i];

    descending_order(responseRatio, index, j, 2, arrivalTime, burstTime);

    curTime += burstTime[index];
    completionTime[index] = curTime;
    hrrn(arrivalTime, burstTime, completionTime, responseRatio, index + 1, curTime);
}

void highestResponseRatioNext(const int *arrivalTime, const int *burstTime)
{
    int newArrivalTime[process],
        newBurstTime[process],
        completionTime[process],
        turnAroundTime[process],
        waitingTime[process];
    float responseRatio[process];

    copy(arrivalTime, arrivalTime + process, newArrivalTime);
    copy(burstTime, burstTime + process, newBurstTime);

    hrrn(newArrivalTime, newBurstTime, completionTime, responseRatio, 0, newArrivalTime[0]);
    calcOtherTimes(newArrivalTime, newBurstTime, completionTime, turnAroundTime, waitingTime);
    printSchedule(newArrivalTime, newBurstTime, completionTime, turnAroundTime, waitingTime);
}