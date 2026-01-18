#include <bits/stdc++.h>
using namespace std;
#define nodes 4

#include "graphFunction.h"
#include "BFS.h"
#include "DFS.h"
#include "multiStageGraph.h"
#include "shortestPath.h"
#include "minimumSpanningTree.h"

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

    // BFS (feature -> index: property -> 0: level, 1: parent)
    trees = BreadthFirstSearch(input, feature);
    printFeaturesBFS(feature, trees);

    // DFS (feature -> index: property -> 0: start, 1: finish)
    trees = DepthFirstSearch(input, feature);
    printFeaturesDFS(feature, trees);
    */
    /*
    int cycle, allPair[nodes][nodes], singleSource1[2][nodes], singleSource2[2][nodes];

    floydWarshellDistance(input, allPair);
    cout << "\nAll pair shortest path (Floyd-Warshell):";
    printGraph(allPair);

    dijkstraDistance(input, singleSource1);
    cout << "\nSingle source shortest path (Dijkstra):";
    printDistance(singleSource1);

    cycle = bellmanFordDistance(input, singleSource2);
    cout << "\nSingle source shortest path (Bellman-Ford):";
    if (cycle)
        cout << "\t\t(Negative weight cycle present in graph)";
    printDistance(singleSource2);
    */

    // Minimum Spanning Tree (undirected required)
    int mst1[nodes][nodes], mst2[nodes][nodes], mst3[nodes][nodes];

    primMST(input, mst1);
    cout << "\nMinimum spanning tree (Prim):";
    printGraph(mst1);

    kruskalMST(input, mst2);
    cout << "\nMinimum spanning tree (Kruskal):";
    printGraph(mst2);

    dijkstraMST(input, mst3);
    cout << "\nMinimum spanning tree (Dijkstra):";
    printGraph(mst3);

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
    // 4 nodes (-ve cycle)
    input[0][1] = 3;
    input[0][3] = 2;

    input[1][2] = 4;

    input[2][0] = -9;
    input[2][3] = 3;
    */
    /*
    // 5 nodes (directed)
    input[0][1] = 10;
    input[0][3] = 5;

    input[1][2] = 1;
    input[1][3] = 2;

    input[2][4] = 4;

    input[3][1] = 3;
    input[3][2] = 9;
    input[3][4] = 2;

    input[4][0] = 7;
    input[4][2] = 6;
    */
    /*
    // 5 nodes (-ve edge)
    input[0][1] = 6;
    input[0][3] = 7;

    input[1][2] = 5;
    input[1][3] = 8;
    input[1][4] = -4;

    input[2][1] = -2;

    input[3][2] = -3;
    input[3][4] = 9;

    input[4][0] = 2;
    input[4][2] = 7;
    */
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