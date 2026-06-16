#include <bits/stdc++.h>
using namespace std;
#define job 9

#include "../../Common/printArrayMatrix.h"
#include "../../Common/sortingMultiple.h"
#include "../SearchSort/HeapSort.h"
#include "JobScheduling.h"
#include "IntervalScheduling.h"
#include "LectureScheduling.h"

int main()
{

    int k,
        // start[job] = {6, 0, 4, 2, 3, 3, 1, 4, 2},
        // finish[job] = {7, 2, 5, 3, 4, 6, 2, 7, 3}, //deadline
        // start[job] = {1, 2, 4, 1, 5, 8, 9, 11, 13},
        // finish[job] = {3, 5, 7, 8, 9, 10, 11, 14, 16}, //deadline
        // profit[job] = {15, 20, 30, 18, 18, 10, 23, 16, 25};
        start[job] = {2, 3, 4, 7, 8, 9, 9, 11, 12},
        finish[job] = {5, 4, 7, 10, 9, 11, 13, 12, 14}, // deadline
        profit[job] = {11, 7, 9, 18, 3, 17, 54, 20, 22};

    // JSD
    cout << "\nJOB SEQUENCING DEADLINE:";
    k = jobSequencingDeadline(finish, profit);

    // Activity Selection
    cout << "\n\nINTERVAL SCHEDULING:";
    k = intervalScheduling(start, finish);

    // LS
    cout << "\n\nLECTURE SCHEDULING:";
    k = lectureScheduling(start, finish);

    // Weighted Activity Selection
    cout << "\n\nWEIGHTED INTERVAL SCHEDULING:";
    k = weightedIntervalScheduling(start, finish, profit);

    return 0;
}