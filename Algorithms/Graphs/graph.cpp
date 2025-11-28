#include <bits/stdc++.h>
using namespace std;
#define nodes 4

#include "graphFunction.h"
#include "BFS.h"
#include "DFS.h"
#include "multiStageGraph.h"
#include "floydWarshell.h"

void makeDirectedGraph(int input[][nodes]);
int main()
{
    int input[nodes][nodes];
    initGraph(input);
    makeDirectedGraph(input);
    initUndirectedGraph(input);
    printGraph(input);

    /*
    int feature[2][nodes], trees;

    // BFS
    // feature -> index: property -> 0: level, 1: parent
    trees = BreadthFirstSearch(input, feature);
    printFeaturesBFS(feature, trees);

    // DFS
    // feature -> index: property -> 1: start, 2: finish
    trees = DepthFirstSearch(input, feature);
    printFeaturesDFS(feature, trees);
    */

    /*
    // All-Pair Shortest Path
    int output[nodes][nodes];
    allPairShortestPath(input, output);
    cout << "\nAll pair shortest path:";
    printGraph(output);
    */

    /*
    // Multi-Stage Graph
    int minCost, levels = 5;
    int cost[levels][nodes], path[levels][nodes];
    int nodeLevel[levels] = {1, 4, 3, 3, 1};

    initMultiStageGraph(cost, path, levels);
    minCost = minCostMultiStage(input, nodeLevel, levels, cost, path);
    cout << "\nMinimum Cost to reach destination = " << minCost;
    pathPrint(levels, path);
    */
    return 0;
}

void makeDirectedGraph(int input[][nodes])
{
    /*
    // 4 nodes
    input[0][1] = 8;
    input[0][3] = 1;

    input[1][2] = 1;

    input[2][0] = 4;

    input[3][1] = 2;
    input[3][2] = 9;
    */

    // 4 nodes
    input[0][1] = 3;
    input[0][2] = 8;

    input[1][2] = 4;
    input[1][3] = 11;

    input[2][3] = 7;

    input[3][0] = 4;

    /*
    // 8 nodes
    input[0][1] = 1;
    input[0][3] = 1;
    input[0][4] = 1;

    input[1][2] = 1;
    input[1][3] = 1;

    input[2][0] = 1;

    input[3][2] = 1;

    input[4][3] = 1;
    input[4][5] = 1;

    input[5][3] = 1;

    input[6][4] = 1;
    input[6][5] = 1;
    input[6][7] = 1;

    input[7][3] = 1;
    */
    /*
    // 12 nodes
    input[0][1] = 9;
    input[0][2] = 7;
    input[0][3] = 3;
    input[0][4] = 2;

    input[1][5] = 4;
    input[1][6] = 2;
    input[1][7] = 1;

    input[2][5] = 2;
    input[2][6] = 7;

    input[3][7] = 11;

    input[4][6] = 11;
    input[4][7] = 8;

    input[5][8] = 6;
    input[5][9] = 5;

    input[6][8] = 4;
    input[6][9] = 3;

    input[7][9] = 5;
    input[7][10] = 6;

    input[8][11] = 4;

    input[9][11] = 2;

    input[10][11] = 3;
    */
}