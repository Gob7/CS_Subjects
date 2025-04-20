/*Shortest path in multi stage graph
Assumptions:
        i. #vertices = n; #edges = e (Directed graph)
        ii. matrix c, c[i][j] = edge cost of i to j (n*n matrix)
        iii. Number of stages = l
        iv. Stage 1: source (1 vertex) = c[0]
        v. Stage l: destination (1 vertex) = c[n-1]
        vi. cost function, cost(i, j) = cost of path from "vertex j" in "stage i" 
                                        to reach destination (stage l)

        vii. cost(i, j) = min{ c[j][k] + cost(i+1, k) }
*/
#include <bits/stdc++.h>
using namespace std;

int minCostMultiStage(int c[][nodes], int *nodeLevel, int levels, int cost[][nodes], int path[][nodes]){
    int stage, vertex, k, j1, j2, y, z;
    int *ptr;
    stage = levels - 1;
    j1 = nodes - nodeLevel[stage];

    for (; stage>0; stage--){
        j2 = j1;
        j1 -= nodeLevel[stage-1];
        vertex = j1;

        for (; vertex<j2; vertex++){
            k = j2;
            y = nodeLevel[stage];
            z = k + y;

            if (stage == levels - 1){
                cost[stage][vertex] = c[vertex][nodes-1];
                path[stage][vertex] = nodes-1;
            }
            else{
                int arr[y];
                fill(arr, arr+y, INT_MAX);
                // cout<<endl;

                for (; k<z; k++){
                    if (c[vertex][k] != INT_MAX){
                        // cout<<"j = "<<vertex+1<<", k = "<<k<<";\t"<<c[vertex][k]<<"+"<<cost[stage+1][k];
                        arr[k-j2] = c[vertex][k] + cost[stage+1][k];
                        // cout<<" = "<<arr[k-j2]<<endl;
                    }
                }
                z = *min_element(arr, arr+y);
                cost[stage][vertex] = z;
                ptr = find(arr, arr+y, z);
                path[stage][vertex] = j2 + (ptr-arr);
            }
            // cout<<"cost("<<stage<<", "<<vertex+1<<") = "<<cost[stage][vertex]<<endl;
            // cout<<"Path = "<<path[stage][vertex]+1<<endl<<endl;
        }
    }
    return cost[1][0];   
}