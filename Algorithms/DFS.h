/*
feature -> index: property -> 0: parent, 1: start, 2: finish
parent  -> parent of respective node in BFS tree,
           parent of root is -1
start   -> start time of node
finish  -> finish time of node
*/
#include <bits/stdc++.h>
using namespace std;
int timeDFS = 0;

void runDFS(const int input[][nodes], int feature[3][nodes], int parent)
{
    feature[1][parent] = ++timeDFS;
    for (int i = 0; i < nodes; i++)
    {
        if (i == parent)
            continue;
        if (input[parent][i] != INT_MAX && feature[0][i] == INT_MIN)
        {
            feature[0][i] = parent;
            runDFS(input, feature, i);
        }
    }
    feature[2][parent] = ++timeDFS;
}

int DepthFirstSearch(const int input[][nodes], int feature[3][nodes], const int root = 0)
{

    int i, trees = 1;

    fill(feature[0], feature[0] + nodes, INT_MIN);

    feature[0][root] = -1;
    runDFS(input, feature, root);

    for (i = 0; i < nodes; i++)
    {
        if (feature[0][i] == INT_MIN)
        {
            feature[0][i] = -1;
            runDFS(input, feature, i);
            trees++;
        }
    }

    return trees;
}