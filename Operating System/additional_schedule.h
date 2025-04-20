#include <bits/stdc++.h>
using namespace std;

int ready_queue(int *at, int index, int job, int cur_time){
    while (index<job && at[index]<=cur_time) 
        index++;
    return index;
}

int next_process_time(int *at, int index, int cur_time){
    while (at[index] <= cur_time) 
        index++;
    return at[index] - cur_time;
}