/*
feature -> index: property -> 0: start, 1: finish
start   -> start time of node
finish  -> finish time of node
(feature[2] -> parent)
*/
#include <bits/stdc++.h>
using namespace std;
int curTime = 0;

void runDFS(const int input[][nodes], int feature[2][nodes], int parent)
{
    feature[0][parent] = ++curTime;

    for (int i = 0; i < nodes; i++)
    {
        if (i == parent)
            continue;
        if (input[parent][i] != INT_MAX && feature[0][i] == 0)
        {
            // feature[2][i] = parent;
            runDFS(input, feature, i);
        }
    }

    feature[1][parent] = ++curTime;
}

int DepthFirstSearch(const int input[][nodes], int feature[2][nodes], const int root = 0)
{

    int i, trees = 1;
    fill(feature[0], feature[0] + nodes, 0);

    // feature[2][root] = -1;
    runDFS(input, feature, root);

    for (i = 0; i < nodes; i++)
    {
        if (feature[0][i] == INT_MIN)
        {
            // feature[2][i] = -1;
            runDFS(input, feature, i);
            trees++;
        }
    }

    return trees;
}