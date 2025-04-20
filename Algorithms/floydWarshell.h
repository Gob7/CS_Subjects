#include <bits/stdc++.h>
using namespace std;

void allPairShortestPath(int c[][nodes], int allPair[][nodes]){
    int i, j, k, d[nodes][nodes];
    copyGraph(c, d);
    
    for (k=0; k<nodes; k++){
        for (i=0; i<nodes; i++){
            for (j=0; j<nodes; j++){
                if (d[i][k]==INT_MAX || d[k][j]==INT_MAX)
                    allPair[i][j] = d[i][j];
                else
                    allPair[i][j] = min(d[i][j], d[i][k]+d[k][j]);
            }
        }
        // graphPrint(d);
        copyGraph(allPair, d);
    }
}