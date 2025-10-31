/*
feature -> index: property -> 0: level, 1: parent
level   -> distance from root
parent  -> parent in BFS tree, root's parent = -1
*/
#include <bits/stdc++.h>
using namespace std;

void runBFS(const int input[][nodes], int feature[2][nodes], int parent)
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
                feature[0][i] = feature[0][parent] + 1;
                feature[1][i] = parent;
                Q.push(i);
            }
        }
    }
}

int BreadthFirstSearch(const int input[][nodes], int feature[2][nodes], const int root = 0)
{
    int i, trees = 1;
    fill(feature[0], feature[0] + nodes, -1);

    feature[0][root] = 0;
    feature[1][root] = -1;
    runBFS(input, feature, root);

    for (i = 0; i < nodes; i++)
    {
        if (feature[0][i] == -1)
        {
            feature[0][i] = 0;
            feature[1][root] = -1;
            runBFS(input, feature, i);
            trees++;
        }
    }

    return trees;
}