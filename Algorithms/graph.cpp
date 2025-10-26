#include <bits/stdc++.h>
using namespace std;
#define nodes 8

#include "graphFunction.h"
#include "BFS.h"
#include "DFS.h"
// #include "multiStageGraph.h"
// #include "floydWarshell.h"

int main()
{
    int input[nodes][nodes];
    initGraph(input);
    makeGraph(input);
    printGraph(input);

    /**/
    int feature[3][nodes], trees;

    // BFS
    // feature -> index: property -> 0: color, 1: level, 2: parent
    trees = BreadthFirstSearch(input, feature);
    printFeaturesBFS(feature, trees);

    // DFS
    //  feature -> index: property -> 0: parent, 1: start, 2: finish
    trees = DepthFirstSearch(input, feature);
    printFeaturesDFS(feature, trees);

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

    initMultiStage(cost, path, levels);
    minCost = minCostMultiStage(input, nodeLevel, levels, cost, path);
    cout << "\nMinimum Cost to reach destination = " << minCost;
    pathPrint(levels, path);
    */
    return 0;
}