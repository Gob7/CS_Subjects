#include <bits/stdc++.h>
using namespace std;

/*
Interval Scheduling
Assumption: i. Every job must occur between start and finish
            ii. finish > start > 0
            iii. Goal -> maximize jobs
*/
int intervalScheduling(const int *start, const int *finish)
{
    int i, j = 0,
           newStart[job],
           newFinish[job],
           intervals[job] = {0};

    copy(start, start + job, newStart);
    copy(finish, finish + job, newFinish);
    ascending_order(newFinish, 0, job, 1, newStart);

    for (i = 1; i < job; i++)
        if (newStart[i] >= newFinish[intervals[j]])
            intervals[++j] = i;

    arrPrint(newStart, newFinish, "Start", "Finish", 0, job);
    cout << "\nMaximum Jobs\t= " << j + 1 << endl
         << "Job indexes\t: ";
    arrPrint(intervals, 0, j + 1);

    return j + 1;
}

/*
Weighted Interval Scheduling
Assumption: i. Every job must occur between start and finish
            ii. finish > start > 0
            iii. Goal -> maximize weight
*/
int weightedIntervalScheduling(const int *start, const int *finish, const int *weight)
{
    int i, l, m, h,
        j = 0,
        newStart[job],
        newFinish[job],
        newWeight[job],
        p[job + 1], // criticalPoint
        result[job + 1];

    copy(start, start + job, newStart);
    copy(finish, finish + job, newFinish);
    copy(weight, weight + job, newWeight);
    ascending_order(newFinish, 0, job, 2, newStart, newWeight);

    p[0] = 0;
    p[1] = 0;
    for (i = 2; i <= job; i++)
    {
        // binary search
        l = 1;
        h = i - 1;
        while (l <= h)
        {
            m = (l + h) / 2;
            if (newStart[i - 1] >= newFinish[m - 1])
                l = m + 1;
            else
                h = m - 1;
        }
        p[i] = h;
    }

    // bottom-up approach
    result[0] = 0;
    for (i = 1; i <= job; i++)
        result[i] = max(result[i - 1], newWeight[i - 1] + result[p[i]]);

    arrPrint(newStart, newFinish, newWeight, p, 0, job);
    cout << "\nMaximum Profit\t= " << result[job] << endl
         << "intermediate opt : ";
    arrPrint(result, 1, job);

    return result[job];
}