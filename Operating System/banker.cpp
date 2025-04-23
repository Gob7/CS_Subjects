#include <bits/stdc++.h>
using namespace std;

int safetyAlgorithm(int n, int m, int *allocate, int *need, int *available)
{
    int satisfy[n] = {0}, prev, next, i, j, flag;
    vector<int> safeSequence;
    prev = accumulate(satisfy, satisfy + n, 0);

    while (1)
    {
        for (i = 0; i < n; i++)
        {
            if (satisfy[i] == 1)
                continue;
            flag = 1;
            for (j = 0; j < m; j++)
            {
                if (*(need + i * m + j) > available[j])
                    flag = 0;
            }
            if (flag)
            {
                satisfy[i] = 1;
                safeSequence.push_back(i);
                for (j = 0; j < m; j++)
                {
                    available[j] += *(allocate + i * m + j);
                    *(allocate + i * m + j) = 0;
                    *(need + i * m + j) = 0;
                }
            }
        }
        next = accumulate(satisfy, satisfy + n, 0);
        if (prev == next)
            break;
        prev = next;
    }

    if (prev == n)
    {
        cout << "\nSafe sequence";
        for (int i = 0; i < n; i++)
            cout << " -> P" << safeSequence[i];
        return 1;
    }
    return 0;
}

int main()
{
    int n, m, i, j, k, error = 0, temp, safe;

    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter number of resources: ";
    cin >> m;

    if (n < 0 || m < 0)
    {
        cout << "\nWrong input!!!" << endl;
        exit(0);
    }

    int maximum[n][m], allocate[n][m], need[n][m], total[m], available[m], newAllocate[n][m], newNeed[n][m], newAvailable[m];

    cout << "\nEnter 'maximum' matrix:" << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> maximum[i][j];
        }
    }

    cout << "\nEnter 'allocation' matrix:" << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> allocate[i][j];
            need[i][j] = maximum[i][j] - allocate[i][j];
            if (need[i][j] < 0 || maximum[i][j] < 0 || allocate[i][j] < 0)
                error = 1;
        }
    }

    cout << "\nEnter 'total' matrix:" << endl;
    for (j = 0; j < m; j++)
    {
        cin >> total[j];
        temp = 0;
        for (i = 0; i < n; i++)
            temp += allocate[i][j];

        available[j] = total[j] - temp;
        if (total[j] < 0 || available[j] < 0)
            error = 1;
    }

    if (error)
    {
        cout << "\nWrong input!!!" << endl;
        exit(0);
    }

    copy(available, available + m, newAvailable);
    for (k = 0; k < n; k++)
    {
        copy(allocate[k], allocate[k] + m, newAllocate[k]);
        copy(need[k], need[k] + m, newNeed[k]);
    }

    safe = safetyAlgorithm(n, m, newAllocate[0], newNeed[0], newAvailable);
    if (!safe)
    {
        cout << "\nNo safe sequence!!!" << endl;
        exit(0);
    }

    cout << "\nPress 0 to quit: ";
    cin >> temp;
    if (!temp)
        exit(0);

    int request[n][m];
    cout << "\nEnter 'request' matrix:" << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> request[i][j];
            if (need[i][j] < request[i][j] || available[j] < request[i][j] || request[i][j] < 0)
                error = 1;
        }
    }

    if (error)
    {
        cout << "\nWrong input!!!" << endl;
        exit(0);
    }

    for (i = 0; i < n; i++)
    {
        copy(available, available + m, newAvailable);
        for (k = 0; k < n; k++)
        {
            copy(allocate[k], allocate[k] + m, newAllocate[k]);
            copy(need[k], need[k] + m, newNeed[k]);
        }
        for (j = 0; j < m; j++)
        {
            newAvailable[j] -= request[i][j];
            newNeed[i][j] -= request[i][j];
            newAllocate[i][j] += request[i][j];
        }
        cout << "\nRequest " << i << " is ";
        safe = safetyAlgorithm(n, m, newAllocate[0], newNeed[0], newAvailable);
        safe ? cout << "\tgranted.\n" : cout << "denied.\n";
    }

    return 0;
}