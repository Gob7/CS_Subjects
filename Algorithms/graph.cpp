#include <bits/stdc++.h>
#define nodes 4
#include "graphFunction.h"
#include "multiStageGraph.h"
#include "floydWarshell.h"
using namespace std;

int main(){
    int levels, minCost, i, j;
    levels = 5;
    int c[nodes][nodes];
    int cost[levels][nodes], path[levels][nodes], allPair[nodes][nodes];
    initGraph(c);

    /*Special type of graph*/
    // c[0][1] = 9; c[0][2] = 7; c[0][3] = 3; c[0][4] = 2;
    // c[1][5] = 4; c[1][6] = 2; c[1][7] = 1; 
    // c[2][5] = 2; c[2][6] = 7; 
    // c[3][7] = 11; 
    // c[4][6] = 11; c[4][7] = 8; 
    // c[5][8] = 6; c[5][9] = 5;
    // c[6][8] = 4; c[6][9] = 3;
    // c[7][9] = 5; c[7][10] = 6;
    // c[8][11] = 4;
    // c[9][11] = 2;
    // c[10][11] = 3;

    // graphPrint(c);
    // int nodeLevel[] = {1, 4, 3, 3, 1};
    // initMultiStage(cost, path, levels);
    // minCost = minCostMultiStage(c, nodeLevel, levels, cost, path);
    // cout<<"\nMinimum Cost to reach destination = "<<minCost;
    // pathPrint(levels, path);



    // c[0][1] = 8; c[0][3] = 1;
    // c[1][2] = 1;
    // c[2][0] = 4;
    // c[3][1] = 2; c[3][2] = 9;

    c[0][1] = 3; c[0][2] = 8;
    c[1][2] = 4; c[1][3] = 11;
    c[2][3] = 7;
    c[3][0] = 4;

    allPairShortestPath(c, allPair);
    cout<<"\nAll pair shortest path:";
    graphPrint(allPair);


    return 0;
}