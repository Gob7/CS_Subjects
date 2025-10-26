/*
feature -> index: property -> 0: color, 1: level, 2: parent
color   -> -1: not visited, 0: visited not processed, 1: processed
level   -> distance from root
parent  -> parent of respective node in BFS tree,
           parent of root is -1
*/
#include <bits/stdc++.h>
using namespace std;

void runBFS(const int input[][nodes], int feature[3][nodes], int parent)
{
    queue<int> Q;
    Q.push(parent);

    while (!(Q.empty()))
    {
        parent = Q.front();
        Q.pop();
        for (int i = 0; i < nodes; i++)
        {
            if (i == parent)
                continue;
            if (input[parent][i] != INT_MAX && feature[0][i] == -1)
            {
                feature[0][i] = 0;
                feature[1][i] = feature[1][parent] + 1;
                feature[2][i] = parent;
                Q.push(i);
            }
        }
        feature[0][parent] = 1;
    }
}

int BreadthFirstSearch(const int input[][nodes], int feature[3][nodes], const int root = 0)
{
    int i, trees = 1;

    fill(feature[0], feature[0] + nodes, -1);
    feature[1][root] = 0;
    fill(feature[2], feature[2] + nodes, INT_MIN);
    feature[2][root] = -1;

    feature[0][root] = 0;
    runBFS(input, feature, root);

    for (i = 0; i < nodes; i++)
    {
        if (feature[0][i] == -1)
        {
            feature[0][i] = 0;
            feature[1][i] = 0;
            feature[2][i] = -1;
            runBFS(input, feature, i);
            trees++;
        }
    }

    return trees;
}