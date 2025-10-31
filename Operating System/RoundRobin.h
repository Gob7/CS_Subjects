/*
Round Robin scheduling
Note:
    If time quantum of current running process (P_cur) finishes at time 't';
    Let at time 't' a new process (P_new) comes [i.e. AT(P_new) = t];
    Then in RQ, P_cur comes before P_new [i.e RQ = (..., P_cur, P_new)]
*/
#include <bits/stdc++.h>
using namespace std;

void rr(int *arrivalTime,
        int *zeroArrivalTime,
        int *burstTime,
        int *zeroBurstTime,
        int *completionTime,
        int index,
        int curTime,
        const int timeQuantum)
{
    ascending_order(zeroArrivalTime, index, process, 3, arrivalTime, zeroBurstTime, burstTime);
    if (zeroArrivalTime[index] > curTime)
        curTime = zeroArrivalTime[index];
    int time;

    if (accumulate(zeroBurstTime, zeroBurstTime + process, 0) != 0)
    {
        if (zeroBurstTime[index] < timeQuantum)
            time = zeroBurstTime[index];
        else
            time = timeQuantum;

        zeroBurstTime[index] -= time;
        curTime += time;

        if (!zeroBurstTime[index])
            completionTime[index++] = curTime;
        else
            zeroArrivalTime[index] = curTime;

        rr(arrivalTime, zeroArrivalTime, burstTime, zeroBurstTime, completionTime, index, curTime, timeQuantum);
    }
}

void roundRobin(const int *arrivalTime, const int *burstTime, const int timeQuantum)
{
    int newArrivalTime[process],
        zeroArrivalTime[process],
        newBurstTime[process],
        zeroBurstTime[process],
        completionTime[process],
        turnAroundTime[process],
        waitingTime[process];

    copy(arrivalTime, arrivalTime + process, newArrivalTime);
    copy(arrivalTime, arrivalTime + process, zeroArrivalTime);
    copy(burstTime, burstTime + process, newBurstTime);
    copy(burstTime, burstTime + process, zeroBurstTime);

    rr(newArrivalTime, zeroArrivalTime, newBurstTime, zeroBurstTime, completionTime, 0, arrivalTime[0], timeQuantum);
    calcOtherTimes(newArrivalTime, newBurstTime, completionTime, turnAroundTime, waitingTime);
    cout << "\nTime Quantum\t\t\t= " << timeQuantum;
    printSchedule(newArrivalTime, newBurstTime, completionTime, turnAroundTime, waitingTime);
}