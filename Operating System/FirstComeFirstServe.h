// First Come First Serve scheduling
#include <bits/stdc++.h>
using namespace std;

void firstComeFirstServe(const int *arrivalTime, const int *burstTime)
{
    int i,
        completionTime[process],
        turnAroundTime[process],
        waitingTime[process];

    for (i = 0; i < process; i++)
    {
        if (i == 0 || arrivalTime[i] > completionTime[i - 1])
            completionTime[i] = arrivalTime[i] + burstTime[i];
        else
            completionTime[i] = completionTime[i - 1] + burstTime[i];
    }

    calcOtherTimes(arrivalTime, burstTime, completionTime, turnAroundTime, waitingTime);
    printSchedule(arrivalTime, burstTime, completionTime, turnAroundTime, waitingTime);
}