/*Job Sequencing Deadline
Assumption: i. Every job arrival time = 0
            ii. Every job burst time = 1
            iii. deadline > 0
            iv. profit > 0
            v. Goal -> maximize profit
*/
#include <bits/stdc++.h>
using namespace std;

int jsd(int *dl, int *pft, int job)
{
    int i, j, k, maxJob;
    maxJob = *max_element(dl, dl + job);
    int arr[maxJob] = {};

    k = 0;
    for (i = 0; i < job; i++)
    {
        if (k == maxJob)
            break;

        // Find the last free slot before the deadline
        j = dl[i] - 1;
        while (j > -1 && arr[j] != 0)
            j--;

        // If a free slot is found, assign the job to it
        // else, ignore the job
        if (j >= 0)
        {
            arr[j] = pft[i];
            k++;
        }
    }
    // for (i=0; i<maxJob; i++)
    //     cout<<arr[i]<<" ";
    return accumulate(arr, arr + maxJob, 0);
}