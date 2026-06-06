/*
Interval Scheduling
Assumption: i. Every lecture must occur between start and finish
            ii. finish > start > 0
            iii. Goal -> minimize classrooms
*/
#include <bits/stdc++.h>
using namespace std;

int lectureScheduling(const int *start, const int *finish)
{
    int i, j = 0,
           newStart[job],
           newFinish[job],
           classroom[job];

    copy(start, start + job, newStart);
    copy(finish, finish + job, newFinish);
    ascending_order(newStart, 0, job, 1, newFinish);

    classroom[j++] = newFinish[0];
    for (i = 1; i < job; i++)
    {
        if (newStart[i] >= classroom[0])
            classroom[0] = newFinish[i];
        else
            classroom[j++] = newFinish[i];
        minHeapify(classroom, 0, j, 0);
    }

    arrPrint(newStart, newFinish, "Start", "Finish", 0, job);
    cout << "\nMin Classrooms\t= " << j << endl
         << "Class finish at\t: ";
    arrPrint(classroom, 0, j);

    return j;
}