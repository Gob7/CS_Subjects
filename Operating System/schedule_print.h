#include <bits/stdc++.h>
using namespace std;

void s_print(int *at, int *bt, int *ct, int *tat, int *wt, int n){
    int i;
    float avg_tat = (float) accumulate(tat, tat+n, 0)/n;
    float avg_wt = (float) accumulate(wt, wt+n, 0)/n;
    int schedule_len = *max_element(ct, ct+n) - *min_element(at, at+n);
    int idle = schedule_len - accumulate(bt, bt+n, 0);

    cout<<"\nAverage turn around time\t= "<<avg_tat<<endl;
    cout<<"Average waiting time\t\t= "<<avg_wt<<endl;
    cout<<"Schedule length\t\t\t= "<<schedule_len<<endl;
    cout<<"CPU idle for\t\t\t= "<<idle<<endl;

    cout<<"\nAT\tBT\tCT\tTAT\tWT\n";
    for(i=0; i<35; i++)
        cout<<"-";
    cout<<endl;
    for(i=0; i<n; i++)
        cout<<at[i]<<"\t"<<bt[i]<<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<<endl;
    // for(i=0; i<35; i++)
    //     cout<<"-";
    cout<<endl;
    // cout<<"Total =\t\t"<<accumulate(tat, tat+n, 0)<<"\t"<<accumulate(wt, wt+n, 0)<<endl;
}