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

int jobSequencingDeadline(const int *deadline, const int *profit)
{
    int i, freeTime,
        curTime = 0,
        newDeadline[job],
        newProfit[job],
        maxDeadline = *max_element(deadline, deadline + job);
    int profits[maxDeadline] = {0};

    copy(deadline, deadline + job, newDeadline);
    copy(profit, profit + job, newProfit);
    descending_order(newProfit, 0, job, 1, newDeadline);

    for (i = 0; i < job; i++)
    {
        if (curTime == maxDeadline)
            break;

        // Find the last free slot before the deadline
        freeTime = newDeadline[i] - 1;
        while (freeTime > -1 && profits[freeTime] != 0)
            freeTime--;

        // If a free slot is found, assign the job to it
        // else, ignore the job
        if (freeTime >= 0)
        {
            profits[freeTime] = newProfit[i];
            curTime++;
        }
    }

    arrPrint(newDeadline, newProfit, "Dadlin", "Profit", 0, job);
    cout << "\nJob Sequence\t: ";
    for (i = 0; i < maxDeadline; i++)
        cout << profits[i] << ",\t";

    cout << "\nMaximum Profit\t= " << accumulate(profits, profits + maxDeadline, 0)
         << "\t(" << maxDeadline << " jobs)\n";
    return maxDeadline;
}