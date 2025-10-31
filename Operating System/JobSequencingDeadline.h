/*
Job Sequencing Deadline
Assumption: i. Every job arrival time = 0
            ii. Every job burst time = 1
            iii. deadline > 0
            iv. profit > 0
            v. Goal -> maximize profit
*/
#include <bits/stdc++.h>
using namespace std;

void jobSequencingDeadline(const int *deadline, const int *profit)
{
    int i, freeTime,
        curTime = 0,
        maxDeadline = *max_element(deadline, deadline + process);
    int processes[maxDeadline] = {0};

    for (i = 0; i < process; i++)
    {
        if (curTime == maxDeadline)
            break;

        // Find the last free slot before the deadline
        freeTime = deadline[i] - 1;
        while (freeTime > -1 && processes[freeTime] != 0)
            freeTime--;

        // If a free slot is found, assign the job to it
        // else, ignore the job
        if (freeTime >= 0)
        {
            processes[freeTime] = profit[i];
            curTime++;
        }
    }

    printDeadlineProfit(deadline, profit);
    cout << "\nJob Sequence\t: ";
    for (i = 0; i < maxDeadline; i++)
        cout << processes[i] << ",\t";

    cout << "\nMaximum Profit\t= " << accumulate(processes, processes + maxDeadline, 0) << endl;
}