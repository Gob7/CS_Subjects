#include <bits/stdc++.h>
using namespace std;

int readyQueue(const int *arrivalTime, int index, const int curTime)
{
    while (index < process && arrivalTime[index] <= curTime)
        index++;
    return index;
}

int nextProcessTime(const int *arrivalTime, int index, const int curTime)
{
    while (arrivalTime[index] <= curTime)
        index++;
    return arrivalTime[index] - curTime;
}

void calcOtherTimes(const int *arrivalTime,
                    const int *burstTime,
                    const int *completionTime,
                    int *turnAroundTime,
                    int *waitingTime)
{
    for (int i = 0; i < process; i++)
    {
        turnAroundTime[i] = completionTime[i] - arrivalTime[i];
        waitingTime[i] = turnAroundTime[i] - burstTime[i];
    }
}

void printSchedule(const int *arrivalTime,
                   const int *burstTime,
                   const int *completionTime,
                   const int *turnAroundTime,
                   const int *waitingTime)
{
    int i,
        totalTurnAroundTime = accumulate(turnAroundTime, turnAroundTime + process, 0),
        totalWaitingTime = accumulate(waitingTime, waitingTime + process, 0),
        totalBurstTime = accumulate(burstTime, burstTime + process, 0),
        scheduleLength = *max_element(completionTime, completionTime + process) -
                         *min_element(arrivalTime, arrivalTime + process);

    cout << "\nAverage turn around time\t= " << (float)totalTurnAroundTime / process << endl;
    cout << "Average waiting time\t\t= " << (float)totalWaitingTime / process << endl;
    cout << "Schedule length\t\t\t= " << scheduleLength << endl;
    cout << "CPU idle for\t\t\t= " << scheduleLength - totalBurstTime << endl;

    // top
    cout << "\nAT\tBT\tCT\tTAT\tWT\n";
    for (i = 0; i < 35; i++)
        cout << "-";
    cout << endl;

    // middle
    for (i = 0; i < process; i++)
        cout << arrivalTime[i] << "\t"
             << burstTime[i] << "\t"
             << completionTime[i] << "\t"
             << turnAroundTime[i] << "\t"
             << waitingTime[i] << endl;

    // bottom
    for (i = 0; i < 35; i++)
        cout << "-";
    cout << endl;
    cout << "Total =\t\t\t" << totalTurnAroundTime << "\t" << totalWaitingTime << endl;
}

void printPriority(const int *arrivalTime, const int *priority)
{
    cout << "\nAT\tPriority\n";
    for (int i = 0; i < process; i++)
        cout << arrivalTime[i] << "\t" << priority[i] << endl;
}

void printDeadlineProfit(const int *deadline, const int *profit)
{
    cout << "\nDeadline\tProfit\n";
    for (int i = 0; i < process; i++)
        cout << deadline[i] << "\t\t" << profit[i] << endl;
}