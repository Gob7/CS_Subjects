#include <bits/stdc++.h>
#define nodes 4
#include "graphFunction.h"
#include "multiStageGraph.h"
#include "floydWarshell.h"
using namespace std;

int main(){
    int levels, minCost, i, j;
    levels = 5;
    int input[nodes][nodes];
    int cost[levels][nodes], path[levels][nodes], allPair[nodes][nodes];
    initGraph(input);

    /*Special type of graph*/
    // input[0][1] = 9; input[0][2] = 7; input[0][3] = 3; input[0][4] = 2;
    // input[1][5] = 4; input[1][6] = 2; input[1][7] = 1; 
    // input[2][5] = 2; input[2][6] = 7; 
    // input[3][7] = 11; 
    // input[4][6] = 11; input[4][7] = 8; 
    // input[5][8] = 6; input[5][9] = 5;
    // input[6][8] = 4; input[6][9] = 3;
    // input[7][9] = 5; input[7][10] = 6;
    // input[8][11] = 4;
    // input[9][11] = 2;
    // input[10][11] = 3;

    // graphPrint(input);
    // int nodeLevel[] = {1, 4, 3, 3, 1};
    // initMultiStage(cost, path, levels);
    // minCost = minCostMultiStage(input, nodeLevel, levels, cost, path);
    // cout<<"\nMinimum Cost to reach destination = "<<minCost;
    // pathPrint(levels, path);



    input[0][1] = 8; input[0][3] = 1;
    input[1][2] = 1;
    input[2][0] = 4;
    input[3][1] = 2; input[3][2] = 9;

    // input[0][1] = 3; input[0][2] = 8;
    // input[1][2] = 4; input[1][3] = 11;
    // input[2][3] = 7;
    // input[3][0] = 4;

    allPairShortestPath(input, allPair);
    cout<<"\nAll pair shortest path:";
    graphPrint(allPair);


    return 0;
}